

x, k, d = map(int, input().split(' '))
if x == 0:
	if k&1:
		print(d)
	else:
		print("0")
elif x < 0:
	_max = x + k*d
	if _max <= 0:
		print(abs(_max))
	else:
		k -= (abs(x)//d)
		x += d*(abs(x)//d)
		if k > 0:
			nxt = x + d
			if k&1:
				print(abs(nxt))
			else:
				print(abs(x))
		else:
			print(abs(x))
else:
	_max = x - k*d
	if _max >= 0:
		print(abs(_max))
	else:
		k -= (abs(x)//d)
		x -= d*(abs(x)//d)
		if k > 0:
			nex = x - d
			if k&1:
				print(abs(nex))
			else:
				print(abs(x))
		else:
			print(abs(x))
		