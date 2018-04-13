from __future__ import print_function
import cmath


r1, p1, r2, p2 = map(float, raw_input().split())

z1 = cmath.rect(r1, p1)
z2 = cmath.rect(r2, p2)
z3 = z1*z2

# import math
# img = r1*r2*math.sin(p1+p2)
# real=r1*r2*math.cos(p1+p2)

img = z3.imag
real = z3.real

# 0.01 or 0.005
if abs(img)<0.01:
	img=0
if abs(real)<0.01:
	real=0

if img<0:
	print('%.2f-%.2fi' % (real, abs(img)))
else:
	print('%.2f+%.2fi' % (real, abs(img)))



'''
2.3 3.5 5.2 0.4


-8.68215035823-8.22568326384j

-8.68-8.23i

'''

