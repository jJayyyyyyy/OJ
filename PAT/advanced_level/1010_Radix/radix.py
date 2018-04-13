def getNum(radix, NList):
	l = len(NList); num = 0
	for i in range(l):
		num += NList[i]*(radix**(l-i-1))
	return num

def str2numList(n):
	NList = []
	for i in n:
		if i>='0' and i<='9':
			NList.append(int(i))
		else:
			NList.append(ord(i)-87)
	return NList

N1, N2, tag, radix = raw_input().split()
radix = int(radix)
if tag == '1':
	num = getNum(radix, str2numList(N1))
	target = str2numList(N2)
else:
	num = getNum(radix, str2numList(N2))
	target = str2numList(N1)
left = max(target)+1; right = max(num, left)
isFind = False; rlt = 0
while left <= right:
	mid = (left + right)/2
	tempRlt = getNum(mid, target)
	if num == tempRlt:
		rlt = mid; isFind = True
		right = mid - 1
	elif num < tempRlt:
		right = mid - 1
	else:
		left = mid + 1

if isFind:
	print rlt
else:
	print 'Impossible'
