#include <stdio.h>
#include <stdlib.h>

char* commands[]  = {"add","sub","mul"};
int no_of_commands = 3;

int add(int first, int second)
{
	return first + second;
}

int sub(int first, int second)
{
	return first - second;
}

int mul(int first, int second)
{
	return first * second;
}

int main(int argc, char* argv[])
{
	if (argc > 3){
		char* command = argv[1];
		int command_int = -1;
		int first = atoi(argv[2]);
		int second = atoi(argv[3]);
		int i = 0;
		for(i = 0; i < no_of_commands; i++){
			if(!strcmp(command, *(commands+i))){
				command_int = i;
			}
		}
		int result = 0;
		switch(command_int){
			case -1:
				printf("Invalid command! Commands are add, sub and mul\n");
				return -1;
			case 0:
				result = add(first, second);
				printf("%d + %d = %d\n", first, second, result);
				break;
			case 1:
				result = sub(first, second);
				printf("%d - %d = %d\n", first, second, result);
				break;
			case 2:
				result = mul(first, second);
				printf("%d * %d = %d\n", first, second, result);
				break;
			default:
				break;
		}
	} else {
		printf("Usage: ./calc <command> <int1> <int2>\n");
	}
	
	return 0;
}