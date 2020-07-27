
def solve(a, b):
	x = bin(a).replace("0b", "")
	y = bin(b).replace("0b", "")
	xx = x + y
	yy = y + x

	a = int(xx, 2)
	b = int(yy, 2)

	return a - b

t = int(input())
for _ in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	if n == 1:
		print(a[0])
		continue
	ans = -1000000000000000000000000
	for i in range(n):
		for j in range(n):
			ans = max(ans, solve(a[i], a[j]))
	print(ans)