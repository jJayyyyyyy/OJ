1.	先以 string 为单位，录入全部数据, 得到 raw_list

2.	本题不用对数据进行过滤

3.	对于 raw_list 的每个元素，进行 get_digit_sum() ，按位求和

	```cpp
	void getDigitSum(string num){
		int len = num.size();
		int sum = 0, digit;
		for( int i = 0; i < len; i++ ){
			digit = num[i] - '0';
			sum += digit;
		}
		ans_set.insert(sum);
	}
	```

4.	得到一个数字的和之后，插入 ans_set ，去重

5.	得到完整的 ans_set 后，再整体迁移到线性的 ans_list，方便输出

6.	按格式输出
