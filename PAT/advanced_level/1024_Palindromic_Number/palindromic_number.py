n, k = input().split()  # use raw_input() in python2.7
k = int(k)

i = 0
while i<k:
	r_n = n[::-1]
	if( n == r_n ):
		break
	else:
		n = str(int(n) + int(r_n))
		i += 1

print(n)
print(i)
