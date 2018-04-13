#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int cnt_Win;
	int cnt_Tie;
	int cnt_Lose;
	int cnt_Bu_Win;
	int cnt_Chui_Win;
	int cnt_Jian_Win;
}Player;

int judge(Player *a, char choice_a, Player *b, char choice_b){
	if(choice_a=='B'){
		if(choice_b=='B'){
			a->cnt_Tie++;
			b->cnt_Tie++;
		}else if(choice_b=='C'){
			a->cnt_Win++;
			b->cnt_Lose++;
			a->cnt_Bu_Win++;

		}else{
			a->cnt_Lose++;
			b->cnt_Win++;
			b->cnt_Jian_Win++;

		}
	}else if(choice_a=='C'){
		if(choice_b=='B'){
			a->cnt_Lose++;
			b->cnt_Win++;
			b->cnt_Bu_Win++;

		}else if(choice_b=='C'){
			a->cnt_Tie++;
			b->cnt_Tie++;
		}else{
			a->cnt_Win++;
			b->cnt_Lose++;
			a->cnt_Chui_Win++;

		}
	}else{
		if(choice_b=='B'){
			a->cnt_Win++;
			b->cnt_Lose++;
			a->cnt_Jian_Win++;

		}else if(choice_b=='C'){
			a->cnt_Lose++;
			b->cnt_Win++;
			b->cnt_Chui_Win++;

		}else{
			a->cnt_Tie++;
			b->cnt_Tie++;
		}
	}

	return 1;
}

int how_to_win(Player *p){
	int B, C, J;
	B = p->cnt_Bu_Win;
	C = p->cnt_Chui_Win;
	J = p->cnt_Jian_Win;

	if(B>=C)
		if(B>=J)
			return 'B';
		else
			return 'J';
	else
		if(C>=J)
			return 'C';
		else
			return 'J';
}

int main(){
	int us_N=0, i=0;
	char choice_a[2], choice_b[2];
	int a_win, b_win;

	Player *a, *b;
	a = (Player *)malloc(sizeof(Player));
	b = (Player *)malloc(sizeof(Player));

	scanf("%d", &us_N);
	for(i=0; i<us_N; i++){
		scanf("%s %s", choice_a , choice_b);
		judge(a, choice_a[0], b, choice_b[0]);
	}

	printf("%d %d %d\n", a->cnt_Win, a->cnt_Tie, a->cnt_Lose);
	printf("%d %d %d\n", b->cnt_Win, b->cnt_Tie, b->cnt_Lose);
	printf("%c %c\n", how_to_win(a), how_to_win(b));

	free(a);
	free(b);

	return 0;
}


/*
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
*/
