#include <stdio.h>
#include <math.h>

int main(){
	int n, i;
	double real, imag, radius, max_radius=0.0;
	scanf("%d", &n);
	for( i=0; i<n; i++ ){
		scanf("%lf%lf", &real, &imag);
		radius = sqrt(real*real + imag*imag);
		if( max_radius<radius )
			max_radius = radius;
	}

	if( (int)(max_radius*100+0.5)==(int)(max_radius*100) )
		printf("%.2f", max_radius);
	else
		printf("%.2f", max_radius+0.005);

	return 0;
}
//16min
