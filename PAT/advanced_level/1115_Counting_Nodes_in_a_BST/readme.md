##  思路

1.  先建立BST，建完之后再用层序法，自上而下更新 level

2.  `levelTraverse()`，更新每个结点的level，并得到`maxLevel1`，`maxLevel2 = maxLevel1 -1`，即`the lowest 2 levels`

3.  遍历树，统计出最low的两个level的结点数

##  知识点

*   建立BST，层序遍历，前序遍历

*   N为正数，所以不会出现`N==0`

*   注意`N==1`，即只有一个结点的情况

*   除此以外的情况，都能构成至少有两层的树，所以n1和n2肯定存在
