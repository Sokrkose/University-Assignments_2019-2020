#include "matrixMultiplication.h"

// for tripcount pragmas
const int n_iter = n;
const int p_iter = p;
const int m_iter = m;


void ARRAY_COPY1(ap_uint<8> inArray1[n][m],ap_uint<8> outArray1[n][m]){

	for(int i = 0; i < n; i++){
		#pragma HLS loop_tripcount min=n_iter max=n_iter
			for(int j = 0; j < m; j++){
				#pragma HLS loop_tripcount min=m_iter max=m_iter
				#pragma HLS UNROLL factor=2
				#pragma HLS PIPELINE II=1
				outArray1[i][j] = inArray1[i][j];
			}
		}

}

void ARRAY_COPY2(ap_uint<8> inArray2[m][p],ap_uint<8> outArray2[m][p]){

	for(int i = 0; i < m; i++){
		#pragma HLS loop_tripcount min=m_iter max=m_iter
			for(int j = 0; j < p; j++){
				#pragma HLS loop_tripcount min=p_iter max=p_iter
				#pragma HLS UNROLL factor=2
				#pragma HLS PIPELINE II=1
				outArray2[i][j] = inArray2[i][j];
			}
		}

}

void matrix_mul_hw(ap_uint<8> inArray1[n][m], ap_uint<8> inArray2[m][p], unsigned int outArray[n][p]){

	#pragma HLS DATAFLOW

	ap_uint<8> BRAM_in1[n][m];
	ap_uint<8> BRAM_in2[m][p];

	#pragma HLS ARRAY_PARTITION variable=BRAM_in1 cyclic factor=m_iter dim=2
	#pragma HLS ARRAY_PARTITION variable=BRAM_in2 cyclic factor=m_iter dim=1

	ARRAY_COPY1(inArray1,BRAM_in1);
	ARRAY_COPY2(inArray2,BRAM_in2);

	int result;

	for(int i = 0; i < n; i++){
	#pragma HLS loop_tripcount min=n_iter max=n_iter

		for(int j = 0; j < p; j++) {
		#pragma HLS loop_tripcount min=p_iter max=p_iter
		#pragma HLS UNROLL factor=2
		#pragma HLS PIPELINE II=1 rewind

			result = 0;
	mainloop: for(int k = 0; k < m; k++){
				#pragma HLS loop_tripcount min=m_iter max=m_iter

				result += BRAM_in1[i][k] * BRAM_in2[k][j];
			}
				outArray[i][j] = result;
		}
	}

}
