from __future__ import print_function

units = ['', 'jan', 'feb', 'mar', 'apr', 'may', 'jun', 'jly', 'aug', 'sep', 'oct', 'nov', 'dec']
tens = ['tret', 'tam', 'hel', 'maa', 'huh', 'tou', 'kes', 'hei', 'elo', 'syy', 'lok', 'mer', 'jou']

def cnv13to10(num):
	l = len(num)
	if l==3:
		for i in range(1, 13):
			if tens[i]==num:
				print(i*13)
				return 0
			elif units[i]==num:
				print(i)
				return 0
			else:
				continue
	elif l==4:
		print(0)
	else:
		sigma = 0
		n1, n2 = num.split(' ')
		for i in range(1, 13):
			if tens[i]==n1:
				sigma = i*13
				break
		for i in range(1, 13):
			if units[i]==n2:
				sigma += i
				break
		print(sigma)
	return 0

def cnv10to13(num):
	num = int(num)
	remain = num % 13
	quotient = num / 13
	if remain==0:
		print(tens[quotient])
	elif quotient==0:
		print(units[remain])
	else:
		print(tens[quotient], units[remain])
	return 0

us_N = raw_input()
for i in range( int(us_N) ):
	num = raw_input()
	if num[0].isdigit():
		cnv10to13(num)
	else:
		cnv13to10(num)


# 10:52 ~ 11:26
# 34min
