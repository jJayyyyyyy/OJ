#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int sum;
	int id;
	int moral;
	int talent;
}Student;

int cmp(const void *p1, const void *p2){
	const Student *a1 = (const Student *)p1;
	const Student *a2 = (const Student *)p2;

	if(a1->sum != a2->sum)
		return a1->sum < a2->sum;
	else if(a1->moral != a2->moral)
		return a1->moral < a2->moral;
	else
		return a1->id > a2->id;
}

int main(int argc, char * argv[]){
	int us_num=0, us_low=0, us_high=0;
	int id=0, moral=0, talent=0, sum=0;
	int num_pass=0, num_a=0, num_b=0, num_c=0, num_d=0;
	int i=0;
	Student *stu_a, *stu_b, *stu_c, *stu_d;

	scanf("%d%d%d", &us_num, &us_low, &us_high);
	stu_a = (Student *)malloc( us_num * sizeof(Student) );
	stu_b = (Student *)malloc( us_num * sizeof(Student) );
	stu_c = (Student *)malloc( us_num * sizeof(Student) );
	stu_d = (Student *)malloc( us_num * sizeof(Student) );

	for(i=0; i<us_num; i++){
		scanf("%d%d%d", &id, &moral, &talent);
		if( moral<us_low || talent<us_low ){
			continue;
		}else{
			if( moral>=us_high && talent>=us_high ){
				stu_a[num_a].id = id;
				stu_a[num_a].moral = moral;
				stu_a[num_a].talent = talent;
				stu_a[num_a].sum = moral + talent;
				num_a++;
			}else if( moral>=us_high && talent<us_high ){
				stu_b[num_b].id = id;
				stu_b[num_b].moral = moral;
				stu_b[num_b].talent = talent;
				stu_b[num_b].sum = moral + talent;
				num_b++;
			}else if( moral<us_high && talent<=moral ){
				stu_c[num_c].id = id;
				stu_c[num_c].moral = moral;
				stu_c[num_c].talent = talent;
				stu_c[num_c].sum = moral + talent;
				num_c++;
			}else{
				stu_d[num_d].id = id;
				stu_d[num_d].moral = moral;
				stu_d[num_d].talent = talent;
				stu_d[num_d].sum = moral + talent;
				num_d++;
			}
			num_pass++;
		}
	}

	qsort(stu_a, num_a, sizeof(Student), cmp);
	qsort(stu_b, num_b, sizeof(Student), cmp);
	qsort(stu_c, num_c, sizeof(Student), cmp);
	qsort(stu_d, num_d, sizeof(Student), cmp);

	printf("%d\n", num_pass);
	for(i=0; i<num_a; i++){
		printf("%d %d %d\n", stu_a[i].id, stu_a[i].moral, stu_a[i].talent);
	}
	for(i=0; i<num_b; i++){
		printf("%d %d %d\n", stu_b[i].id, stu_b[i].moral, stu_b[i].talent);
	}
	for(i=0; i<num_c; i++){
		printf("%d %d %d\n", stu_c[i].id, stu_c[i].moral, stu_c[i].talent);
	}
	for(i=0; i<num_d; i++){
		printf("%d %d %d\n", stu_d[i].id, stu_d[i].moral, stu_d[i].talent);
	}

	free(stu_a);
	free(stu_b);
	free(stu_c);
	free(stu_d);

	return 0;
}
