1.  按照题意，用long long，只能拿到18分，剩下的输入，经过运算后会溢出2^64

2.  换用大整数加法

3.  <algorithm>中有一个[reverse()](http://www.cplusplus.com/reference/algorithm/reverse/?kw=reverse)

    用法
    
    ```cpp
    vector<int> v;
    reverse( v.begin(), v.end() );  //直接对v进行反转，而不是返回一个copy
    ```
    
4.  对于这种题意清晰又很简单的题目(主要是不会超时)，可以试试python，因为python会帮忙解决整数溢出的问题。

