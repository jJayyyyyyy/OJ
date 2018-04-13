1.  先录入全部数据, 得到 raw_list

2.  如果起点下标大于总人数

    ```cpp
    if( start > total ){
        cout<<"Keep going...\n";
        return 0;
    }
    ```

3.  否则，按照规则，把得奖者加入 winner_list, 和 winner_set，后者用于去重

4.  输出 winner_list

5.  PS: set的用法

    ```cpp
    set<string> winner_set;

    winner_set.insert(name); // 插入

    if( winner_set.find(name) == winner_set.end() ){
        // 如果这个名字还不是得奖者
    }
    ```