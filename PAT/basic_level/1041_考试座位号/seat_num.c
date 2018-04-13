#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char id[16];
	int exam_seat;
}Student;

int main(){
	int us_N=0, us_M=0, test_seat=0, exam_seat=0, i=0;
	char id[16]={0};
	Student *stu;

	scanf("%d", &us_N);
	stu = (Student *)malloc( (us_N+1)*sizeof(Student) );

	for( i=0; i<us_N; i++ ){
		scanf("%s %d %d", id, &test_seat, &exam_seat);
		strcpy(stu[test_seat].id, id);
		stu[test_seat].exam_seat = exam_seat;
	}

	scanf("%d", &us_M);
	for( i=0; i<us_M; i++){
		scanf("%d", &test_seat);
		printf("%s %d\n", stu[test_seat].id, stu[test_seat].exam_seat);
	}

	return 0;
}
