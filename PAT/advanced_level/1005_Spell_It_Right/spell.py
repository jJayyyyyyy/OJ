num_list = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']

us_N = str( sum( map(int, raw_input()) ) )

for i in range(len(us_N)):
	print num_list[int(us_N[i])],
