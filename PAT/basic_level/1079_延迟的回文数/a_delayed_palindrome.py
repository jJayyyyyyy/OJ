# 用python最简单，不用考虑大整数运算溢出

def main():
	s1 = input()
	flag = 0
	for i in range(10):
		s2 = s1[::-1]
		n1, n2 = int(s1), int(s2)
		if n1 == n2:
			print("%d is a palindromic number." % n1)
			flag = 1
			break
		else:
			n3 = n1 + n2
			s3 = str(n3)
			print("%d + %d = %d" % (n1, n2, n3))
			s1 = s3
	if flag == 0:
		print("Not found in 10 iterations.")

main()