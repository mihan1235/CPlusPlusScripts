#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

enum error{
	err_index,
	err_print,
};

class ArrayCmd
{
	int size;	
public:
	ArrayCmd();
	~ArrayCmd();
	char*& operator[](int idx);
	void print_arr();
	char* give_struct(int index);
	int give_size();
	void make_real_size();
	void delete_arr();
private:
	void operator=(const ArrayCmd& ref){};
	ArrayCmd(const ArrayCmd& ref){};
	void Resize(int required_index);
protected:
	char** p;
};

int ArrayCmd::give_size()
{
	return size;
}

char* ArrayCmd::give_struct(int index)
{
	if (index>=size){
		throw(err_index);
	}
	return p[index];
}

ArrayCmd::ArrayCmd()
{
	p=NULL;
	size=0;
}

ArrayCmd::~ArrayCmd()
{
	if (p!=NULL){
		delete[] p;
	} 
}

char*& ArrayCmd::operator[](int idx) 
{
	if (p==NULL){
		size = 16;
		p = new char*[size];
	}
	if(idx >= size){
		Resize(idx);
	}
	return p[idx];
}

void ArrayCmd::Resize(int required_index) 
{
	int new_size = size;
	while(new_size <= required_index){
		new_size *= 2;
	}
	char** new_array = new char*[new_size];
	for(int i = 0; i < size; i++){
		new_array[i] = p[i];
	}
	delete[] p;
	p = new_array;
	size = new_size;
}

void ArrayCmd::make_real_size()
{
	if (p==NULL){
		throw(err_print);
	}
	int i=0;
	while (p[i]!=NULL){
		i++;
	}
	size=i;
	char** new_array = new char*[size];
	i=0;
	while ((i<size)&&(p[i]!=NULL)){
		new_array[i] = p[i];
		i++;
	}
	//putchar('\n');
	delete[] p;
	p = new_array;
}

void ArrayCmd::print_arr()
{
	if (p==NULL){
		throw(err_print);
	}
	int i=0;
	while ((i<size)&&(p[i]!=NULL)){
		printf("%i: '%s' ;\n",i,p[i]);
		i++;
	}
}
void ArrayCmd::delete_arr(){
	if (p!=NULL){
		delete[] p;
		p=NULL;
	} 
	size=0;	
};

class WordAnalyser{
	char* buf;
	int mode,i,size,mode1;
	char c;
	char c_prev;
public:
	WordAnalyser();
	char** mk_word();
	void put_char(char ch);
private:	
	void put_char_in_buf();
	void resize(int required_index);
	void reset_variabeles();
	void operator=(const WordAnalyser& ref) {}
	WordAnalyser(const WordAnalyser& ref) {}
};

WordAnalyser::WordAnalyser(){
	i=0;
	mode=0;
	size=0;
	buf=NULL;
};

void WordAnalyser::put_char(char ch){
	c_prev=c;
	c=ch;
}

void WordAnalyser::resize(int required_index) 
{
	int new_size = size;
	while(new_size <= required_index){
		new_size *= 2;
	}
	char* new_buf = new char[new_size];
	for(int i = 0; i < size; i++){
		new_buf[i] = buf[i];
	}
	delete[] buf;
	buf = new_buf;
	size = new_size;
}

void WordAnalyser::put_char_in_buf(){
	if (mode==0){
		size = 16;
		buf = new char[size];
	}
	if(i >= size-1){
		resize(i);
	}
	buf[i++]=c;
	buf[i]='\0';	
}

char** WordAnalyser::mk_word(){
	char** p=new char*[2];
	if ((c==' ')||(c=='\n')||(c=='\t')){
		if (mode==0){
			return NULL;
		}
		else {
			p[0]=buf;
			p[1]=NULL;
			reset_variabeles();
			return p;			
		}
	};
	if ((c=='<')||(c==';')||(c=='(')||(c==')')||(c=='`')){
		if (mode==0){
			put_char_in_buf();	
			p[0]=buf;
			p[1]=NULL;
			reset_variabeles();
			return p;		
		}
		else {
			p[0]=buf;
			reset_variabeles();
			put_char_in_buf();
			p[1]=buf;
			reset_variabeles();
			return p;
		}
		
	}
	if ((c=='|')||(c=='&')||(c=='>')){
		
	}
	put_char_in_buf();
	mode=1;
	return NULL;
}


void WordAnalyser::reset_variabeles(){
	i=0;
	mode=0;
	size=0;	
}


int main(int argc, char **argv)
{
	ArrayCmd arr;
	WordAnalyser analyser;
	char** point;
	int i=0;
	printf("--> ");
	char c;
	while ((c=getchar())!=EOF){
		analyser.put_char(c);
		point=analyser.mk_word();
		if (point!=NULL){
			arr[i++]=point[0];
			if (point[1]!=NULL){
				arr[i++]=point[1];
			}
			arr[i]=NULL;
			delete point;
		}
		if (c=='\n'){
			if (arr.give_size()!=0){
				arr.make_real_size();
				arr.print_arr();
				arr.delete_arr();
				i=0;
			}
			printf("--> ");
		}
	}
	return 0;
}

