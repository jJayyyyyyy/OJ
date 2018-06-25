def check(passwd):
	if len(passwd) < 6:
		print("Your password is tai duan le.")
	else:
		has_digit = False
		has_alpha = False
		for ch in passwd:
			if ch.isalpha():
				has_alpha = True
			elif ch.isdigit():
				has_digit = True
			elif ch == '.':
				pass
			else:
				print("Your password is tai luan le.")
				return

		if has_digit == True and has_alpha == True:
			print("Your password is wan mei.")
		elif has_digit == False and has_alpha == True:
			print("Your password needs shu zi.")
		elif has_digit == True and has_alpha == False:
			print("Your password needs zi mu.")
		else:
			# 对于全是小数点 "." 且长度 >=6 的情况, 题目没有说明应该输出什么, 所以暂且输出 "tai luan le"
			print("Your password is tai luan le.")

def main():
	n = int(input())
	for i in range(n):
		passwd = input()
		check(passwd)

main()