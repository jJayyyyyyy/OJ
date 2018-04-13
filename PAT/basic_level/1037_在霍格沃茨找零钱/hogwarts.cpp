// #include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int p_galleon, p_sickle, p_knut;
	int a_galleon, a_sickle, a_knut;
	// c for change
	int c_galleon, c_sickle, c_knut;
	int p_sigma, a_sigma, c_sigma;
	scanf("%d.%d.%d", &p_galleon, &p_sickle, &p_knut);
	scanf("%d.%d.%d", &a_galleon, &a_sickle, &a_knut);

	p_sigma = p_galleon*17*29 + p_sickle*29 + p_knut;
	a_sigma = a_galleon*17*29 + a_sickle*29 + a_knut;
	if( p_sigma>a_sigma ){
		printf("-");
		c_sigma = p_sigma - a_sigma;
	}else{
		c_sigma = a_sigma - p_sigma;
	}
	c_galleon = c_sigma / 17 / 29;
	c_sigma -= c_galleon*17*29;
	c_sickle = c_sigma / 29;
	c_sigma -= c_sickle*29;
	c_knut = c_sigma;
	printf("%d.%d.%d\n", c_galleon, c_sickle, c_knut);

	return 0;
}

// 27min
// be careful not to make stupid mistakes...
// line 14 & line 15
// why the fuck did you misspell [*] to [+] between sickle and 29 !!!
