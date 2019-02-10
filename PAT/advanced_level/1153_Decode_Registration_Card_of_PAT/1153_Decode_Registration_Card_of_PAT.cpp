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
// 思路1 重写后的代码如下
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

struct Student
{
	string id;
	int score;
	Student(string uid, int uscore)
	{
		id = uid;
		score = uscore;
	}
};

struct Site
{
	string site_id;
	int cnt_student;
	Site(string id, int cnt)
	{
		site_id = id;
		cnt_student = cnt;
	}
};

vector<Student> stu_list;

bool cmp1(Student const & s1, Student const & s2)
{
	if( s1.score != s2.score )
	{
		return s1.score > s2.score;
	}
	else
	{
		return s1.id < s2.id;
	}
}

void output1(string term)
{
	vector<Student> ans;
	for( Student stu : stu_list )
	{
		if( stu.id[0] == term[0] )
		{
			ans.push_back(stu);
		}
	}

	if( ans.size() == 0 )
	{
		cout << "NA\n";
	}
	else
	{
		sort(ans.begin(), ans.end(), cmp1);
		for( Student stu : ans )
		{
			cout << stu.id << ' ' << stu.score << '\n';
		}
	}
}

void output2(string term)
{
	int cnt_student = 0;
	int sum = 0;

	for( Student stu : stu_list )
	{
		string site_id = stu.id.substr(1, 3);
		if( site_id == term )
		{
			cnt_student++;
			sum += stu.score;
		}
	}

	if( cnt_student == 0 )
	{
		cout << "NA\n";
	}
	else
	{
		cout << cnt_student << ' ' << sum << '\n';
	}
}

bool cmp2(Site & s1, Site & s2)
{
	if( s1.cnt_student != s2.cnt_student )
	{
		return s1.cnt_student > s2.cnt_student;
	}
	else
	{
		return s1.site_id < s2.site_id;
	}
}

void output3(string term)
{
	unordered_map<string, int> site_map;
	for( Student stu : stu_list )
	{
		string date = stu.id.substr(4, 6);
		if( date == term )
		{
			string site_id = stu.id.substr(1, 3);
			site_map[site_id]++;
		}
	}

	vector<Site> ans;
	for( auto item : site_map )
	{
		ans.push_back(Site(item.first, item.second));
	}

	if( ans.size() == 0 )
	{
		cout << "NA\n";
	}
	else
	{
		sort(ans.begin(), ans.end(), cmp2);
		for( Site site : ans )
		{
			cout << site.site_id << ' ' << site.cnt_student << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	string id;
	int score;
	for( int i = 0; i < n; i++ )
	{
		cin >> id >> score;
		stu_list.push_back( Student(id, score) );
	}

	for( int i = 1; i <= m; i++ )
	{
		int type;
		string term;
		cin >> type >> term;
		cout << "Case " << i << ": " << type << ' ' << term << '\n';
		if( type == 1 )
		{
			output1(term);
		}
		else if( type == 2 )
		{
			output2(term);
		}
		else if( type == 3 )
		{
			output3(term);
		}
	}
	return 0;
}




// 2. 我的思路, 原以为思路 1 会超时, 所以在输入的时候就对数据进行了分类
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


