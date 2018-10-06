/*
https://leetcode.com/problems/sort-array-by-parity/description/
把偶数全都放到奇数前面
同类题目 P905
*/

#include <iostream>
#include <vector>
using namespace std;

// 需要开辟 O(n) 的空间
class Solution{
public:
	vector<int> sortArrayByParity(vector<int> & A) {
		vector<int> even, odd;
		for( int n : A ){
			if( n % 2 == 0 ){
				even.push_back(n);
			}else{
				odd.push_back(n);
			}
		}
		even.insert(even.end(), odd.begin(), odd.end());
		return even;
	}
};

// 从前往后找奇数，从后向前找偶数
class Solution{
public:
	vector<int> sortArrayByParity(vector<int> & A) {
		int i=0, j=A.size()-1;
		while( i < j ){
			// !(even & 1) => !0 => true
			while( i < A.size() && !(A[i] & 1) ){
				i++;
			}
			// 现在 A[i] 是 A 的第一个奇数

			// 涉及到 >= 0 不能用 size_t
			while( j >= 0 && (A[j] & 1) ){
				j--;
			}
			// 现在 A[i] 是 A 的最后一个偶数

			if( i >= j ){
				break;
			}

			swap(A[i], A[j]);
			i++;
			j--;
		}
		return A;
	}
};

// 把偶数全都放到前面就好了，不用管偶数内部的相对顺序
class Solution{
public:
	vector<int> sortArrayByParity(vector<int> & A) {
		int i = 0;
		for( int j = 0; j < A.size(); j++ ){
			if( !(A[j] & 1) ){
				swap(A[i], A[j]);
				i++;
			}
		}
		return A;
	}
};