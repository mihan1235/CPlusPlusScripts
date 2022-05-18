#include <stdio.h>
#include <math.h>
class TooHigh {
	double pol5;
	public:
	TooHigh(double pol5){
		this->pol5 = pol5;
	}
	double Get(){
		return pol5;
	}
};

class AbstractFunction {
public:
	virtual double Value(double arg) const = 0;
	virtual AbstractFunction* Antiderivative() const = 0;
	double operator() (double arg) {
		return Value(arg);
	}
	virtual ~AbstractFunction(){};
};

class Polynomial4: public AbstractFunction {
	double pol[5];
	public:
	Polynomial4( double constant_term){
		pol[0] = constant_term;
		pol[1] = pol[2] = pol[3] = pol[4] = 0;
	}
	double& operator[] (int i)
	{
		return pol[i];
	}
	double Value(double arg) const
	{
		int tmp;
		tmp=pol[0] + arg * pol[1] + pow(arg, 2) * pol[2];
		tmp=tmp+pow(arg, 3) * pol[3] + pow(arg, 4) * pol[4];
		return tmp;
	}
	AbstractFunction* Antiderivative() const {
		if (pol[4]){
			throw(TooHigh(pol[4] / 5));
		}
		else {
			Polynomial4 *pnew_func = new Polynomial4(pol [0]);
			for (int i = 1; i < 5; i++){
				pnew_func -> pol[i] = pol[i - 1] / i;
			}
			return pnew_func;
		}
	}
};

int main(){
	try {
		Polynomial4 pol(6);
		pol[1] = 120;
		AbstractFunction *f1 = &pol;
		AbstractFunction *f2 = f1->Antiderivative();
		AbstractFunction *f3 = f2->Antiderivative();
		AbstractFunction *f4 = f3->Antiderivative();
		delete f2;
		delete f3;
		for (int i = 0; i < 5; i++){
			printf("%.2lf ", (*(Polynomial4*)f4)[i]);
		}
		printf("\n%.2lf %.2lf\n", f4->Value(1), f4->Value(2));
		AbstractFunction *f5 = f4->Antiderivative();
		delete f5;
	}
	catch(TooHigh &h)
	{
		printf("TooHigh: %.2lf\n", h.Get());
	}
	return 0;
}
