1.	构造一个map，关键字是id，值是学生信息

```cpp
struct Student{
	string id;
	int g0, g1, g2, final, pass;
	Student(){
		g0 = g1 = g2 = final = pass = -1;
	}
};

map<string, Student> m;
```

2.	输入学生信息

3.	完成输入后，把map复制到一个数组

4.	对数组按照成绩进行排序

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

sort(stuList.begin(), stuList.end(), cmp);
```

5.	输出结果

<br>

PS:	策略

先看乙级题目，有1~2个和甲级题目一样的，但是用的中文描述。

可以先做这个，省得阅读理解。
