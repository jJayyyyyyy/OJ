from __future__ import print_function

us_input = raw_input()
length = len(us_input)

if 3==length:
	for i in range(int(us_input[0])):
		print('B', end='')
	for i in range(int(us_input[1])):
		print('S', end='')
	for i in range(int(us_input[2])):
		print(i+1, end='')
if 2==length:
	for i in range(int(us_input[0])):
		print('S', end='')
	for i in range(int(us_input[1])):
		print(i+1, end='')
if 1==length:
	for i in range(int(us_input[0])):
		print(i+1, end='')
