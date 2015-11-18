#include <stdio.h>
#include <ctype.h>
#include <string.h>

int lengthOfStringArray(char *arr[]);
void cTypeFuncs();

int main(){
	char *strs[] = {"juuh", "elikkäs", "nyt","syöpä"};
	printf("Lenght of string array is (not) %d\n", lengthOfStringArray(strs));
	printf("Length of strin array IS %ld \n", sizeof(strs) / sizeof(*strs));
	cTypeFuncs();
	return 0;
}

int lengthOfStringArray(char *arr[]){
	return sizeof(arr) / sizeof(*arr);
}

void cTypeFuncs(){
	char *string = "are these printable? 3554";
	int i = 0;
	for(i = 0; i< strlen(string); i++){
		if(isalpha(string[i]) || isblank(string[i])){
			printf("Printable: %c \n", string[i]);
		}else{
			printf("Not printable! \n");
		}
	}
}