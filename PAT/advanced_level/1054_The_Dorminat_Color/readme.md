##	[原题](https://www.patest.cn/contests/pat-a-practise/1054)：1054. The Dominant Color (20)

Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color. A *strictly* dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800x600), you are supposed to point out the strictly dominant color.

###	Input Specification

Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (<=800) and N (<=600) which are the resolutions of the image. Then N lines follow, each contains M digital colors in the range [0, 2<sup>24</sup>). It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.

###	Output Specification

For each test case, simply print the dominant color in a line.

###	Sample Input

	5 3
    0 0 255 16777215 24
    24 24 0 0 24
    24 0 24 24 24

###	Sample Output

	24

###	注意

	时间限制： 100 ms
	内存限制： 65536 kB
	代码长度限制： 16000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	使用`STL`中的`map`

    `map`中的key是输入的color, value是出现次数。
	
    ```cpp
    #include <map>
    using namespace std;
    //...
    
    map<int, int> colorMap;
    map<int, int>::iterator it;
    ```
	
2.  输入与存储

    若已收入`colorMap`则该项的value++，否则向`colorMap`添加新的项:
    
    ```cpp
    cin>>color;
    if( colorMap.find(color)!=colorMap.end() ){
        colorMap[color]++;
    }else{
        colorMap[color] = 1;
    }
    ```

3.  输出

    注意到题目可以保证有一个**strictly dominant color**，由此可以推出有且仅有一个**strictly dominant color**。所以遍历`colorMap`时，只要发现value大于总像素点数量一半，即可确定输出该点。
    
    ```cpp
    int maxCnt=m*n/2;
	for( it=colorMap.begin(); it!=colorMap.end(); it++){
		if( it->second >maxCnt ){
			cout<<it->first;
			break;
		}
	}
    ```

4.  注意

    测试点2数据量很大，为避免超时，需要加上这么两行，屏蔽cin/cout的许多特性以换取时间:
    
    ```cpp
    ios::sync_with_stdio(false);
	cin.tie(0);
    ```

#	部分测试用例

同输入样例

#	其他参考

*   晴神宝典

*   同类题目互联

    [PAT_A_1054](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1054_The_Dorminat_Color)  
    [PAT_A_1071](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1071_Speech_Patterns)  
    [PAT_A_1022](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1022_Digital_Library)  

*	// TODO 更多同类题目互联