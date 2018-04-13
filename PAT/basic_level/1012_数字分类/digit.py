#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import print_function

us_input_arr = raw_input().split()
us_input_size = int(us_input_arr[0])
us_input_arr = us_input_arr[1:]

a = [0]*6
cnt = [1, 0, 0, 0, 0, 0]
i = 0

while i<us_input_size:
	a[0] = int(us_input_arr[i])
	if 0 == a[0]%10:
		a[1] += a[0]
		cnt[1] += 1
	if 1 == a[0]%5:
		a[2] += cnt[0]*a[0]
		cnt[0] = -cnt[0]
		cnt[2] += 1
	if 2 == a[0]%5:
		a[3] += 1
		cnt[3] += 1
	if 3 == a[0]%5:
		a[4] += a[0]
		cnt[4] += 1
	if 4 == a[0]%5:
		if a[0]>a[5]:
			a[5] = a[0]
		cnt[5] += 1
	i+=1

if 0 == cnt[1]:
	a[1] = 'N'
if 0 == cnt[2]:
	a[2] = 'N'
if 0 == cnt[3]:
	a[3] = 'N'
if 0 == cnt[4]:
	a[4] = 'N'
else:
	a[4] = round(a[4]*1.0/cnt[4], 1)
if 0 == cnt[5]:
	a[5] = 'N'

print(a[1], a[2], a[3], a[4], a[5])
