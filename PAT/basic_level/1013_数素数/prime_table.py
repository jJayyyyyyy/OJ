#!/usr/bin/env python
from __future__ import print_function

us_pm, us_pn = raw_input().split()
us_pm, us_pn = int(us_pm), int(us_pn)
num, cnt, line_cnt = 2, 0, 0

MAX = us_pn*10 + 5001
is_prime = [bool] * MAX
is_prime[0:3] = [False, False, True]
for i in range(3, MAX, 2):
	is_prime[i] = True
	is_prime[i+1] = False

up_bound = int(MAX**0.5) + 1
for i in range(3, up_bound, 2):
	if is_prime[i]:
		for j in range(i+i, MAX, i):
			is_prime[j] = False

while True:
	if is_prime[num]:
		cnt += 1
	if us_pm == cnt:
		print(num, end='')
		line_cnt += 1
		num += 1
		break
	num += 1

if us_pn == us_pm:
	exit()

while True:
	if is_prime[num]:
		if 9 == line_cnt:
			print(' %d'%num)
			line_cnt = 0
		else:
			if 0==line_cnt:
				print('%d'%num, end='')
			else:
				print(' %d'%num, end='')
			line_cnt += 1
		cnt += 1
		if us_pn == cnt:
			break
	num += 1
