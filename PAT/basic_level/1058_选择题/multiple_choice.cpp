#include <cstdio>
#include <algorithm>
using namespace std;

struct Test{
	int id=0;
	int pts=0;
	int total_choice=0;
	int cor_choice=0;
	int ans[5] = {0, 0, 0, 0, 0};
	int cnt_false=0;
};

int getTestAns(Test &test){
	scanf("%d %d %d", &test.pts, &test.total_choice, &test.cor_choice);
	int n = test.cor_choice;
	for(int i=0; i<n; i++){
		getchar();
		char ch = getchar();
		test.ans[ch-'a'] = 1;
	}
	getchar();
	return 0;
}

int resetScore(int &stuScore){
	stuScore = 0;
	return 0;
}

int resetSolution(int solution[]){
	for(int i=0; i<5; i++)
		solution[i] = 0;
	return 0;
}

int getSolution(int solution[]){
	int i, n;

	getchar();
	scanf("%d", &n);
	for( i=0; i<n; i++ ){
		getchar();
		char ch = getchar();
		solution[(ch-'a')] = 1;
	}
	getchar();
	getchar();

	return 0;
}

int getScore(int solution[], Test &test){
	int is_correct = 1;
	for( int i=0; i<5; i++ ){
		if( solution[i]!=test.ans[i] ){
			is_correct = 0;
		}
	}

	if( is_correct==1 )
		return test.pts;
	else{
		test.cnt_false++;
		return 0;
	}
}

int cmp(Test a, Test b){
	if( a.cnt_false!=b.cnt_false )
		return a.cnt_false>b.cnt_false;
	else
		return a.id<b.id;
}

int main(){
	int n, m, i, j, stuScore=0, solution[5]={0};
	Test test[104];

	scanf("%d %d", &n, &m);
	for( i=0; i<m; i++ ){
		test[i].id = i + 1;
		getTestAns(test[i]);
	}
	for(j=0; j<n; j++){
		resetScore(stuScore);
		for( i=0; i<m; i++ ){
			resetSolution(solution);
			getSolution(solution);
			stuScore += getScore(solution, test[i]);
		}
		printf("%d\n", stuScore);
	}

	sort(&test[0], &test[m], cmp);
	int cnt_false = test[0].cnt_false;
	if(cnt_false==0){
		printf("Too simple");
	}else{
		printf("%d", cnt_false);
		i = 0;
		while( cnt_false==test[i].cnt_false ){
			printf(" %d", test[i++].id);
		}
	}
	return 0;
}
