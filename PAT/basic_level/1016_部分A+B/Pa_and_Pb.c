#include <stdio.h>

int get_cnt(const char a, const char *A){
	int t_i=0, t_cnt=0;
	while( A[t_i]!='\0' )
		if( A[t_i++]==a )
			t_cnt++;
	return t_cnt;
}

int get_p(const char a, const int cnt){
	int t_p=0, t_a=a-'0', t_cnt = cnt;
	while(t_cnt--)
		t_p = t_p*10 + t_a;
	return t_p;
}

int main(int argc, char *argv[]){
	char A[12], a, B[16], b;
	int cnt_a=0, cnt_b=0, p_a=0, p_b=0;

	scanf("%s %c %s %c", A, &a, B, &b);

	// cnt_a = get_cnt(a, A);
	// cnt_b = get_cnt(b, B);

	p_a = get_p(a, get_cnt(a, A));
	p_b = get_p(b, get_cnt(b, B));

	printf("%d\n", p_a+p_b);

	return 0;
}
