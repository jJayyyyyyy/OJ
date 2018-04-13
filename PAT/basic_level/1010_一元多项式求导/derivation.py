from __future__ import print_function

us_input = raw_input().split()
us_input = map(int, us_input)

length = len(us_input)

# if 0==length:
# 	print(0, 0)
# else:
is_start = 1
for i in range(0, length, 2):
	coe = us_input[i];
	exp = us_input[i+1];
	if coe and exp:
		if is_start:
			print(coe*exp, exp-1, end='')
			is_start = 0
		else:
			print('' , coe*exp, exp-1, end='')
	elif coe or exp:
		pass
	else:
		if is_start:
			print(0, 0, end='')
			is_start = 0
		else:
			print('', 0, 0, end='')

if is_start:
	print(0, 0)
