from __future__ import print_function

us_num = raw_input()
len_num = len(us_num)
cnt = [0]*10

for i in range(len_num):
	n = int(us_num[i])
	cnt[n] += 1

for i in range(10):
	if cnt[i]:
		print(i, end='')
		print(':', end='')
		print(cnt[i])
