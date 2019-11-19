#include <stdlib.h>
#include <stdio.h>
#include <pcre.h>
#include <string.h>

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
        	if((ch = getchar()) == '1'){ printf("\n"); start(); }
        	else if(ch == 'q') { exit(0); }
        	else { printf("\nUnknown symbol!\n\n");}
        	if(ch != '\n') while (getchar() != '\n');

	}
}
int start() {
	FILE *i_file = fopen("../file.txt", "r");
	int token_n = 0;
	struct Token* tokens = (struct Token*)malloc((token_n + 1) * sizeof(struct Token));
	if(i_file != 0){
		char ch;
		char new_wrd = 0;
		int  buf_pos = 0;
		int  buf_len = 0;
		char *buf_str = (char*)malloc((buf_len + 1) * sizeof(char));

		while(( ch = fgetc(i_file) ) != '\0'){

			printf("-+%c",ch);
			++buf_pos;
			if(	ch != ' '  &&
				ch != '\n' && 
				ch != '\r' &&
				ch != '\t'	){
	
				printf("\nletter\n\n");
				if(!new_wrd){ tokens[token_n].pos = buf_pos; }
				new_wrd = 1;
				buf_len++;
				buf_str[buf_len - 1] = ch;
				buf_str = realloc(buf_str, buf_len);

			}else if(new_wrd){
				printf("\nword\n\n");
				buf_str[buf_len - 1] = '\0';
				tokens[ token_n - 1].str = (char*)malloc(buf_len * sizeof(char));
				strcpy(tokens[token_n - 1].str, buf_str);
				new_wrd = 0;
				buf_len = 0;
				buf_str = realloc(buf_str, (buf_len + 1) * sizeof(char));
				token_n++;
			}

			free(buf_len);
			for(int i = 0; i < token_n; ++i){
				printf("%d\t%s\n", tokens[i].pos, tokens[i].str);
			}

		}
		fclose(i_file);

	}else { printf("\nCan't open the file!\n\n"); }
}
