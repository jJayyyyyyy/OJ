#include <iostream>
#include <cstdio>
#include <complex>
#include <cmath>
using namespace std;

int main(){
	double r1, p1, r2, p2;
	scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
	double real1 = r1 * cos(p1);
	double imag1 = r1 * sin(p1);
	double real2 = r2 * cos(p2);
	double imag2 = r2 * sin(p2);
	complex<double> a(real1, imag1), b(real2, imag2);
	complex<double> result(a*b);
	double real = result.real();
	double imag = result.imag();

	if( fabs(imag)<0.01 )
		imag = 0;
	if( fabs(real)<0.01 )
		real = 0;

	if(imag<0)
		printf( "%.2lf-%.2lfi\n", real, fabs(imag) );
	else
		printf( "%.2lf+%.2lfi\n", real, fabs(imag) );

	return 0;
}
