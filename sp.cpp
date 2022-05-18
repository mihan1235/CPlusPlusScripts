#include <iostream>
using namespace std;

struct A {
	int n;
	A(int t){
		n=t;
	}
	operator int(){
		return n;
	}
};

void f(int i,int j){
	cout<<"f(int,int)\n";
}

void f(struct A,int j){
	cout<<"f(A,int)\n";
}

int main(int argc, char **argv){
	A a(1);
	f(a,1);
	return 0;
}
