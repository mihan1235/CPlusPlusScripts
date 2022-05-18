#include <stdio.h>
#include <string.h>

class ConvNumberToStr {
	int i,j,sign;
	char c;
	long int ipart;
	double tmp;
	long int fpart;
public: 
    char* itoa(int n);
    char* ftoa(double f);
private:
	long int get_ipart(double f);
    long int get_fpart(double f);
	char* reverse(char* s);
};

char* ConvNumberToStr::reverse(char* s) {	 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }     
     return s;
 }

char* ConvNumberToStr::itoa(int n) {
	 char* s=new char[45];
     if (n < 0) {
		 sign=n;
         n = -n;  
     }      
	 i = 0;	 
     do {     
         s[i] = n % 10 + '0';  
         i++;
         n=n/10;
     } while (n > 0);  
     if (sign < 0) {
         s[i] = '-';
         i++;
     }
     s[i] = '\0';
     s=reverse(s);
     return s;
 }
 
long int ConvNumberToStr::get_ipart(double f) {
	ipart=f;
	return ipart;	
}
 
long int ConvNumberToStr::get_fpart(double f) {
	sign=0;
    if (f < 0) {
		sign=1;
        f = -f;
    }       
	ipart=f;
	tmp=(f-ipart);
	tmp=tmp*10;
	fpart=tmp;
	while (fpart %10!=0){
		tmp=tmp*10;
		fpart=tmp;		
	}
	fpart=fpart/10;
	if (sign == 1) {
        ipart=-ipart;
    }
	return fpart;
}	

char* ConvNumberToStr::ftoa(double f) {
	 char* s=new char[45];
	 char* t=NULL;
	 const char* b=".";
	 t=strcpy(s,itoa(get_ipart(f)));
	 t=strcat(s,b);
	 t=strcat(s,itoa(get_fpart(f)));
     return t;
}
	
int main(int argc, char **argv)
{
	ConvNumberToStr str;
	char* buf;
	double f;
	int n;
	printf("Введите целое число: ");
	scanf("%i",&n);
	buf=str.itoa(n);
	printf("%s\n",buf); 
	delete [] buf;
	printf("Введите вещественное число: ");
	scanf("%lf",&f);
	buf=str.ftoa(f);
	printf("%s\n",buf); 
	delete [] buf;
	return 0;
}

