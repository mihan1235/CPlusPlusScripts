#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void swap(int& a,int& b){
	int c=a;
	a=b;
	b=c;
}

int i_rnd(int a,int b){
	if (a==b){
		return b;
	}
	if (a>b){
		swap(a,b);
	}
	b=b+1;
	int tmp= random() % b;
	while (tmp < a){
		tmp= random() % b;
	}
	return tmp;
}

int rand_int_range(int a,int b){
	if (a>b){
		swap(a,b);
	}
	if ((a<0)&&(b<=0)){
		a=-a;
		b=-b;
		if (a>b){
			swap(a,b);
		}
		return -i_rnd(a,b);
	}
	if ((a<0)&&(b>=0)){
		a=-a;
		swap(a,b);
		int tmp=i_rnd(0,a);
		int tmp1=i_rnd(0,b);
		int tmp2=i_rnd(0,1);
		if (tmp2==0){
			return -tmp;
		}
		else{
			return tmp1;
		}
	}
	return i_rnd(a,b);
}

void swap(double& a,double& b){
	double c=a;
	a=b;
	b=c;
}

double rnd_range_0_1(){
	double tmp=i_rnd(0,1000);
	tmp=tmp/1000;
	return tmp;
}

double f_rand(double a,double b){
	if (a==b){
		return b;
	}
	if (a>b){
		swap(a,b);
	}
	double tmp=rnd_range_0_1();
	while ((tmp < a)||(tmp>b)){
		tmp= rnd_range_0_1();
	}
	return tmp;
}


int main(int argc, char *argv[]){
	srand(getpid());
	for (int i=0;i<55;i++){
		printf("[%f] ",f_rand(0,1));
	} 
	putchar('\n');
    return 0;
}


