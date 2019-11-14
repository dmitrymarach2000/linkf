#include <stdlib.h>
#include <stdio.h>
#include "pcre.h"
struct Token{
	char *str;
	int pos;
};

int menu();
int start();


struct Token tokenizer();
int regex_match(struct Token token, char* rule);

int main(){
	menu();
	return 0;
}

int menu(){
	while(1){
        	int ch;
		printf("\n%s\n\n",pcre_version());
        	printf("1 - start\nq - exit\n>> ");
        	if((ch = getchar()) == '1'){ start(); }
        	else if(ch == 'q') { exit(0); }
        	else { printf("\nUnknown symbol!\n\n");}
        	if(ch != '\n') while (getchar() != '\n');

	}
}
int start() {
	FILE *i_file = fopen("../file.txt", "r");
	if(i_file != 0){
		int buf_len = 1;
		char *buf_str = (char*)malloc(buf_len);
		while(( buf_str[buf_len-1]  = fgetc(i_file)) != '\0' &&
			buf_str[buf_len-1] != ' '  &&
			buf_str[buf_len-1] != '\t' &&
			buf_str[buf_len-1] != '\r' &&
			buf_str[buf_len-1] != '\n'){
		buf_str = realloc(buf_str, ++buf_len);
		}
		printf("%s",buf_str);
		fclose(i_file);
	}else{printf("\nCan't open the file!\n\n");}
}
