/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 * 去掉值为有序表中重复的元素
 * 本题的输入是数组, 数组的插入, 需要将每一个后面的元素都往后推，时间复杂度为O(n), 因此建议新建一个数组用于存放答案. 除非题目有明确的空间限制, 但是这DS太傻了, 要考察插入操作, 还不如直接出链表
 * P021的输入是链表, 插入删除的时间复杂度为常量, 与本题的数组不同
 *
 * 注意 nums2 为空的情况
 * 注意 复制粘贴自己代码的时候, 要改好参数
*/

// #include <iostream>
// using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i=0, j=0;
		vector<int> nums3;

		if( m > 0 && n > 0 ){
			while( i < m && j < n ){
				if( nums1[i] < nums2[j] ){
					nums3.push_back(nums1[i]);
					i++;
				}else{
					nums3.push_back(nums2[j]);
					j++;
				}
			}

			while( i < m ){
				nums3.push_back(nums1[i++]);
			}

			while( j < n ){
				nums3.push_back(nums2[j++]);
			}

			nums1 = nums3;
		}else if( m > 0 ){
			nums1 = nums1;
		}else{
			nums1 = nums2;
		}
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;
// 	vector<int> nums1, nums2;

// 	// case 1
// 	// nums1.push_back(1);
// 	// nums1.push_back(2);
// 	// nums1.push_back(3);
// 	// nums1.push_back(0);
// 	// nums1.push_back(0);
// 	// nums1.push_back(0);

// 	// nums2.push_back(2);
// 	// nums2.push_back(5);
// 	// nums2.push_back(6);


// 	// case 2
// 	// nums1.push_back(1);


// 	// case 3
// 	nums1.push_back(4);
// 	nums1.push_back(0);
// 	nums1.push_back(0);
// 	nums1.push_back(0);
// 	nums1.push_back(0);
// 	nums1.push_back(0);

// 	nums2.push_back(1);
// 	nums2.push_back(2);
// 	nums2.push_back(3);
// 	nums2.push_back(5);
// 	nums2.push_back(6);


// 	s.merge(nums1, 1, nums2, 5);

// 	for( auto i : nums1 ){
// 		cout<<i<<' ';
// 	}

// 	cout<<'\n';
// 	return 0;
// }