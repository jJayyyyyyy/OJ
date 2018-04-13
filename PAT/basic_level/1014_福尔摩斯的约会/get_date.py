from __future__ import print_function

def is_day(s):
	return s>='A' and s<='G'

def is_hour(s):
	return ( (s>='A' and s<='N') or s.isdigit() )

us_str, length, cnt = [0]*4, [0]*4, 0
day = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']

for i in range(4):
	us_str[i] = raw_input()
	length[i] = len(us_str[i])

length[0] = min(length[0], length[1])
length[2] = min(length[2], length[3])

for i in range(length[0]):
	if is_day( us_str[0][i] ):
		if is_day( us_str[1][i] ):
			if us_str[0][i] == us_str[1][i]:
				print( day[ord(us_str[0][i])-ord('A')], '', end='' )
				cnt = i + 1
				break

for i in range(cnt, length[0]):
	if is_hour( us_str[0][i] ):
		if is_hour( us_str[1][i] ):
			if us_str[0][i] == us_str[1][i]:
				if us_str[0][i]>=0 and us_str[0][i]<=9:
					print( '0'+us_str[0][i], end='' )
				else:
					print( ord(us_str[0][i])-ord('A')+10, end='' )
				break

print(':', end='')

for i in range(length[2]):
	if us_str[2][i].isalpha():
		if us_str[2][i]==us_str[3][i]:
			if i<10:
				print('0', end='')
			print(i, end='')
			break


'''
3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm

str.isalpha()
str.islower()
str.lower()
str.isupper()
str.upper()
str.isalnum()
str.isdigit()

'''
