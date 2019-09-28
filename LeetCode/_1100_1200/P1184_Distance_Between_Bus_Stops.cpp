/*
https://leetcode.com/problems/distance-between-bus-stops/description/?goto=old

输入1：距离向量 distance[], 其中 distance[i] 表示点 i 到 点 i+1 的顺时针距离；
输入2：起点
输入3：终点
输出：输出起点到终点的最短距离
注：题目保证只有一个环

同类题目 P1184

思路1
首先遍历 distance，累加得出总的一圈下来有多长 ttl_dist
同时新开一个数组 dist_from_0[n], 每经过一个点 i 都加上 distance[i]
这样就得到了总路程的长度 ttl_dist
以及每一个点到 0 点的距离（从而可以求出两点之间的顺时针距离）
最短距离要么是顺时针距离，要么是逆时针距离

dist = abs(dist_from_0[end] - dist_from_0[start])
min_dist = min(dist, ttl_dist - dist)

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int> & distance, int start, int destination) {
        int size = distance.size();
        int ttl_dist = 0;
        vector<int> clockwise_dist_from_0(size + 1, 0);

        for ( int i = 0; i < size; i++ ){
            ttl_dist += distance[i];
            clockwise_dist_from_0[i + 1] = ttl_dist;
        }
        int dist = abs(clockwise_dist_from_0[destination] - clockwise_dist_from_0[start]);
        int min_dist = min(dist, ttl_dist - dist);
        return min_dist;
    }
};

int main(){
    vector<int> arr = {1, 2, 3, 4};
    int start = 0, destination = 3;
    Solution s;
    cout << s.distanceBetweenBusStops(arr, start, destination) << '\n';
    return 0;
}