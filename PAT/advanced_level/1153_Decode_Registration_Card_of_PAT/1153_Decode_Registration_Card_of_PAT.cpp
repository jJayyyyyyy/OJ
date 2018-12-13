/*
https://pintia.cn/problem-sets/994805342720868352/problems/1071785190929788928
考察数据结构以及 STL 的使用
题目本身不难, 但是逻辑很繁杂

case 1: 输出某个 level 的参赛者的 id 和 score
        按照 score 降序, 如果 score 相同, 则按照 id 升序
case 2: 输出某个 site 的参赛者的总人数和总成绩
case 3: 输出某个 date 下, 每个 site 的总人数
        按照人数降序, 如果人数相同, 则按照 site 升序

*/


// 两种解题思路
// https://www.liuchuo.net/archives/8023
// 1. 柳神的题解, 时间换空间, 也就是先读取所有输入到vector
//    然后, 根据不同的query, 重新进行排序
//    耗时多(143ms), 空间少(3236KB)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct stu {
	string id;
	int sco;
};
struct site {
	string siteId;
	int cnt;
};
bool cmp1(const stu &a, const stu &b) {
	return a.sco == b.sco ? a.id < b.id : a.sco > b.sco;
}
bool cmp2(const site &a, const site &b) {
	return a.cnt == b.cnt ? a.siteId < b.siteId : a.cnt > b.cnt;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<stu> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].id >> v[i].sco;
	for (int i = 1; i <= k; i++) {
		int num;
		scanf("%d", &num);
		if (num == 1) {
			string level;
			cin >> level;
			printf("Case %d: %d %s\n", i, num, level.c_str());
			vector<stu> ans;
			for (int i = 0; i < n; i++) {
				if (v[i].id[0] == level[0])
					ans.push_back(v[i]);
			}
			sort(ans.begin(), ans.end(),cmp1);
			for (int i = 0; i < ans.size(); i++)
				printf("%s %d\n", ans[i].id.c_str(), ans[i].sco);
			if (ans.size() == 0) printf("NA\n");
		} else if (num == 2) {
			int cnt = 0, sum = 0;
			int siteId;
			cin >> siteId;
			printf("Case %d: %d %d\n", i, num, siteId);
			vector<stu> ans;
			for (int i = 0; i < n; i++) {
				if (v[i].id.substr(1, 3) == to_string(siteId)) {
					cnt++;
					sum += v[i].sco;
				}
			}
			if (cnt != 0) printf("%d %d\n", cnt, sum);
			else printf("NA\n");
		} else if (num == 3) {
			string date;
			cin >> date;
			printf("Case %d: %d %s\n", i, num, date.c_str());
			vector<site> ans;
			unordered_map<string, int> m;
			for (int i = 0; i < n; i++) {
				if (v[i].id.substr(4, 6) == date) {
					string tt = v[i].id.substr(1, 3);
					m[tt]++;
				}
			}
			for (auto it : m)
				ans.push_back({it.first, it.second});
			sort(ans.begin(), ans.end(),cmp2);
			for (int i = 0; i < ans.size(); i++)
				printf("%s %d\n", ans[i].siteId.c_str(), ans[i].cnt);
			if (ans.size() == 0) printf("NA\n");
		}
	}
	return 0;
}

// 2. 我的, 我想多了, 以为会超时, 所以在输入的时候就对数据进行了分类
//    一次整理, 多次重用
//    耗时少(77ms), 空间多(7416KB)


#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

struct Testee{
	string mID, mSite, mDate, mNum;
	char mLevel;
	int mScore;

	Testee(string id, int score){
		mID = id;
		mScore = score;
		mLevel = mID[0];
		mSite = mID.substr(1, 3);
		mDate = mID.substr(4, 6);
		mNum = mID.substr(11, 3);
	}

	bool operator < (const Testee & a) const {
		if( mScore != a.mScore ){
			return mScore > a.mScore;
		}else{
			return mID < a.mID;
		}
	}
};

struct SiteCnt{
	int cntPerson;
	int cntScore;
	SiteCnt(){
		cntPerson = cntScore = 0;
	}
};

struct DateSiteCnt{
	string site;
	int cntPerson;

	DateSiteCnt(string s, int c){
		site = s;
		cntPerson = c;
	}

	bool operator < (const DateSiteCnt & a) const {
		if( cntPerson != a.cntPerson ){
			return cntPerson > a.cntPerson;
		}else{
			return site < a.site;
		}
	}
};

unordered_map<char, set<Testee> > levelMap;
unordered_map<string, SiteCnt> siteMap;
unordered_map<string, unordered_map<string, int> > dateSiteMap;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin>>n>>m;
	string id;
	int score;
	for( int i = 0; i < n; i++ ){
		cin>>id>>score;
		Testee testee(id, score);
		char level = testee.mLevel;
		string site = testee.mSite;
		string date = testee.mDate;
		string num = testee.mNum;
		levelMap[level].insert(testee);
		
		siteMap[site].cntPerson++;
		siteMap[site].cntScore += score;

		dateSiteMap[date][site]++;
	}
	
	int type;
	string term;
	for( int i = 1; i <= m; i++ ){
		cin>>type>>term;
		if( type == 1 ){
			cout<<"Case "<<i<<": "<<type<<' '<<term<<'\n';
			char level = term[0];
			set<Testee> s = levelMap[level];
			if( s.size() == 0 ){
				cout<<"NA\n";
			}else{
				for( auto it : s ){
					cout<<it.mID<<' '<<it.mScore<<'\n';
				}
			}
		}
		else if( type == 2 ){
			cout<<"Case "<<i<<": "<<type<<' '<<term<<'\n';
			string site = term;
			SiteCnt siteCnt = siteMap[site];
			if( siteCnt.cntPerson == 0 ){
				cout<<"NA\n";
			}else{
				cout<<siteCnt.cntPerson<<' '<<siteCnt.cntScore<<'\n';
			}
		}
		else{
			cout<<"Case "<<i<<": "<<type<<' '<<term<<'\n';
			string date = term;

			unordered_map<string, int> m = dateSiteMap[date];
			int len = m.size();
			if( len == 0 ){
				cout<<"NA\n";
			}else{
				vector<DateSiteCnt> v;
				for( auto it : m ){
					v.push_back(DateSiteCnt(it.first, it.second));
				}
				sort(v.begin(), v.end());
				for( int i = 0; i < len; i++ ){
					DateSiteCnt item = v[i];
					cout<<item.site<<' '<<item.cntPerson<<'\n';
				}
			}
		}
	}

	return 0;
}
