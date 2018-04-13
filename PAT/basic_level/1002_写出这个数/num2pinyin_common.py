#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import print_function

num_pinyin = ['ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu']

sigma, hundred, ten, single = 0, 0, 0, 0
us_num = raw_input()
us_num = map(int, us_num)
sigma = sum(us_num)

p_hundreds = sigma / 100
sigma = sigma - p_hundreds*100
p_tens = sigma / 10
sigma = sigma - p_tens*10
p_units = sigma

if 0!=p_hundreds:
	print(num_pinyin[p_hundreds], num_pinyin[p_tens], num_pinyin[p_units])
if 0==p_hundreds:
	if 0!=p_tens:
		print(num_pinyin[p_tens], num_pinyin[p_units])
	else:
		print(num_pinyin[p_units])

