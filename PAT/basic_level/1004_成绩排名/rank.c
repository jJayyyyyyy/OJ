#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[16];
	char id[16];
	int score;
}Student;

int main(){
	int i=0, us_n=0;
	char t_name[16], t_id[16];
	int t_score;
	Student *stu;

	scanf("%d", &us_n);
	stu = (Student *)malloc(2*sizeof(Student));

	// stu[0]---> high, stu[1]---> low
	scanf("%s %s %d", stu[0].name, stu[0].id, &stu[0].score);
	stu[1] = stu[0];


	for(i=1; i<us_n; i++){
		scanf("%s %s %d", t_name, t_id, &t_score);
		if(t_score > stu[0].score){
			strcpy( stu[0].name, t_name );
			strcpy( stu[0].id, t_id );
			stu[0].score = t_score;
		}
		if(t_score < stu[1].score){
			strcpy( stu[1].name, t_name );
			strcpy( stu[1].id, t_id );
			stu[1].score = t_score;
		}
	}

	printf("%s %s\n", stu[0].name, stu[0].id);
	printf("%s %s\n", stu[1].name, stu[1].id);

	free(stu);
	return 0;
}


/*
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95


*/
