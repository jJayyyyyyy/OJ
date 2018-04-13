这是一篇草稿。

##  tag: string

##  灵活使用string对象的各种member function

```cpp
string zero(3, '0');    // 构造函数, "000"

string s="01234.678";
string s1;
s1 = s.substr(3);       // "34.678"
s1 = s.substr(3, 2);    // "34"

// s.erase(pos, len);   //前闭后开
// s.erase(pos);
s.erase(0, 4);          // "4.678";


// insert before ...
// s.insert(pos, n, ch);
// s.insert(pos, str);
s.insert(s.size(), 3, '0');     // "4.678000"
s.insert(0, "123");             // "1234.678"


// s.find
s = "0012.300"
s.find('2');                     // 3
s.find_first_not_of('0');        // 2
s.find_last_not_of('0');         // 5

```
