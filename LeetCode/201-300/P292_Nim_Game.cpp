/*
https://leetcode.com/problems/nim-game/description/
博弈游戏之Nim游戏，一堆石子，每人每次只能拿1~3颗，谁拿到最后一颗石子就是胜者。给定石子总数n，你是先手，判断能否必胜
同类题目 P292

参考：
https://leetcode.com/problems/nim-game/solution/
https://baike.baidu.com/item/Nim%E6%B8%B8%E6%88%8F/6737105?fr=aladdin

一开始想的是用递归，不过根据参考答案以及下面的ps2，应该先考虑一下数字规律，说不定有更好更快的方法
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		return (n&3);
	}
};


/*
ps1:

判断一个正整数数能否被4整除
https://leetcode.com/problems/nim-game/solution/
@yake

return(n&3)





ps2:

判断一个正整数数能否被7整除
http://cache.baiducontent.com/c?m=9f65cb4a8c8507ed4fece7631046893b4c4380147d8c8c4668d4e419ce3b4c413037bfa6663f405a8e906b6075a91e0feba13273660123b59897ca19dfac925f75ce786a6459db0144dc0edfcf5151b637912afedf6ff0cefa25e5aac5a2db4353bb4475799780fb4d0164cf78f1642695a18e3c654860bbfa4413&p=882a940e80991fbe1dbe9b7c44&newp=98769a47879c0ef408e2952a1e53d8224216ed673dc3864e1290c408d23f061d4862e4be20201607d6c4766103ad435be0f23c7123454df6cc8a871d81edc37760d3&user=baidu&fm=sc&query=%B6%FE%BD%F8%D6%C6+%B1%BB7%D5%FB%B3%FD&qid=daefae780002dc75&p1=1

用周期问题的处理方法可以解决这个问题
2的连续次方（2，2个2次方，2的3次方，2的4次方，2的5次方，2的6次方......),除以7的余数是:
2,4,1,2,4,1......循环,每周期3个
18÷3=6周期
那2的18次方除以7的余数就是1
2的18次方减去1就能被7整除。

 
用二进制的方法也可以解决这个问题：

2的18次方，用二进制表示就是1个2，后面18个0，

2的18次方减1，就是18个1，

7用二进制表示是111，

18个1，可以被111整除，所以
2的18次方减去1就能被7整除。


*/