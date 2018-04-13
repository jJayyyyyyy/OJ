#!/usr/bin/env python3

s = input().split(' ')
totalNumber, step, firstWinner = map(int, s)
repostList = ['']
winners = set()

for i in range(totalNumber):
	repostList.append( input() )

if firstWinner > totalNumber:
	print('Keep going...')
else:
	i = firstWinner
	while i<=totalNumber:
		candidate = repostList[i]
		if candidate in winners:
			while i<=totalNumber:
				nextCandidate = repostList[i]
				if nextCandidate not in winners:
					print(nextCandidate)
					winners.add(nextCandidate)
					break
				i += 1
		else:
			print(candidate)
			winners.add(candidate)
		i += step
