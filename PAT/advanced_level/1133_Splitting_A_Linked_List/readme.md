1.  先保存所有节点

2.  各自归类（负数，介于[0, k]的数，大于k的数）

3.  三类连成串（方便输出格式）

*   case4，并不是所有节点都能连成一个list，坑爹。所以步骤2用 `while( addr != -1 )` 进行循环

##	链表，根据起点和终点，找出真正的单链表，重新排序

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

