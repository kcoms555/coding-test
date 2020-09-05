import random
for i in range(100):
	count = 0
	for _ in range(100):
		birthlist = []
		for _ in range(i):
			birth = random.randint(1,365)
			if birth in birthlist:
				count += 1
				break
			else:
				birthlist.append(birth)
	print(f'{i}명일 때 : {count}%')
