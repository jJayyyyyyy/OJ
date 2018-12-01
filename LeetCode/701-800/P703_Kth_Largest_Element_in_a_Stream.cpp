/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
设计一个类，能够输出一个序列中第K大的数
同类题目 P703

TODO:
学习 STL 中 priority_queue 的实现
/usr/include/c++/4.8.4/bits/queue.h
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// 方法1
// 维护一个 vector，构造的时候进行快排
// 更新的时候使用插排
// 问题在于, insert 找到 index 的时候，需要把index后面的元素全部向后推，
// 这个过程虽然是O(n)，但是n很大k很小时，还是比较耗时
// submission 大概在 80~110ms
class KthLargest1 {
public:
	int mK;
	vector<int> mNums;
	KthLargest1(int k, vector<int> nums) {
		mK = k;
		sort(nums.begin(), nums.end(), greater<int>());
		mNums = nums;
	}

	int add(int val) {
		int len = mNums.size();
		int i = 0;
		for( i = 0; i < len; i++ ){
			if( val > mNums[i] ){
				break;
			}
		}
		mNums.insert(mNums.begin() + i, val);
		return mNums[mK-1];
	}
};

// 方法2
// 优先队列(最小堆)
// http://www.cplusplus.com/reference/queue/priority_queue/priority_queue/
// 对于 [4,5,8,2] 的构造过程，
// 当size超过k时 进行pop，最后得到的是top为4的最小堆
// 也就是说，top就是第k大的数
// 时间复杂度大约是 log(n)
class KthLargest2 {
public:
    int mK;
    priority_queue<int, vector<int>, greater<int> > pqNums;
    
	KthLargest2(int k, vector<int> nums) {
		mK = k;
        for( int num : nums ){
            pqNums.push(num);
            if( pqNums.size() > mK ){
                pqNums.pop();
            }
        }
	}

	int add(int val) {
        pqNums.push(val);
        if( pqNums.size() > mK ){
            pqNums.pop();
        }
        return pqNums.top();
	}
};
