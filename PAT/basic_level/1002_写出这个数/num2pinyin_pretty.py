#!/usr/bin/env python
# -*- coding: utf-8 -*-
num_pinyin = ['ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu']
us_num = raw_input()

us_num = map(int, us_num)
sigma = sum(us_num)
sigma = str(sigma)

for i in range(len(sigma)):
	print num_pinyin[int(sigma[i])],
