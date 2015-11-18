#include <stdio.h>

int main(){
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {"Kek", "Top", "Most", "Butter", "RTZ"};
	int *ages2 = {6,0,9};
	/*
	BASIC PTR SAMPLE
	*/
	//Ptrs to start of arrays
	int *age_ptr = ages;
	char **names_ptr = names;
	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	for(i = 0; i < count; i++){
		printf("%s is %d years old\n", *(names_ptr+i), *(age_ptr+i));
		//Same as 
		printf("%s is %d years old\n", names_ptr[i], age_ptr[i]);
	}
	
	//Weird ptr way
	for(names_ptr = names, age_ptr = ages;
		(age_ptr - ages) < count;
		names_ptr++, age_ptr++){
			printf("%s is %d years old\n", *names_ptr, *age_ptr);
		}
		
	for(i = 0; i < 3; i++){
		printf("Ptr testing, %d \n", *(ages2+i));
	}
	
	/*for(i = 0; i < 3; ages2++){
		printf("Ptr testing, %d \n", *ages2);
	}*/
	return 0;
}