#include <iostream>
#include <set>
#define MAXSIZE 50004
using namespace std;

struct Item{
	int id, cnt;
	Item(int _id, int _cnt){
		id = _id;
		cnt = _cnt;
	}
	// 第一个const，表示函数不可修改成员变量。
	// 第二个const，我们在给sort写cmp的时候，如果用了引用&参数，那么cmp的形参表也是要加const的。或者形参表的 const 和 & 同时去掉，也可以编译。
	bool operator < (const Item & a) const {
		if( cnt != a.cnt ){
			return cnt > a.cnt;
		}else{
			return id < a.id;
		}
	}
};

set<Item> s;
// cnt_list[i] 表示id为i的商品，被用户点过的次数
int cnt_list[MAXSIZE] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int total, max_show, id;
	cin>>total>>max_show;
	for( int i = 0; i < total; ++i ){
		cin>>id;
		if( i != 0 ){
			cout<<id<<":";
			int j = 0;
			for( auto it = s.begin(); it != s.end() && j < max_show; ++it, ++j ){
				cout<<' '<<it->id;
			}
			cout<<'\n';
		}
		// 更新 recommendation set
		// 先erase，再insert
		Item item_old(id, cnt_list[id]);
		auto it = s.find(item_old);		// 使用auto类型代替 set<Item>::iterator，更加简洁
		if( it != s.end() ){
			s.erase(it);
		}
		// 更新这个 id 的点击次数
		cnt_list[id]++;
		Item item_new(id, cnt_list[id]);
		s.insert(item_new);
	}
	return 0;
}