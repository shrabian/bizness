/* A loop implementation of the subset sum problem by Sharan K */

#include <stdio.h>
#include<stdlib.h>

int subsetsum(int A[], int n, int k);

//Main func serves as scaffolding to test subsetsum func
int
main(int argc, char **argv){
	
	int A[10] = {2,3,6,8,9};
	if(subsetsum(A, 5, 21)){
		printf("It worked!\n");
	}
	else{
		printf("No solutions!\n");
	}
	return 0;
}

//Loop implementation of subset sum problem
int
subsetsum(int A[], int n, int k){
	
	//Array B stores the indexes of currrently trialled elements in A.
	int B[10], i=0;
	B[0] = 1;
	
	/* Should index 0 be stored in the first position of B, all possible subset
	permutation must have been trialled unsuccessfully */
	while(B[0]!=0){
		
		/*When possible new candidates are exhausted, the last element
		stored in B is disregarded */
		if(n==0){
			if(B[i-1] == 0){
				k+= A[0];
				i--;
			}
			n=B[i-1];
			k += A[n];
			i--;
		}
		
		/* Substracts values in A from k if they are smaller, and stores their
		index in B */
		
		if(A[n-1]<k){
			k-=A[n-1];
			B[i] = n-1;
			i++;
		}
		
		//If an element in A equals k, a subset must exist
		else if(A[n-1] == k){
			return 1;
		}
		n--;
	}
	return 0;
	
}