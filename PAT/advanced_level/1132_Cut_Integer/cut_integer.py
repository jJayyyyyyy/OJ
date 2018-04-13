n = int(input())
for i in range(n):
	s = input()
	num = int(s)
	len_2 = len(s)//2
	num1 = int(s[:len_2])
	num2 = int(s[len_2:])
	if num1 == 0 or num2 == 0:	# 否则会提示 [返回非零]
		print('No')
	elif num % (num1 * num2) != 0:
		print('No')
	else:
		print('Yes')