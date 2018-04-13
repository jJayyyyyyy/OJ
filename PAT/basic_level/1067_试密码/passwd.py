#!/usr/bin/env python3

s1 = input().split(' ')
correctPd = s1[0]
maxCnt = int( s1[1] )
s2 = []

while True:
	s1 = input()
	if s1=='#':
		break
	else:
		s2.append(s1)

for i in range( len(s2) ):
	if s2[i]==correctPd:
		if i<maxCnt:
			print('Welcome in')
			break
	else:
		print('Wrong password: %s' % s2[i])
		if i==maxCnt-1:
			print('Account locked')
			break
