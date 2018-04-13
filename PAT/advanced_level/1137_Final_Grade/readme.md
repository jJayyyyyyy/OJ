1.	构造一个map，关键字是id，值是学生信息

	```cpp
	// map的定义/声明
	map<string, Student> mStu;
	```

2.	map中每一个元素的构造（初始化，填充）

	```cpp
	mStu[id].id = id;
	mStu[id].gOP = gOP;
	```

3.	完成输入后，把map复制到线性的vector，提高后面访问和排序的效率。

	*	注意要push_back到数组里面的元素是`mStu.second`

	```cpp
	vector<Student> stuList;
	for( auto & stu : mStu ){
		stuList.push_back(mStu.second);
	}
	```

4.	排序

	*	逆序大于，顺序小于

	```cpp
	int cmp(Student a, Student b){
		if( a.pass != b.pass ){
			return a.pass > b.pass;
		}else if( a.final != b.final ){
			return a.final > b.final;
		}else{
			return a.id < b.id;
		}
	}
	```

5.  输出格式

	测试时，会添加多余的换行符，注意去掉。

6.	其他

	使用子函数，比如`getFinal()`，可以纠正作用域手误，归属关系。

	举例：`main`里面一开始声明的`int gOP, gMid, gFinal;`，在86行开始的`计算gTotal`程序段中，变成了这样

	```cpp
	getRound(gMid * 4 + gFinal * 6); //错误
	getRound(stu.gMid * 4 + stu.gFinal * 6); //正确
	```
