1.  首先保存输入的数据，同时保存输入编号。
2.  接着按照得分对输入进行排序。排序后，更新各自排名。
3.  这样，即可简化录取规则：
    1.  如果还有名额，则按照排名，优先录取，同时更新录取名额，以及最末录取排名
    2.  如果没有名额了，但是该学生的排名与学校的最末录取排名相同，那么也录取
    3.  否则跳过

存储结构如下

```cpp
struct Student{
	int id, rank, gradeE, gradeI, gradeFinal;
	int preference[MAXPRERENCE];
	Student(){
		id = rank = gradeE = gradeI = -1;
	}
	int setter(int _id, int _gradeE, int _gradeI){
		id = _id;
		gradeE = _gradeE;
		gradeI = _gradeI;
		gradeFinal = gradeE + gradeI;
		return 0;
	}
};

struct School{
	int quota, rankLimit;
	set<int> stuID;
	School(){
		quota = rankLimit = 0;
	}
};
```

*   tip: 虽然题目说总分是按照`(GE + GI) / 2`计算，但我们可以把每个同学的`/2`都去掉，这样不会影响最后的结果，还能简化计算，减少时间。