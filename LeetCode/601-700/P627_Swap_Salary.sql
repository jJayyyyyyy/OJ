# https://leetcode.com/problems/swap-salary/description/
# 某一个 column 只有两种取值, 交换 column 两种取值
# 参考思路
# https://leetcode.com/problems/swap-salary/solution/

update
	salary
set
	sex = case sex
		when 'm'
			then 'f'
		else
			'm'
	end
;