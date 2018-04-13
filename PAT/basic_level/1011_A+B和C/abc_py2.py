def is_overflow(a, b, c):
	if abs(a) <= pow(2, 31):
		return 0
	if abs(b) <= pow(2, 31):
		return 0
	if abs(c) <= pow(2, 31):
		return 0
	return 1

def is_greater(a, b, c):
	if a+b>c:
		return 1
	else:
		return 0

def main():
	a, b, c = 0, 0, 0
	num = int(raw_input())
	for i in range(num):
		a, b, c = raw_input().split()
		a, b, c = int(a), int(b), int(c)
		if is_overflow(a, b, c):
			print "Case #%d: false" % (i+1)
		elif is_greater(a, b, c):
			print "Case #%d: true" % (i+1)
		else:
			print "Case #%d: false" % (i+1)

main()
