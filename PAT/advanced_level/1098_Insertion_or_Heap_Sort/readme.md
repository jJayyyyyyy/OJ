*	思路

	*	首先对比插入排序
	
		*	若一趟插排后得到的序列与目标序列相同，则输出插排
		*	每趟插排用快排sort模拟
	
	*	其次对比堆排
	
		*	堆排模板参考[max_heap](https://github.com/jJayyyyyyy/cs/tree/master/data%20structure/heap)

*	同类题目：PAT_A_1089


```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXSIZE 104
using namespace std;

int n;
vector<int> raw, mid, rawCopy, midCopy, ans;


bool isSame(vector<int> & a, vector<int> & b){
	for( int i = 0; i < n; i++ ){
		if( a[i] != b[i] ){
			return false;
		}
	}
	return true;
}

bool isInsertion(){
	bool flag = false;
	for(int i = 1; i <= n; i++ ){
		flag = isSame(raw, mid);
		sort(raw.begin(), raw.begin()+i);

		if( flag == true ){
			ans.assign(raw.begin(), raw.end());
			break;
		}
	}
	return flag;
}

int main(){
	int num;
	cin>>n;
	for( int i = 0; i < n; i++ ){
		cin>>num;
		raw.push_back(num);
	}

	for( int i = 0; i < n; i++ ){
		cin>>num;
		mid.push_back(num);
	}
	rawCopy.assign(raw.begin(), raw.end());
	midCopy.assign(raw.begin(), raw.end());

	
	if( isInsertion() ){
		cout<<"Insertion Sort\n"<<ans[0];
		for(auto num : ans){
			cout<<' '<<num;
		}
		cout<<'\n';
	}else{
		for( int i = 0; i < n; i++ ){
			isSame(rawCopy, midCopy);
			make_heap(rawCopy.begin(), rawCopy.end());
			
		}

	}

	return 0;
}
```