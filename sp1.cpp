#include <iostream>
using namespace std;
struct A {
	static A a;
public:
	A () {cout << "Constructor of A\n";}
	~A () {cout << "Destructor of A\n";}
};


class Error {
public:
	Error(){
		cout<<"Constructor of error\n";
	}
	~Error(){
		cout<<"Destructor of error\n";
	}
	Error(const Error& er){
		cout<<"Copy constructor of error\n";
	}
};

class B : public A {
	public:
	B () {cout << "Constructor of B\n";}
	~B () {cout << "Destructor of B\n";}
};

void f () {
	A a;
	//throw 1;
	//cout << "This message is never printed" << endl;
}
int main () {
	try {
		f ();
		B b;
		throw Error();
	}
	catch (int) { //cerr << "Catch of int\n";
		 }
	catch (Error) { cerr << "Catch of Error\n"; }
	return 0;
}
