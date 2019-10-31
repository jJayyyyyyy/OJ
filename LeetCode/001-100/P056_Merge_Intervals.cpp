/*
https://leetcode.com/problems/merge-intervals/description/?goto=old
 
反转链表 同类题目 P056, P986

输入：一个数组 intervals, 其中每个元素 itv 都是长度为2的数组，表示区间 [a, b]
过程：对所有区间取并集
输出：输出并集

思路:
1. 先对所有区间从小到大排序
2. 然后分类讨论，如何取并集

情形1
1:    [    ]
2:    [      ]
->:   [      ]

情形2
1:    [     ]
2:      [ ]
->:   [     ]

情形3
1:    [     ]
2:      [     ]
->:   [       ]

情形4(3的特殊情况)
1:    [    ]
2:         [     ]
->:   [          ]

情形5
1:    [    ]
2:           [     ]
->:   [    ] [     ]
 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
//     std::ios::sync_with_stdio(false);
//     cin.tie(0);
//     return 0;
// } ();

class Solution {
private:
    static bool cmp(vector<int> & a, vector<int> & b){
        if ( a[0] != b[0] ) {
            return a[0] < b[0];
        }
        else {
            return a[1] < b[1];
        }
    }
public:
    vector<vector<int>> merge(vector< vector<int> > & intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector< vector<int> > ans;
        for ( vector<int> & itv : intervals ) {
            if ( ans.size() == 0 ) {
                ans.push_back(itv);
            }
            else{
                size_t len = ans.size();
                auto & last_itv = ans[len - 1];
                int & lo1 = last_itv[0];
                int & hi1 = last_itv[1];
                int & lo2 = itv[0];
                int & hi2 = itv[1];
                // 画图分类讨论
                if ( lo1 == lo2 ) {
                    hi1 = hi2;
                    // 1: [    ]
                    // 2: [      ]
                    // -> [      ]
                }
                else if ( hi1 >= lo2 && hi1 < hi2 ){
                    // 1: [    ]
                    // 2:   [     ]
                    // -> [       ]
                    hi1 = hi2;
                    // 包含以下情况
                    // 1: [    ]
                    // 2:      [     ]
                    // -> [          ]
                }
                else if ( hi1 >= lo2 && hi1 >= hi2 ) {
                    // 1: [       ]
                    // 2:   [   ]
                    // -> [       ]
                    continue;
                }
                else {
                    // hi1 < lo2
                    // 1: [    ]
                    // 2:        [     ]
                    // -> [    ] [     ]
                    // 增加一项
                    ans.push_back(itv);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> itvs = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    s.merge(itvs);
    return 0;
}
