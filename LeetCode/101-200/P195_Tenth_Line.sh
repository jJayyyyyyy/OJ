# https://leetcode.com/problems/tenth-line/description/
# Read from the file file.txt and output the tenth line to stdout.
# 输出一个文件的第 10 行
# 参考1 https://coolshell.cn/articles/9070.html
# 参考2 https://leetcode.com/problems/tenth-line/discuss/55544/Share-four-different-solutions

awk 'NR==10 {print $0}' file.txt