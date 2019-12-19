#include <stdio.h>
#include <stdlib.h>

int 
main(int argc, char **argv){
	int curr, prev, incomment=0, leave = 0;
	if ((prev = getchar()) == EOF){
		return 0;
	}
	while((curr=getchar()) != EOF){
		if (curr == '*' && prev == '/'){
			incomment = 1;
		}
		
		if (!incomment && !leave){
			putchar(prev);
		}
		else if (leave){
			leave = 0;
		}
		if (curr == '/' && prev == '*' && incomment){
			incomment = 0;
			leave = 1;
		}
		prev = curr;
	}
	if (!incomment && !leave){
		putchar(prev);
	}
	printf("\n");
	return 0;
}