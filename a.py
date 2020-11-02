import math

head = []
sizes = []

class pairs:  
    def __init__(self, first, second):  
        self.first = first  
        self.second = second 

def dsu(n):
	head.clear()
	sizes.clear()
	for i in range(0, n +1):
		head.append(i)
		sizes.append(1)

def find_head(node):
	if head[node] == node:
		return node

	head[node] = find_head(head[node])
	return head[node]

def union_dsu(u, v):
	if sizes[u] > sizes[v]:
		temp = u
		u = v
		v = temp
	u = find_head(u)
	v = find_head(v)

	sizes[v] = sizes[v] + sizes[u]
	sizes[u] = 0
	head[u] = v

t = int(input())
for _ in range(t):
	n = int(input())
	arr = list(map(int, input().split(' ')))
	arr.insert(0, 0)

	dsu(n)

	edges = []
	i = 1
	while i < n +1:
		j = i +1
		while j < n +1:
			u = find_head(i)
			v = find_head(j)
			if u != v and arr[i] != arr[j]:
				union_dsu(i, j)
				edges.append(pairs(i, j))
			j += 1
		i += 1
	flag = 0
	for i in range(1, n +1):
		if(sizes[i] == n):
			print("YES")
			flag = 1
			for edge in edges:
				print(edge.first, edge.second, sep = ' ')
			break
	if flag == 0:
		print("NO")