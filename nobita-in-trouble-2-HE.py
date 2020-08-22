for _ in range(int(input())):
	n = int(input())
	new_n = bin(n).split("0b")[1]
	idx = len(new_n) -1
	res = []
	for elem in new_n:
		if elem == "1":
			res.append(pow(3, idx))
		idx -= 1
	res.sort()
	print(len(res))
	for elem in res:
		print(elem, end = " ")
	print("")