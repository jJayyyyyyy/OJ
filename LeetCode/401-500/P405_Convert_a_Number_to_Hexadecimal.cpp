/*
https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/

同类题目 P405

1. 补码
2. 有符号数 -> 无符号数
3. 进制转换
*/

class Solution{
public:
	string dec2hex(unsigned int num){
		string ans = "";
		int remain;
		do{
			remain = num % 16;
			if( remain < 10 ){
				ans += (remain + '0');
			}else{
				ans += (remain + 'a' - 10);
			}
			num = num / 16;
		} while ( num != 0 );
		reverse(ans.begin(), ans.end());
		return ans;
	}

	string toHex(int num) {
		if( num == 0 ){
			return "0";
		}
		return dec2hex(num);
	}
};

// 改进，由于最终要转换成16进制
// 而除以 16 相当于右移 4 位，移位比除法快多了
class Solution2{
public:
	string dec2hex(unsigned int num){
		string ans = "";
		int remain;
		do{
			remain = num % 16;
			if( remain < 10 ){
				ans += (remain + '0');
			}else{
				ans += (remain + 'a' - 10);
			}
			num = num << 4;
		} while ( num != 0 );
		reverse(ans.begin(), ans.end());
		return ans;
	}

	string toHex(int num) {
		if( num == 0 ){
			return "0";
		}
		return dec2hex(num);
	}
};


// 再改进
// 由于 num 本身就是按照2制存储的，目标又是 16 进制
// 所以我们没必要按照10进制的方式再进行进制转换
// 直接按照 4 位
// think as a machine, not a human being
// 可能是我的第一个 0ms AC (在不使用 io 加速的情况下)
class Solution3{
public:
	string dec2hex(unsigned int num){
		string ans = "";
		for( size_t i = 0; i < 8; i++ ){
			unsigned int low4bit = num & 0x0f;
			if( low4bit < 10 ){
				ans += ( low4bit + '0');
			}else{
				ans += (low4bit + 'a' - 10);
			}
			num >>= 4;
		}
		reverse(ans.begin(), ans.end());
		size_t pos = ans.find_first_not_of("0");	// 去掉前导0
		return ans.substr(pos);
	}

	string toHex(int num) {
		if( num == 0 ){
			return "0";
		}
		return dec2hex(num);
	}
};