*   这题的逻辑是大坑。。

    考试如果遇到了（>=3个标尺），先跳过，先做其他的

*   进行循环，将每个可以作为Gas Station的点作为起点srcID[i]，计算出它到每个House[j]的最短路径。

    注意，路径可以从srcID[i]出发，中间的结点不一定全是House，可以是GS的点
    
    *	然后，若srcID[i]到House[j]的最短距离minDist
        
        *   超过了service range，那就抛弃这个srcID[i]
        *   否则选取尽可能大的minDist（最近的GS，要尽可能远离House）
    
    *   若minDist相同，则选取平均路径更短的（但总体上，要使各个GS到各个House尽可能近）
    
    *   若还有重复，则输出编号小的