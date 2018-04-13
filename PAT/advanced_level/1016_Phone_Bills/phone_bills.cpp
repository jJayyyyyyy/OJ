#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#define MAXSIZE 1004
using namespace std;

struct Record{
	string username;
	int day, hour, minute;
	int time;
	int status;
};

struct CallRecord{
	Record st;
	Record end;
	int bill;
	CallRecord(Record & _st, Record & _end, int _bill){
		st = _st;
		end = _end;
		bill = _bill;
	}
};

struct User{
	string name;
	int totalBill = 0;
	vector<CallRecord> callList;
};

Record recordList[MAXSIZE];
vector<User> userList;
int minToDay = 24 * 60;
int minToHour = 60;
int rate[32] = {0};

int cmp(const Record & a, const Record & b){
	if( a.username != b.username ){
		return a.username < b.username;
	}else{
		return a.time < b.time;
	}
}

int getBill(const Record & st, const Record & end){
	int nowTime = st.time;
	int endTime = end.time;
	int minute = st.minute, hour = st.hour, day = st.day;
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

/*
int getBill(const Record & st, const Record & end){
	// 同一天
	if( st.day == end.day ){
		if( st.hour == end.hour ){
			// 同一小时内的电话，资费费率相同
			int bill = (end.time - st.time) * rate[end.hour - st.hour];
			return bill;
		}else{
			// 跨小时的电话，资费分三段进行计算
			// 当前小时内的资费
			int bill = (60 - st.minute) * rate[st.hour];
			// 中间连续小时的资费
			for( int i = st.hour + 1; i < end.hour; ++i ){
				bill += 60 * rate[i];
			}
			// 最后不足一小时内的资费
			bill += end.minute * rate[end.hour];
			return bill;
		}
	}

	// 跨天的电话
	else{
		// 当天资费
		int bill = (60 - st.minute) * rate[st.hour];
		for( int i = st.hour + 1; i < 24; ++i ){
			bill += 60 * rate[i];
		}

		// 中间天数的资费
		for( int i = st.day + 1; i < end.day; ++i ){
			for( int j = 0; j < 24; ++j ){
				bill += 60 * rate[j];
			}
		}
		// 最后不满一天的资费
		for( int i = 0; i < end.hour; ++i ){
			bill += 60 * rate[i];
		}

		bill += end.minute * rate[end.hour];
		return bill;
	}
}
*/

int printBill(const int & cent){
	cout.setf(ios::fixed);
	cout<<'$'<<setprecision(2)<<(cent * 1.0 / 100)<<'\n';
	return 0;
}

int getInfo(const CallRecord & call){
	cout<<setfill('0')<<setw(2)<<call.st.day<<':';
	cout<<setfill('0')<<setw(2)<<call.st.hour<<':';
	cout<<setfill('0')<<setw(2)<<call.st.minute<<' ';
	
	cout<<setfill('0')<<setw(2)<<call.end.day<<':';
	cout<<setfill('0')<<setw(2)<<call.end.hour<<':';
	cout<<setfill('0')<<setw(2)<<call.end.minute<<' ';
	
	cout<<(call.end.time - call.st.time)<<' ';
	printBill(call.bill);
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string username, status;
	char ch;
	int n, i, j, month, day, hour, minute;

	for( i = 0; i < 24; ++i ){
		cin>>rate[i];
	}
	cin>>n;
	for( i = 0; i < n; ++i ){
		cin>>username>>month>>ch>>day>>ch>>hour>>ch>>minute>>status;
		recordList[i].username = username;
		recordList[i].day = day;
		recordList[i].hour = hour;
		recordList[i].minute = minute;
		recordList[i].time = day * 24 * 60 + hour * 60 + minute;
		if( status == "on-line" ){
			recordList[i].status = 1;
		}else{
			recordList[i].status = 0;
		}
	}
	sort(recordList, recordList + n, cmp);

	User user;
	user.name = recordList[0].username;
	int cntUser = 0;
	userList.push_back(user);
	
	for( i = 1; i < n; ++i ){
		if( recordList[i].username == recordList[i - 1].username ){
			int bill = 0;
			int preStatus = recordList[i - 1].status;
			int nowStatus = recordList[i].status;
			if( preStatus == 1 && nowStatus == 0 ){
				// 只有这种才是有效记录
				Record st = recordList[i - 1];
				Record end = recordList[i];
				bill = getBill(st, end);
				CallRecord call(st, end, bill);
				userList[cntUser].callList.push_back(call);
			}
			userList[cntUser].totalBill += bill;
		}else{
			user.name = recordList[i].username;
			cntUser++;
			userList.push_back(user);
		}
	}

	for( i = 0; i <= cntUser; ++i ){
		if( userList[i].totalBill != 0 ){
			cout<<userList[i].name<<' ';
			cout<<setfill('0')<<setw(2)<<month<<'\n';
			vector<CallRecord> callList = userList[i].callList;
			for( j = 0; j < callList.size(); ++j ){
				getInfo(callList[j]);
			}
			cout<<"Total amount: ";
			printBill(userList[i].totalBill);
		}
	}

	return 0;
}