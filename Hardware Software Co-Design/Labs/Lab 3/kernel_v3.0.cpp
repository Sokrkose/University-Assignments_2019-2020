#include <ap_int.h>
#include <stdio.h>
#include <string.h>
#include "matrixMultiplication.h"

#define BUFFER_SIZE 64
#define DATAWIDTH 512
#define VECTOR_SIZE (DATAWIDTH / 32) // vector size is 16 (512/32 = 16)
typedef ap_uint<DATAWIDTH> uint512_dt;

//TRIPCOUNT identifier
const unsigned int c_chunk_sz = BUFFER_SIZE;
const unsigned int c_size     = VECTOR_SIZE;

/*
    Vector Addition Kernel Implementation using uint512_dt datatype
    Arguments:
        in1   (input)     --> Input Vector1
        in2   (input)     --> Input Vector2
        out   (output)    --> Output Vector
        size  (input)     --> Size of Vector in Integer
   */
extern "C"
{
    void wide_vadd(
        const uint512_dt *in1, // Read-Only Vector 1
        const uint512_dt *in2, // Read-Only Vector 2
        uint512_dt *out       // Output Result
    )
    {
#pragma HLS INTERFACE m_axi port = in1 max_write_burst_length = 32 max_read_burst_length = 32 offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = in2 max_read_burst_length = 32 offset = slave bundle = gmem1
#pragma HLS INTERFACE m_axi port = out max_write_burst_length = 32 max_read_burst_length = 32 offset = slave bundle = gmem2
#pragma HLS INTERFACE s_axilite port = in1 bundle = control
#pragma HLS INTERFACE s_axilite port = in2 bundle = control
#pragma HLS INTERFACE s_axilite port = out bundle = control
#pragma HLS INTERFACE s_axilite port = return bundle = control


		uint512_dt v1_local[128][8];//4096
		uint512_dt v2_local[128][8];//4096

		ap_uint<32> v1_local32[128][128];//65536
		ap_uint<32> v2_local32[128][128];//
		ap_uint<32> v3_output32[128][128];//

		uint512_dt v3_output512;


#pragma HLS ARRAY_PARTITION variable=v1_local32 complete dim=2
#pragma HLS ARRAY_PARTITION variable=v2_local32 complete dim=1
#pragma HLS ARRAY_PARTITION variable=v2_local32 complete dim=2
#pragma HLS ARRAY_PARTITION variable=v3_output32 complete dim=2
#pragma HLS ARRAY_PARTITION variable=v1_local complete dim=2
#pragma HLS ARRAY_PARTITION variable=v2_local complete dim=0

		for(int i=0; i<128; i++){//4096
			#pragma HLS loop_tripcount min=128 max=128
			#pragma HLS UNROLL factor=2

			uint512_dt A;
			uint512_dt B;

			for(int j=0; j<8; j++){
				#pragma HLS PIPELINE II=1

				v1_local[i][j]=in1[i*8+j];
				v2_local[i][j]=in2[i*8+j];

				A=v1_local[i][j];
				B=v2_local[i][j];

				for(int k=0; k<16; k++){
					#pragma HLS loop_tripcount min=16 max=16
					v1_local32[i][j*16+k]=A.range(32*k + 31, 32*k);
					v2_local32[i][j*16+k]=B.range(32*k + 31, 32*k);
				}
			}
		}


		for(int i = 0; i < 128; i++){//256
		#pragma HLS loop_tripcount min=128 max=128

		    for(int j = 0; j < 8; j++){//256
		#pragma HLS loop_tripcount min=128 max=128

		        ap_int<32> result = 0;

		#pragma HLS UNROLL factor=2
		#pragma HLS PIPELINE II=1

		        for(int w=0; w<16; w++){

			        for(int k = 0; k < 128; k++){//256
			#pragma HLS loop_tripcount min=128 max=128

			        	result+= v1_local32[i][k]*v2_local32[k][j*16 + w];//256
			        }
			        v3_output32[i][j*16 + w] = result;//256

			        v3_output512.range(32*w + 31, 32*w)=v3_output32[i][j*16 + w];//128->256

		    	}

		        out[i*8+j]=v3_output512;

			}
		}



    }
}
