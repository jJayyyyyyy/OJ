##	[原题](https://www.patest.cn/contests/pat-b-practise/1051)： 1051. 复数乘法 (15)

复数可以写成(A + B**i**)的常规形式，其中A是实部，B是虚部，**i**是虚数单位，满足**i**<sup>2</sup> = -1；也可以写成极坐标下的指数形式(R×e<sup>(P<b>i</b>)</sup>)，其中R是复数模，P是辐角，**i**是虚数单位，其等价于三角形式(R(cos(P) + **i**sin(P))。

现给定两个复数的R和P，要求输出两数乘积的常规形式。

###	输入格式

输入在一行中依次给出两个复数的R1, P1, R2, P2，数字间以空格分隔。

###	输出格式

在一行中按照“A+Bi”的格式输出两数乘积的常规形式，实部和虚部均保留2位小数。注意：如果B是负数，则应该写成“A-|B|i”的形式。

###	输入样例

	2.3 3.5 5.2 0.4

###	输出样例

	-8.68-8.23i

###	注意

	时间限制： 400ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

基于python

1.	构造复数对象

	直角坐标系

	```python
	z1 = 1 + 1j
	z2 = cmath.rect(r, phi)	#两个参数是极坐标系下的半径和相位角
	```

	极坐标系

	```python
	z3 = cmath.polar(z1)
	z4 = cmath.polar(z2)
	```

2.	只读属性

	对于一个复数complex对象`z`，可以读取其实部和虚部

	```python
	real = z.real
	img = z.imag
	```

	这两个属性是只读的，对其进行写操作会报错

	```python
	Traceback (most recent call last):
	  File "complex_number.py", line 28, in <module>
		z3.imag=0
	TypeError: readonly attribute
	```

3.	`-0.0`与`0`

	当我们在交互式环境下分别输入 `-0`和`-0.0`

	```python
	>>> -0
	0
	>>> -0.0
	-0.0	#...负号
	>>> -0.1*0
	-0.0	#...负号
	>>> -0.1*0.0
	-0.0	#...负号
	>>> -0.0==0
	True
	```

	原因在于，十进制下的很多小数无法用二进制准确地表示，因此float本身就不是完全准确的（精度越高越接近）。这在我们打印符号的时候会造成一定麻烦（本题至少有1个测试点与此相关）。

	```python
	r1, p1, r2, p2 = map(float, raw_input().split())
	img = r1*r2*math.sin(p1+p2)
	real=r1*r2*math.cos(p1+p2)

	if img<0:
		print('%.2f-%.2fi' % (real, abs(img)))
	else:
		print('%.2f+%.2fi' % (real, img))
	```

	我们要做的是把`-0.0`的负号去掉。

	```python
	# 四舍五入保留两位的方法
	if abs(real)<0.005:
		real=0
	if abs(img)<0.005:
		img=0

	# 直接截取两位小数
	if abs(real)<0.01:
		real=0
	if abs(img)<0.01:
		img=0
	```

	题目没有明确说明是四舍五入还是截取，两种方式都能AC，看来是没有考核四舍五入的问题，只看-0.0的负号有没有去掉

	如果真的要进行四舍五入，可以+50再取整，参考[1026\_程序运行时间](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1026_%E7%A8%8B%E5%BA%8F%E8%BF%90%E8%A1%8C%E6%97%B6%E9%97%B4)

基于c++

1.  库

    根据题意，需要引入`<complex>`和`<cmath>`

2.  复数对象

    构造对象
    
    ```cpp
    double r1=2.3, p1=3.5;
    double real1 = r1 * cos(p1);
    double imag1 = r1 * sin(p1);
    complex<double> a(real1, imag1);
    ```

    获取实部和虚部

    ```cpp
    double real = a.real();
    double imag = a.imag();
    ```

3.  去掉`-0.0`

    ```cpp
    if( fabs(imag)<0.01 )
        imag = 0;
    if( fabs(real)<0.01 )
        real = 0;
    ```

#	部分测试用例

1.	test1

		输入
		2.3 3.5 5.2 0.4

		输出
		-8.68-8.23i

2.	test2

		输入
		0 0 0 0

		输出
		0.00+0.00i

3.	test3

		输入
		0.001 -0.001 1 0

		输出
		0.00+0.00i

#	其他参考

*	[Python Docs: cmath](https://docs.python.org/3/library/cmath.html#module-cmath)

*	[Python Docs: round](https://docs.python.org/3/library/functions.html#round)

*	[Android\_chunhui: PAT\_1051](http://blog.csdn.net/android_chunhui/article/details/53509348)

*   [cplusplus](http://www.cplusplus.com/reference/complex/complex/)

<!-- [](http://stackoverflow.com/questions/24497316/set-a-read-only-attribute-in-python) -->

<!-- -8.68215035823-8.22568326384j -->
