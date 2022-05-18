#include <string>

class Example
{
	int i;
	std::string s;
public:
	Example(int j){
		i=j;
		s="abc";
	};
};


//const Example& f1(){ return Example(1); } // компилируется, не работает.
//Example& f2(){ return Example(2); } // не компилируется, не работает.
const Example* f3(){ return new Example(3); } // компилируется, не работает. (нельзя будет удалить объект)
Example* f4(){ return new Example(4); } //  компилируется, работает.


int main(){
   //const Example& e1 = f1();
   //Example& e2 = f2();
   const Example* e3 = f3();
   Example* e4 = f4();

   delete e3;
   delete e4;
}
