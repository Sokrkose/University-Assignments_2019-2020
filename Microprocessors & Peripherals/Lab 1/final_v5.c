
__asm int myASM_HashSummarizer(char* string, int* hash){

		PUSH	{r4, r5, lr}					//Put r4, r5 and the Link Register (in order to keep the return address) in the stack of the activation record of the function
		MOV		r2, r0								//Assign the value of register r0 (which has stored the "string" argument) to the register r2
		MOV		r4, r1								//Assign the value of register r1 (which has stored the "hash" argument) to the register r4

		MOVS	r3, #0								//Assign the value 0 to the register r3, which is the "sum" hash of the string
		MOVS	r1, #0								//Assign the value 0 to the register r1, which is a counter "i" for a while loop
	
		B			goto1									//Branch to the "goto1" label, in order to get in the while loop

whileLoop
		CMP		r0, #65								//Compare the value of register r0 which is " *(string + i) " with the decimal number 65
		BLT		goto2									//if r0 is less than 65, branch to the "goto2" label

		CMP		r0, #90								//Compare the value of register r0 which is " *(string + i) " with the decimal number 90
		BGT		goto2									//if r0 is greater than 90, branch to the "goto2" label

		SUB		r5, r0, #65						//Subtract the value of register r0 with 65 and store it to the register r5
		LDR		r5, [r4, r5, LSL #2]	//Load to r5 the value of "r4[r5]" or "hash[*(string + i) - 65]". LSL #2 is for shifting left by 2, thus multiply by 4, in order to move 4 bytes, since the index of the table is an integer value
		ADD		r3, r3, r5						//Add the value of register r5 to the register r3 which stores the "sum" variable

goto2
		CMP		r0, #48								//Compare the value of register r0 which is " *(string + i) " with the decimal number 48
		BLT		goto3									//if r0 is less than 48, branch to the "goto3" label
		
		CMP		r0, #57								//Compare the value of register r0 which is " *(string + i) " with the decimal number 57
		BGT		goto3									//if r0 is greater than 57, branch to the "goto3" label

		SUB		r5, r0, #48						//Subtract r0 value with 48 and store it to the register r5
		SUBS	r3, r3, r5						//Subtract r3 value with r5 and store it to the register r3 which stores the "sum" variable

goto3
		ADDS	r1, r1, #1						//Increace the counter value "i" by 1

		NOP													//Unnecessary instruction which does nothing and indicates the end of while loop

goto1
		LDRB	r0, [r2, r1]					//Assign to the register r0 the value of " *(string + i) "
		CMP		r0, #0								//Implement the comparison " *(sting + i) == NULL " in order to check if the string is finished
		BNE		whileLoop							//if not equeal, thus if it is not the end of the string, branch to the "goto4" label

		MOV		r0, r3								//Copy the value of register r3 (which has stored the "sum" hash of the string) to the register r0 which is the output of the function

		POP		{r4, r5, pc}					//Deallocate r4, r5 and from the stack and assign the link register value to the program counter

}

int main(void )
{
	
		int hash[26] = {18, 11, 10, 21, 7, 5, 9, 22, 17, 2, 12, 3, 19, 1, 14, 16, 20, 8, 23, 4, 26, 15, 6, 24, 13, 25};

    char* string = "AaB9C 5F!-EZ.";
		int actualSum = 62;
			
		int sum = myASM_HashSummarizer(string, hash);
		
		int validation = 0;
		if(actualSum == sum){	
			validation = 1;
		}

 		return 0;
	
}
