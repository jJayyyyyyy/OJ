from __future__ import print_function

us_input = raw_input().split()
A, Da, B, Db = us_input[0], us_input[1], us_input[2], us_input[3]
cnt_Da, cnt_Db = A.count(Da), B.count(Db)

def get_p(cnt_D, D):
	if cnt_D:
		return int(D*cnt_D)
	else:
		return 0

Pa = get_p(cnt_Da, Da)
Pb = get_p(cnt_Db, Db)

print( Pa+Pb )
