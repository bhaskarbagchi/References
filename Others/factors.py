from math import sqrt

def noOfFactors(n):
	factors = set()
	for x in range(1, int(sqrt(n)) + 1):
		if n % x == 0:
			factors.add(x)
			factors.add(n//x)
	return factors.size()

a, b, n = map(int, input().split())
count = 0
for x in range(a, b):
	if n == noOfFactors(x):
		count = count  + 1
print(count)