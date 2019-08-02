/*
https://leetcode.com/problems/day-of-the-year/description/
给定 YYYY-MM-DD 格式的日期，输出这是一年中的第几天
同类题目 P1154

*/

#include <iostream>
using namespace std;

class Solution {
public:
	bool isLeapYear(int year) {
		return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
	}

	int dayOfYear(string date) {
		int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int year = stoi(date.substr(0, 4));
		int month = stoi(date.substr(5, 2));

		// 统计当月的天数
		int day = stoi(date.substr(8));
		// 统计之前月份的天数
		for (int i = 1; i < month; i++) {
			day += daysOfMonth[i];
		}

		// 统计闰年额外带来的一天
		if (month > 2 && isLeapYear(year)) {
			day++;
		}

		return day;
	}
};