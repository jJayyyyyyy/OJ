/*
 * https://leetcode.com/problems/sqrtx/description/
 * 数学题, 模拟sqrt(x), 求平方根
 * 同类题目 
 * 注意，输入可能是 x = 2147395600, sqrt(x) = 46340, 而 46341^2 就超过int范围了
 * 从小到大遍历的方法太慢了
 * 自然数是递增的, 用二分查找可以加快速度
 * left = mid + 1;
 * right = mid - 1;
 *
 * 似乎还有更快的方法, 牛顿法, 可以
*/

// #include <iostream>
// using namespace std;


// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	int mySqrt(int x) {
		if( x < 0 ){
			return -1;
		} else if( x == 0 ) {
			return 0;
		} else if( x == 1 ) {
			return 1;
		} else {
			long long key = x;
			long long left, mid, right, c1, c2;
			left = 0;
			right = x;

			while( true ){
				mid = (left + right) / 2;
				c1 = mid * mid;
				c2 = (mid+1)*(mid+1);
				if( c1 == key ){
					return (int)mid;
				}else if( c2 == key ){
					return (int)(mid + 1);
				}else if( c1 < key && c2 > key ){
					return (int)mid;
				}else if( c1 < key && c2 < key ){
					left = mid + 1;
				}else if( c1 > key && c2 > key ){
					right = mid - 1;
				}
			}
		}
	}
};

/*
// 牛顿法

class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        long a = x;
        while(r * r > a) {
            r = (r + a / r) / 2;
        }
        return r;
    }
};
*/

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;

// 	cout<<s.mySqrt(0)<<'\n';	// 0
// 	cout<<s.mySqrt(1)<<'\n';	// 1
// 	cout<<s.mySqrt(3)<<'\n';	// 1
// 	cout<<s.mySqrt(4)<<'\n';	// 2
// 	cout<<s.mySqrt(8)<<'\n';	// 2
// 	cout<<s.mySqrt(15)<<'\n';	// 3
// 	cout<<s.mySqrt(2147395600)<<'\n';	// 46340, 注意46341^2就超过int范围了
// 	return 0;
// }
