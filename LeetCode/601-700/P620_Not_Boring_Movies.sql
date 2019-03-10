# https://leetcode.com/problems/not-boring-movies/description/
# https://leetcode.com/problems/not-boring-movies/solution/

select
	*
from
	cinema
where
	mod(id, 2) = 1 and description != 'boring'
order by
	rating desc
;