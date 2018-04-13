##	重载overload

参考了几位博主的代码，总结下来，要使本题代码优雅简练，需要学习C++的重载。也就是在Item中定义比较运算符 `<`，以便set进行比较排序

```cpp
#include <set>
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

s.insert(Item(id, cnt) );
```

##	参考

1.	思路

	*	https://github.com/liuchuo/PAT/blob/master/PAT%E7%94%B2%E7%BA%A7(Advanced%20Level)/1129.%20Recommendation%20System%20(25)%20.cpp
	*	http://blog.csdn.net/shepherd2010/article/details/72855719
	*	https://www.joyhwong.com/archives/1121

2.	auto类型

	*	http://www.cplusplus.com/forum/general/103388/

3.	const

	*	http://blog.csdn.net/turinglife/article/details/7275884
	*	https://stackoverflow.com/questions/4600295/what-is-the-meaning-of-operator-bool-const
	*	http://blog.csdn.net/yjh0628/article/details/5830153