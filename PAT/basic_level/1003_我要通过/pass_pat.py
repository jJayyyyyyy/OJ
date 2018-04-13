from __future__ import print_function

def correct_cnt(us_str):
	cnt_p, cnt_a, cnt_t = 0, 0, 0

	for i in range( len(us_str) ):
		if us_str[i]=='P':
			cnt_p += 1
			posi_p = i
		elif us_str[i]=='A':
			cnt_a += 1
		elif us_str[i]=='T':
			cnt_t += 1
			posi_t = i
		else:
			return False

	if 1!=cnt_p:
		return False
	elif 0==cnt_a:
		return False
	elif 1!=cnt_t:
		return False
	else:
		return True

def correct_order(us_str):
	return (us_str.find('P')+1) < us_str.find('T')

def correct_logic(us_str):
	a1, a2 = us_str.split('P')
	a2, a3 = a2.split('T')

	cnt_a = [ a1.count('A'), a2.count('A'), a3.count('A') ]

	if cnt_a[0]*cnt_a[1] == cnt_a[2]:
		return True
	else:
		return False

us_N = int(raw_input().strip())
if us_N<10:
	for i in range(us_N):
		us_str = raw_input()
		if correct_cnt(us_str):
			if correct_order(us_str):
				if correct_logic(us_str):
					print('YES')
				else:
					print('NO')
			else:
				print('NO')
		else:
			print('NO')
else:
	print('NO')


'''
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA


'''






