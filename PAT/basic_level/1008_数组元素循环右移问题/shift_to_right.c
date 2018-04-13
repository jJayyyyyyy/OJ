#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}ListType;

ListType *init_list(ListType arr[], const int us_N);
ListType *shift_head(ListType *head, const int us_N, const int us_shift);
int print_list(ListType *head, const int us_N);
ListType *init_list_2(ListType *arr, const int us_N);


int main(int argc, char *argv[]){
	ListType arr[101], *head=NULL;
	int us_N=0, us_shift=0;

	scanf("%d%d", &us_N, &us_shift);
	head = init_list(arr, us_N);
	head = shift_head(head, us_N, us_shift);
	print_list(head, us_N);

	return 0;
}

// int sub_main(){
// 	ListType *arr=NULL, *head=NULL;
// 	int us_N=0, us_shift=0;

// 	scanf("%d%d", &us_N, &us_shift);
// 	arr = init_list_2(arr, us_N);
// 	head = shift_head(arr, us_N, us_shift);
// 	print_list(head, us_N);

// 	free(arr);
// 	return 0;
// }



ListType *init_list(ListType arr[], const int us_N){
	int i=0;

	for(i=0; i<us_N; i++){
		scanf("%d", &arr[i].data);
		arr[i].next = &arr[i+1];
	}
	arr[i-1].next = &arr[0];

	return &arr[0];
}

ListType *shift_head(ListType *head, const int us_N, const int us_shift){
	int i=0, r_shift=0;
	// int l_shift=0;

	r_shift = us_N - us_shift%us_N;
	// l_shift = us_shift % us_N;
	for(i=0; i<r_shift; i++){
		head = head->next;
	}

	return head;
}

int print_list(ListType *head, const int us_N){
	int i=0, is_start=1;

	for(i=0; i<us_N; i++){
		if(is_start){
			printf("%d", head->data);
			is_start = 0;
		}else
			printf(" %d", head->data);
		head = head->next;
	}

	return 0;
}

ListType *init_list_2(ListType *arr, const int us_N){
	int i=0;
	arr = (ListType *)malloc( us_N*sizeof(ListType) );

	for(i=0; i<us_N; i++){
		scanf("%d", &arr[i].data);
		arr[i].next = &arr[i+1];
	}
	arr[i-1].next = &arr[0];

	return &arr[0];
}



/*
ListType *init_circular_linked_list(int us_N){
	int i=0;
	ListType *head, *node, *p_tail;

	while( i++<us_N ){
		node = (ListType *)malloc( sizeof(ListType) );
		scanf("%d", &node->data);
		node->next = NULL;

		if( NULL == head ){
			head = node;
		}else{
			p_tail = head;
			while( NULL != p_tail->next )
				p_tail = p_tail->next;
			p_tail->next = node;
		}
	}
	node->next = head;

	return head;
}

int free_list(ListType *head, int us_N){
	ListType *p, *q;
	int i=0;

	p = head;
	while( i++<us_N ){
		q = p->next;
		free(p);
		p = q;
	}
	return 1;
}
*/
