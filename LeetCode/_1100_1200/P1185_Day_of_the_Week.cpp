/*
https://leetcode.com/problems/day-of-the-week/description/?goto=old

同类题目 P1185

参考思路
https://leetcode.com/problems/day-of-the-week/discuss/377384/JavaC++Python-Zeller-Formula/339135

1971-1-1 is Friday
*/

#include <iostream>
using namespace std;

class Solution {
public:
	string dayOfTheWeek(int day, int month, int year) {
		vector<string> days_of_week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

		vector<int> days_of_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		int cnt = 0;
		for (int i = 1971; i < year; i++) {
			if (isLeapYear(i)) {
				cnt += 366;
			}
			else {
				cnt += 365;
			}
		}

		if (isLeapYear(year)) {
			days_of_month[1] = 29;
		}

		for (int i = 0; i < month - 1; i++) {
			cnt += days_of_month[i];
		}

		cnt += day - 1;
		day = (cnt + 5) % 7;
		return days_of_week[day];
	}

	bool isLeapYear(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
};