from __future__ import print_function

sci = raw_input()
ixE = sci.find('E')

if '-'==sci[0]:
	print('-', end='')

part1 = sci[1]
part2 = sci[3:ixE]
len2 = len(part2)
e = int(sci[ixE+1:])

if e>0:
	if e<len2:
		print( part1+part2[:e]+'.'+part2[e:len2] )
	else:
		print( part1+part2+(e-len2)*'0' )
elif e==0:
	print(sci[1:ixE])
else:
	e = -e
	print( '0.'+'0'*(e-1)+part1+part2 )
