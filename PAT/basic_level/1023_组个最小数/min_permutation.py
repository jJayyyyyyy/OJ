from __future__ import print_function

numList = raw_input().split()
numList = map(int, numList)

for i in range(1, 10):
    if 0!=numList[i]:
        print(i, end='')
        numList[i] -= 1
        break

for i in range(10):
    while numList[i]:
        print(i, end='')
        numList[i] -= 1
