from __future__ import print_function

def isInteger(str_num):
	if str_num[0].isdigit() or str_num[0]=='-':
		for i in str_num[1:]:
			if not i.isdigit():
				return 0
		return 1
	else:
		return 0

def isFloat(str_num):
	return str_num.count('.')==1

us_N = int(raw_input())
str_num = raw_input().split(' ')
sigma = 0.0
cnt = 0

for i in range(us_N):
	n = str_num[i]
	if isInteger(n):
		n = int(n)
		if n>=-1000 and n<=1000:
			sigma += n
			cnt += 1
			continue
	elif isFloat(n):
		n1, n2 = n.split('.')
		if len(n2)<=2:
			n = float(n)
			if n>=-1000 and n<=1000:
				sigma += n
				cnt += 1
				continue
	print("ERROR:", n, "is not a legal number")

if cnt>0:
	if cnt==1:
		print('The average of', cnt, 'number is %.2f' % sigma)
	else:
		print('The average of', cnt, 'numbers is %.2f' % (sigma/cnt))
else:
	print('The average of 0 numbers is Undefined')


'''
	# inte, flt = str(sigma/cnt).split('.')
	# if len(flt)<2:
	# 	flt += '0'
	# print('The average of', cnt, 'numbers is %s.%s' %(inte, flt[0:2]))

7
5 -3.2 aaa 9999 2.3.4 7.123 2.35

2
aaa -9999

2
0 999.99

2
0 -999.99

1
0

2
0 1000.00

1
-1000

1
12a2

2
-999.99 1000.00

2
-999.99 -1000.00





'number[s]'


'-10'.isdigit() is False
isdigit() judges str[0], that is '-'

'''
