#include <iostream>
using namespace std;

struct A {
	static int n;
	A(int t){
		n=t;
	}
	operator int(){
		return n;
	}
};

int A::n=3;

int main(int argc, char **argv){
	const A a(1);
	a.n=3;
	return 0;
}
