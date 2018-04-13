#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#define MAXRECORDS 10004
using namespace std;

int getSeconds(const string &_time){
	int h = stoi(_time.substr(0, 2));
	int m = stoi(_time.substr(3, 2));
	int s = stoi(_time.substr(6, 2));
	return 3600*h + 60*m + s;
}

int getFormattedTime(int second){
	int h = second / 3600;
	second -= h*3600;
	int m = second / 60;
	second -= m*60;
	int s = second;

	cout<<setfill('0')<<setw(2)<<h<<':';
	cout<<setfill('0')<<setw(2)<<m<<':';
	cout<<setfill('0')<<setw(2)<<s<<'\n';
	return 0;
}

struct Record{
	string id;
	int time, status;
	Record(string _id, string _time, string _status){
		id = _id;
		time = getSeconds(_time);
		status = (_status=="in") ? 1 : -1;
	}
};

vector<Record> allRecords, validRecords;
vector<int> cntCurCars(MAXRECORDS);
map<string, int> parkTime;
map<string, int>::iterator it;

int cmp1(const Record &r1, const Record &r2){
	if( r1.id != r2.id ){
		return r1.id < r2.id;
	}else{
		return r1.time < r2.time;
	}
}

int cmp2(const Record &r1, const Record &r2){
	return r1.time < r2.time;
}

int show(vector<Record> &records){
	cout<<'\n';
	vector<Record>::iterator it;
	for( it=records.begin(); it!=records.end(); it++ ){
		cout<< it->id <<' '<< it->time <<' '<< it->status <<'\n';
	}
	cout<<'\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k, i;
	int maxTime = 0;
	string id, time, status;

	cin>>n>>k;

	for( i=0; i<n; i++ ){
		cin>>id>>time>>status;
		Record rcd(id, time, status);
		allRecords.push_back(rcd);
	}

	sort(allRecords.begin(), allRecords.end(), cmp1);

	for( i=0; i<n-1; i++){
		if( allRecords[i].id == allRecords[i+1].id && allRecords[i].status == 1 && allRecords[i+1].status == -1 ){
			validRecords.push_back(allRecords[i]);
			validRecords.push_back(allRecords[i+1]);
			
			parkTime[allRecords[i].id] += ( allRecords[i+1].time - allRecords[i].time );
			if( maxTime < parkTime[ allRecords[i].id ] ){
				maxTime = parkTime[ allRecords[i].id ];
			}
		}
	}

	sort(validRecords.begin(), validRecords.end(), cmp2);

	cntCurCars[0] = validRecords[0].status;
	for( i=1; i<validRecords.size(); i++ ){
		// in means +1, out means -1
		cntCurCars[i] = cntCurCars[i-1] + validRecords[i].status;
	}

	string query;
	int queryTime, j, preRcd = 0;
	for( i=0; i<k; i++ ){
		cin>>query;
		queryTime = getSeconds(query);
		for( j=preRcd; j<validRecords.size(); j++ ){
			if( queryTime < validRecords[j].time ){
				cout<<cntCurCars[j-1]<<'\n';
				break;
			}else if( j == validRecords.size() - 1 ){
				cout<<cntCurCars[j]<<'\n';
			}
		}
		preRcd = j;
	}

	for( it=parkTime.begin(); it!=parkTime.end(); it++ ){
		if( it->second == maxTime ){
			cout<< it->first <<' ';
		}
	}
	getFormattedTime(maxTime);
	return 0;
}
