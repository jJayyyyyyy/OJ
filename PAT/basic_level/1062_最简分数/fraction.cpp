#include <cstdio>
using namespace std;

int get_gcd(int a, int b){
	if(b==0)
		return a;
	else
		return get_gcd(b, a%b);
}

int get_lcm(int a, int b){
	return a*b/get_gcd(a, b);
}

int is_simplest(int a, int b){
	return 1==get_gcd(a, b);
}

int swap(int &a, int &b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	return 1;
}

int main(){
	int a1, b1, a2, b2, b3, a3;
	scanf("%d/%d %d/%d %d", &a1, &b1, &a2, &b2, &b3);

	int lcm = get_lcm(get_lcm(b1, b2), b3);
	int factor_b1b2 = lcm / b3;
	int lower_bound, upper_bound, res, is_first=1;
	lower_bound = a1 * lcm / b1;
	upper_bound = a2 * lcm / b2;
	if( lower_bound>upper_bound )
		swap(lower_bound, upper_bound);

	for( a3=1; ; a3++ ){
		if( is_simplest(a3, b3) ){
			res = a3*factor_b1b2;
			if( res>lower_bound && res<upper_bound ){
				if( is_first ){
					printf("%d/%d", a3, b3);
					is_first = 0;
				}else{
					printf(" %d/%d", a3, b3);
				}
			}else if(res>=upper_bound){
				break;
			}
		}
	}

	return 0;
}


/*
7/18 13/20 12

13/20 7/18 12

*/
