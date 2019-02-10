##	链表，根据起点和终点，找出真正的单链表，重新排序

*	思路

	*	不要把所有逻辑都混在在输入输出上
	*	先读取输入，得到 `raw_list`
	*	对输入进行过滤，得到真正的 `linked_list`, 
	*	接着归类到不同的 `list`，比如 1133 的 `before, mid, after`，或者可能要插入 `set` 去重
	*	然后从 `list/set` 迁移到得到真正的 ans_list，它是线性的，方便输出
	*	按照格式输出，补零，或者[0, n-1), 再来末尾节点的 -1

1.	数据结构

	```cpp
	// addr val next
	// 00100 2 12345

	#define MAXSIZE 100004
	struct Node{
		int addr, val, next;
		Node(){}			// 用于数组初始化
		Node(int a, int v, int n){
			addr = a;
			val = v;
			next = n;
		}
	}

	Node raw_list[MAXSIZE];		// 地址不仅保存在数组下标，还要保存在结构体中，即node.addr
	```

1.	读入全部节点，保存到raw_list

2.	找到主线linked_list

	有的case，其输入可能会串成多条链，因此需要找到主线 `start ---> ... ---> -1`

	```cpp
	addr = start;
	while(addr != -1){
		Node node = raw_list[addr];
		linked_list.push_back(node);
		addr = node.next;
	}
	```

3.	按要求进行排序或者分类

	*	排序

		```cpp
		sort(linked_list.begin(), linked_list.end(), cmp)
		```

	*	分类(1133)

		```cpp
		for( auto & node : linked_list ){
			val = node.val;
			if( node.val < 0 ){
				before.push_back(node);
			}else if( node.val <= k ){
				mid.push_back(node);
			}else{
				after.push_back(node);
			}
		}
		```

		重新连接

		```cpp
		for( auto & node : before ){
			ans.push_back(node);
		}
		for( auto & node : mid ){
			ans.push_back(node);
		}
		for( auto & node : after ){
			ans.push_back(node);
		}
		```

4.	输出

	*	最后一个节点单独处理

		```cpp
		int len = ans.size();
		for( i = 0; i < len - 1; i++ ){
			// ans[i].addr
			// ans[i].val
			// ans[i+1].addr  注意是i+1
		}
		```

	*	输出格式（补0）

		```cpp
		#include <iomanip>
		void disp_addr(int addr){
			cout<<setw(5)<<setfill('0')<<addr;
		}
		```
