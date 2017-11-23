a1 = raw_input()
a2 = raw_input()
a1=a1.split()
a2=a2.split()

a11 = int(a1[0])
a12 = int(a1[1])
a21 = int(a2[0])
a22 = int(a2[1])

a = list()

while True :
	if (a11<a12 or a21<a22):
		d1 = 1<<128 -1
		d2 = 1<<128 -1
		if a11!=0:
			d1 = a12//a11
		if a21!=0:
			d2 = a22//a21
		m = min(d1,d2)
		a12 = a12 - a11*m
		a22 = a22 - a21*m
		a.extend([1]*m)
	else:
		d3 = 1<<128-1
		d4 = 1<<128-1
		if a12!=0:
			d3 = a11//a12
		if a22!=0:
			d4 = a21//a22
		m2 = min(d3,d4)
		a11 = a11 - a12*m2
		a21 = a21 - a22*m2
		a.extend([0]*m2)
	if a12 == 0 and a21 == 0 :
		break;
a.reverse()
import sys
for i in range(len(a)):
	sys.stdout.write(str(a[i]))
