*   寻找最长的对称子串。

*   固定下标，然后逐步对比两边字符是否相同

*   分两种情况，字符串长度为

    *   偶数    s[i - offset] != s[i + offset + 1]
    *   奇数    s[i - offset] != s[i + offset]
