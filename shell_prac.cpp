#include <stdio.h>
#include <string.h>

enum err{
	err_index,
	err_print,	
};

template <class T>
class Arr
{
	int size;	
public:
	Arr();
	~Arr();
	T*& operator[](int idx);
	void print_arr();
	void make_real_size();
	T* give_struct(int index);
	int give_size();
	static void print_arr_struct(T* a);
private:
	void delete_arr();
	void operator=(const Arr<T>& ref){};
	Arr(const Arr<T>& ref){};
	void Resize(int required_index);
protected:
	T** p=NULL;
};

template <class T>
void Arr<T>::delete_arr(){
	if (p!=NULL){
		delete[] p;
	} 
}

template <class T>
int Arr<T>::give_size()
{
	return size;
}

template <class T>
T* Arr<T>::give_struct(int index)
{
	if (index>=size){
		throw(err_index);
	}
	return p[index];
}

template <class T>
Arr<T>::Arr()
{
	p=NULL;
	size=0;
}

template <class T>
Arr<T>::~Arr()
{
	delete_arr();
}

template <class T>
T*& Arr<T>::operator[](int idx) 
{
	if (p==NULL){
		size = 16;
		p = new T*[size];
	}
	if(idx >= size){
		Resize(idx);
	}
	return p[idx];
}

template <class T>
void Arr<T>::Resize(int required_index) 
{
	int new_size = size;
	while(new_size <= required_index){
		new_size *= 2;
	}
	T** new_array = new T*[new_size];
	for(int i = 0; i < size; i++){
		new_array[i] = p[i];
	}
	delete[] p;
	p = new_array;
	size = new_size;
}

template <class T>
void Arr<T>::make_real_size()
{
	if (p==NULL){
		throw(err_print);
	}
	int i=0;
	while (p[i]!=NULL){
		i++;
	}
	size=i;
	T** new_array = new T*[size];
	i=0;
	while ((i<size)&&(p[i]!=NULL)){
		new_array[i] = p[i];
		i++;
	}
	//putchar('\n');
	delete[] p;
	p = new_array;
}

template <class T>
void Arr<T>::print_arr()
{
	if (p==NULL){
		throw(err_print);
	}
	int i=0;
	while ((i<size)&&(p[i]!=NULL)){
		printf("%i: ",i);
		print_arr_struct(p[i]);
		i++;
	}
}

template <class T>
void Arr<T>::print_arr_struct(T* a)
{
	printf("Unknown type! :(\n");
};

template <>
void Arr<char>::print_arr_struct(char* a)
{
	printf("%s\n",a);
};



class Shell {
	char c;
	bool end_str;
	bool end_file;
	public:
		Shell(){
			end_str=false;
			end_file=false;
		}
		Arr<char>* get_cmd();
		bool get_end_str(){
			return end_str;
		}
		bool get_end_file(){
			return end_file;
		}
	private:
		char* get_word();
};

char* Shell::get_word(){
	end_file=false;
	end_str=false;
	char* s=NULL;
	int size=15;
	int i=0;
	while ((c=getchar())!=EOF){
		if ((c=='\n')||(c==' ')){
			if (s==NULL){
				return(NULL);
			}
			s[i]='\0';
			if (c=='\n'){
				end_str=true;
			}
			return s;
		} 	
		if (c!='\t'){
			if (s==NULL) {
				s=new char [size];
			}
			if (i>=size){
				s[i]='\0';
				size=size+size;
				char* s1=new char [size];
				strcpy(s1,s);
				delete [] s;
				s=s1;
			}
			s[i]=c;
			i++;
		}
	}
	s[i]='\0';
	end_file=true;			
	return s;
};

Arr<char>* Shell::get_cmd(){
	Arr<char>* arr_p=new Arr<char>;
	Arr<char>& arr=*arr_p;
	char* s;
	int i=0;
	for(;;){
		s=get_word();
		if (end_file||end_str||(s==NULL)){
			break;
		}
		arr[i]=s;
		i++;
	}
	if ((end_file)||(s==NULL)){
		delete arr_p;
		return NULL;
	}
	arr[i]=NULL;
	return arr_p;
};

int main(int argc, char **argv){
	Shell term;
	Arr<char>* arr_p;
	for(;;){
			printf("->> ");
			arr_p=term.get_cmd();
			if (term.get_end_file()){
				break;
			}
			Arr<char>& arr=*arr_p;
			if (arr_p!=NULL){
				arr.print_arr();
				delete arr_p;
			}		
	}
	printf("\nEOF!!\n");	
	return 0;
}

