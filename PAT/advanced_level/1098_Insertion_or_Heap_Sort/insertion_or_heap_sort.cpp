#include <iostream>
#include <algorithm>
#define MAXSIZE 128
using namespace std;

bool isSame(int a[], int b[], int len){
	for( int i = 1; i <= len; ++i ){
		if( a[i] != b[i] ){
			return false;
		}
	}
	return true;
}

bool insertSort(int a[], int b[], int len){
	// 从第2个元素开始，判断是否需要插到前面
	for( int i = 2; i <= len; ++i ){
		// 对 [1, i] 区间进行排序
		sort( a+1, a+i+1 );

		// 最终要输出下一轮排序的结果
		// 所以在判断完成后还要来一次sort
		if( true == isSame(a, b, len) ){
			sort( a+1, a+i+2 );
			return true;
		}
	}
	return false;
}

int swap(int & a, int & b){
	int tmp = a;
	a = b;
	b = tmp;
	return 0;
}

int adjustHeap(int a[], int parent, int len){
	int child = parent * 2;
	while( child <= len ){
		int left = child;
		int right = left + 1;
		if( right <= len ){
			if( a[left] < a[right] ){
				child = right;
			}
		}

		if( a[parent] < a[child] ){
			swap( a[parent], a[child] );
			parent = child;
			child = parent * 2;
		}else{
			break;
		}
	}
	return 0;
}

bool heapSort(int a[], int b[], int len){
	for( int i = len / 2; i >= 1; --i ){
		adjustHeap(a, i, len);
	}

	for( int i = len; i > 1; --i ){
		swap( a[1], a[i] );
		adjustHeap( a, 1, i - 1 );

		if( true == isSame(a, b, len) ){
			// 再进行一趟堆排
			swap( a[1], a[i - 1] );
			adjustHeap( a, 1, i - 2 );
			return true;
		}
	}
	return false;
}

int showArray(int a[], int len){
	for( int i = 1; i <= len; ++i ){
		cout<<a[i];
		if( i < len ){
			cout<<' ';
		}
	}
	cout<<'\n';
	return 0;
}

int main(){
	int n, i;
	int origin[MAXSIZE]={0}, tmpOri[MAXSIZE]={0}, target[MAXSIZE]={0};

	cin>>n;
	for( i = 1; i <= n; ++i ){
		cin>>origin[i];
		tmpOri[i] = origin[i];
	}

	for( i = 1; i <= n; ++i ){
		cin>>target[i];
	}

	if( true == insertSort(tmpOri, target, n) ){
		cout<<"Insertion Sort\n";
		showArray(tmpOri, n);
	}else{
		cout<<"Heap Sort\n";
		for( int i = 1; i <= n; ++i ){
			tmpOri[i] = origin[i];
		}
		heapSort(tmpOri, target, n);
		showArray(tmpOri, n);
	}

	return 0;
}