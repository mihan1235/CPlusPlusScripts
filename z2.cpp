#include<stdio.h>

/*
Regular Grammar:

S->C
C->Ab|Ba
A->a|Ca
B->b|Cb
*/

enum mode {S,A,B,C,H};

enum error {
	err_mode,
	err_char,
	err_mode_s,
	err_grammar,
};

class LexerAnalyzer{
	char c;
	mode m;
public:
	void put_char(char tmp_ch){
		c=tmp_ch;
	}
	LexerAnalyzer(){
		m=H;	
	}
	void run();
	mode get_mode(){
		return m;
	}
};

void LexerAnalyzer::run(){
	if (!((c=='a')||(c=='b'))){
		throw(err_char);
	}
	//printf("[%c]\n",c);
	switch(m){
	case H:
		if (c=='a'){
			m=A;
		}
		if (c=='b'){
			m=B;
		}
		break;
	case A:
		if (c=='b'){
			m=C;
		}
		else {
			throw(err_grammar);
		}
		break;
	case B:
		if (c=='A'){
			m=C;
		}
		break;
	case C:
		if(c=='a'){
			m=A;
		}
		if (c=='b'){
			m=B;
		}
		if ((c=='\0')||(c==EOF)){
			m=S;
		}
		break;
	case S:
		throw(err_mode_s);
		break; 
	default:
		throw(err_mode);
	}	
}

void lex_err_exception(error n){
	switch (n){
		case err_mode:
			printf("Error: Unknown mode :(\n");
			break;
		case err_char:
			printf("Error: The char is not in grammar:(\n");
			break;
		case err_mode_s:
			printf("Error: Mode 'S' occured,when it was not expected:(\n");
			break;
		case err_grammar:
			printf("Error: This string doesn`t belong to this grammar:(\n");
			break;
		default:
			printf("Error: Smth unknown has occured:(\n");
	}
}

int make_lexer_analyze(char* str=NULL){
	LexerAnalyzer lex_an;
	char c;
	if (str==NULL){
		try {
			while ((c=getchar())!=EOF){
				lex_an.put_char(c);
				lex_an.run();
			}		
			lex_an.put_char(c);
		}
		catch(error n){
			lex_err_exception(n);
			return 1;
		} 
	}
	else {
		try{
			int i=0;
			while (str[i]!='\0'){
				lex_an.put_char(str[i]);
				lex_an.run();	
				i++;			
			}
			lex_an.put_char(str[i]);
		}
		catch(error n){
			lex_err_exception(n);
			return 1;
		}
	}
	printf("The string belongs to grammar:)\n");
	return 0;
}

int main(int argc,char** argv){
	if (argc<=1){
		make_lexer_analyze();
	}
	else {
		make_lexer_analyze(argv[1]);
	}
	return 0;
}

