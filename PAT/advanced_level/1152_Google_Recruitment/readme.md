##	1152 Google Recruitment(20)

In July 2004, Google posted on a giant billboard along Highway 101 in Silicon Valley (shown in the picture below) for recruitment. The content is super-simple, a URL consisting of the first 10-digit prime found in consecutive digits of the natural constant e. The person who could find this prime number could go to the next step in Google's hiring process by visiting this website.

![google](https://github.com/jJayyyyyyy/OJ/blob/master/advanced_level/1152_Google_Recruitment/assets/google.jpg)

The natural constant e is a well known transcendental number（超越数）. The first several digits are: e = 2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427427466391932003059921... where the 10 digits in bold are the answer to Google's question.

Now you are asked to solve a more general problem: find the first K-digit prime in consecutive digits of any given L-digit number.

<br>

##	Input Specification:

Each input file contains one test case. Each case first gives in a line two positive integers: L (≤ 1,000) and K (< 10), which are the numbers of digits of the given number and the prime to be found, respectively. Then the L-digit number N is given in the next line.

<br>

##	Output Specification:

For each test case, print in a line the first K-digit prime in consecutive digits of N. If such a number does not exist, output 404 instead. Note: the leading zeroes must also be counted as part of the K digits. For example, to find the 4-digit prime in 200236, 0023 is a solution. However the first digit 2 must not be treated as a solution 0002 since the leading zeroes are not in the original number.

<br>

##	Sample Input1:

```
20 5
23654987725541023819
```

<br>

##	Sample Output1:

```
49877
```

<br>

##	Sample Input2:

```
10 3
2468024680
```

<br>

##	Sample Output1:

```
404
```

<br>

##	Info

```
作者: 陈越
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB
```
