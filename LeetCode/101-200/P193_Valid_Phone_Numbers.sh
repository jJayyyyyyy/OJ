# https://leetcode.com/problems/valid-phone-numbers/description/
# 正则表达式
# 参考 https://leetcode.com/problems/valid-phone-numbers/discuss/55481/Three-different-solutions-using-grep-sed-and-awk

# Solution 1 with grep -P
grep -P '^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$' file.txt
# or
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
# or egrep
egrep '^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$' file.txt


# Solution 2 with sed
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt

# Solution 3 with awk
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt