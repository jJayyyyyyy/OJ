###	天坑！慎填！

1.	输出逻辑的细节非常繁琐，读懂题目以后就能感觉出来。策略：先测试简单情况，尽快拿分，后面再回来完善。

2.	注意点（包括但不限于）

	*	记录[day, hour, minute], 并记录总的[minute=day * 24 * 60 + hour * 60 + minute]，看似多了一个冗余数据，但是方便后面调用，减少了一定的代码量。

	*	`getBill()`，即计算每一次有效通话的资费，要考虑到很多种情况，如
	
		*	同一天，相同小时
		*	同一天，不同小时
		*	不同天，不同小时
		*	...
		
		写这么多判断逻辑太复杂了，一不小心就出错。换个思路。重点在`while`。

		```cpp
		int getBill(const Record & st, const Record & end){
			int nowTime = st.time, endTime = end.time, minute = st.minute, hour = st.hour, day = st.day;
			int bill = 0;
			while( nowTime < endTime ){
				bill += 1 * rate[hour];
				nowTime++;
				minute++;
				if( minute == 60 ){
					minute = 0;
					hour++;
				}
				if( hour == 24 ){
					hour = 0;
					day++;
				}
			}
			return bill;
		}
		```

		这里用到了我们之前记录的冗余数据time(总的分钟数)，只要当前time还小于终点time，就继续循环。每次循环，加上一分钟的bill。而当前费率为rate[hour]。
		
		这种写法，就不用我们去列出所有的判断情况了。

	*	数据结构
	
		配合题目逻辑，构造合适的存储结构。多用点内存没关系，能减少逻辑思维的复杂度/空间换时间，就ok。不用担心重复和冗余。

		灵活使用vector，动态数组可以帮大忙。
		
	*	输出格式，时间数字前面补零

3.	测试用例:

		[link](https://www.nowcoder.com/completeSubmissionInfo?submissionId=14584366)

		28 85 19 52 26 93 48 19 92 61 90 45 89 82 92 90 31 83 55 22 87 98 58 28 58 CS02 07:01:23:57 on-line CS04 07:09:22:36 on-line CS02 07:02:03:36 on-line CS06 07:12:10:45 off-line CS06 07:04:12:36 off-line CS09 07:01:18:57 off-line CS03 07:10:03:34 on-line CS06 07:14:13:53 off-line CS09 07:19:12:22 on-line CS08 07:29:04:09 on-line CS03 07:24:07:06 on-line CS01 07:18:09:20 off-line CS06 07:30:02:08 off-line CS05 07:20:04:14 off-line CS08 07:23:08:19 on-line CS04 07:06:00:36 on-line CS02 07:28:04:43 on-line CS08 07:02:12:43 off-line CS01 07:15:11:30 off-line CS09 07:16:05:11 off-line CS09 07:19:11:05 on-line CS01 07:30:05:10 off-line CS05 07:28:10:37 on-line CS06 07:22:19:08 off-line CS04 07:25:12:38 on-line CS05 07:15:17:59 on-line CS05 07:03:09:58 on-line CS08 07:30:00:39 off-line CS01 07:14:05:58 off-line CS00 07:28:07:45 on-line CS08 07:02:20:01 on-line CS07 07:24:09:15 on-line CS04 07:31:21:42 off-line CS04 07:10:14:08 off-line CS06 07:20:17:33 off-line CS02 07:06:22:56 off-line CS01 07:19:01:35 off-line CS06 07:22:01:22 on-line CS08 07:22:10:19 on-line CS04 07:22:14:37 on-line CS09 07:29:03:17 on-line CS07 07:25:22:15 on-line CS01 07:29:17:45 on-line CS04 07:13:09:32 on-line CS02 07:16:15:49 on-line CS01 07:14:08:15 on-line CS06 07:06:18:15 off-line CS01 07:13:08:46 on-line CS04 07:12:13:38 off-line CS04 07:14:05:23 off-line CS09 07:02:05:43 on-line CS02 07:07:23:11 on-line CS06 07:08:07:32 on-line CS04 07:09:02:16 on-line CS01 07:25:09:33 on-line CS07 07:06:15:05 off-line CS00 07:30:09:10 on-line CS07 07:14:11:18 off-line 

	对应输出应该为

		CS01 07 13:08:46 14:05:58 1272 $799.42 14:08:15 15:11:30 1635 $1029.30 29:17:45 30:05:10 685 $356.55 Total amount: $2185.27 CS02 07 02:03:36 06:22:56 6920 $4301.96 Total amount: $4301.96 CS04 07 09:22:36 10:14:08 932 $535.48 13:09:32 14:05:23 1191 $734.47 25:12:38 31:21:42 9184 $5688.74 Total amount: $6958.69 CS05 07 15:17:59 20:04:14 6375 $3858.87 Total amount: $3858.87 CS06 07 08:07:32 12:10:45 5953 $3672.82 22:01:22 22:19:08 1066 $674.26 Total amount: $4347.08 CS08 07 29:04:09 30:00:39 1230 $781.98 Total amount: $781.98 CS09 07 02:05:43 16:05:11 20128 $12343.44 Total amount: $12343.44 

	ps: 没写好getBill()时的一次错误输出

		CS01 07 13:08:46 14:05:58 1272 $799.42 14:08:15 15:11:30 1635 $1029.30 29:17:45 30:05:10 685 $356.55 Total amount: $2185.27 CS02 07 02:03:36 06:22:56 6920 $4301.96 Total amount: $4301.96 CS04 07 09:22:36 10:14:08 932 $535.48 13:09:32 14:05:23 1191 $734.47 25:12:38 31:21:42 9184 $5688.74 Total amount: $6958.69 CS05 07 15:17:59 20:04:14 6375 $3858.87 Total amount: $3858.87 CS06 07 08:07:32 12:10:45 5953 $3672.82 22:01:22 22:19:08 1066 $674.26 Total amount: $4347.08 CS08 07 29:04:09 30:00:39 1230 $781.98 Total amount: $781.98 CS09 07 02:05:43 16:05:11 20128 $5635.84


每个不同的名字，
	ans.push_back(record)
		ans[cntAns] 累计处理

			ans[cntAns].name
			ans[cntAns].month
			ans[cntAns].callList.push_back()
			ans[cntAns].totalFee
	cntAns++


for i in range(cntAns):
	if ans[i].totalFee != 0
		output



on 和 off 必然是连续的

2~16
2号		05:43
16号		05:11

