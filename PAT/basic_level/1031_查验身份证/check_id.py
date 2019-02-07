from __future__ import print_function

weight = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
match_ZM = ['1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2']

all_passed = 1
n = int( raw_input() )
for i in range(n):
	identity = raw_input()
	sigma = 0
	valid = 1
	for j in range(17):
		if not identity[j].isdigit():
			valid = 0
			break
		sigma += weight[j] * int(identity[j])
	sigma = sigma % 11
	if match_ZM[sigma] != identity[17]:
		valid = 0
	if not valid:
		print(identity)
		all_passed = 0

if all_passed:
	print('All passed')


'''
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X


2
320124198808240056
110108196711301862


5
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
320124198808240056



'''
