def search_s(snum):
	m = snum
	while 1:
		m = m + snum % 10
		snum = snum // 10
		if snum == 0:
			break
	return m
mylist = [1] * 10001

for i in range(10000):
	m = search_s(i)
	if m < 10000:
		mylist[m] = 0

for n in range(10000):
	if(mylist[n] == 1):
		print(n)
