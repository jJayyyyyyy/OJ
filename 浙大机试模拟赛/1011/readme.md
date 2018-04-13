*   [万妖穴](https://logn.me/problem/1011)

*   本题考察拓扑排序

*   如果存在多个入度为0的顶点，则先访问序号较小的顶点

    此时可以使用 set, 或者使用 priority_queue. 对于本题的测试用例，两者耗费时间差不多。
    
    不过用 set 更加简洁顺手
    
*   模版

    ```
    #include <iostream>
    #include <vector>
    #include <set>
    #define MAXSIZE 1004
    using namespace std;
    
    vector<int> G[MAXSIZE], ansList;    // G是邻接表
    int inDegree[MAXSIZE] = {0};    // 入度表
    int n, m, cnt=0;
    
    bool isTopo(){
    	set<int> s;
    
    	for( int i = 0; i < n; i++ ){
    		if( inDegree[i] == 0 ){
    			s.insert(i);        // 先访问序号较小的
    		}
    	}
    
    	while( s.size() ){
    		int now = *s.begin();
    		ansList.push_back(now);
    		s.erase(now);
    		
    		for( auto next : G[now] ){
    			inDegree[next]--;
    			if( inDegree[next] == 0 ){
    				s.insert(next);
    			}
    		}
    		G[now].clear();
    		cnt++;
    	}
    	return cnt == n;
    }
    
    int main(){
    	ios::sync_with_stdio(false);
    	cin.tie(0);

    	cin>>n>>m;
    	int v1, v2;
    
    	for( int i = 0; i < m; i++ ){
    		cin>>v1>>v2;
    		G[v1].push_back(v2);
    		inDegree[v2]++;
    	}
    
    	if( isTopo() ){
    		cout<<"YES\n";
    		// print ansList
    	}else{
    		cout<<"NO\n";
    		cout<<(n - cnt)<<'\n';
    	}

    	return 0;
    }
    ```


