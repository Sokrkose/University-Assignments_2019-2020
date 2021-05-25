void loop(int* A, int b){
	
	for(int i = 10; i != 0; i = i - 1){
		A[i] = A[i] + b;
	}
	
}

void unrolledLoop(int* A, int b){
	
	for(int i = 10; i != 0; i = i - 5){
		A[i] = A[i] + b;
		A[i - 1] = A[i - 1] + b;
		A[i - 2] = A[i - 2] + b;
		A[i - 3] = A[i - 3] + b;
		A[i - 4] = A[i - 4] + b;
	}
	
}

void falseUnroll(int* A, int b){
	
	for(int i = 10; i != 0; i = i - 3){
		A[i] = A[i] + b;
		A[i - 1] = A[i - 1] + b;
		A[i - 2] = A[i - 2] + b;
	}
	
}


void correctUnroll(int* A, int b){
	
	for(int i = 10; i != 0;){
		A[i] = A[i] + b;
		i--;
		
		if(i != 0){
			A[i - 1] = A[i - 1] + b;
			i--;
		}
		
		if(i != 0){
			A[i - 2] = A[i - 2] + b;
			i--;
		}
	}
	
}

int main(void ){
	
	int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b = 1;
	
	//loop(A, b);
	//unrolledLoop(A, b);
	//falseUnroll(A, b);
	correctUnroll(A, b);
	
	return 0;
}
