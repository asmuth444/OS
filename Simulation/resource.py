filename= raw_input("Enter data file name:") # File Name Input
lines = [line.rstrip('\n') for line in open(filename)] # Preparing File Data
no_of_resources = int(lines[0]) # No. of Resources
no_of_processes = int(lines[1]) # No. of Processes
rmax = list(map(int,lines[2].split())) # Resources maximum no. of instances
print "Resource Max Matrix:"
print " ".join(map(str,rmax))
nmax = []
alloc = []
need = []
avail = []
flag = [0 for i in xrange(no_of_processes)]
start = 3
print "Max Matrix: " #Maximum Matrix input
for i in xrange(no_of_processes):
	nmax.append(map(int,lines[i+start].split()))
	print lines[i+start]
start += no_of_processes
print "Allocation Matrix: " # Allocation Matrix input
for i in xrange(no_of_processes):
	alloc.append(map(int,lines[i+start].split()))
	print lines[i+start]
print "Need Matrix:" # Preparing Need Matrix [Need = Max - Alloc]
for i,j in zip(nmax,alloc):
	temp = []
	for k,l in zip(i,j):
		temp.append(k-l)
	print " ".join(map(str,temp))
	need.append(temp)
temp = [sum(x) for x in zip(*alloc)]
avail = [i-j for i,j in zip(rmax,temp)] # Preparing Available matrix [Avail = RMax - Alloc]
print "Available Matrix:" 
print " ".join(map(str,avail))
check = True
for k in xrange(no_of_processes): # Checking for Deadlock in system
	for n in xrange(no_of_processes):
		for m in xrange(no_of_resources):
			if avail[m]>=need[n][m] and flag[n] is 0:
				check=True
			else:
				check=False
				break
		if check:
			flag[n]=1
			temp=[x+y for x,y in zip(avail,alloc[n])]
			avail=temp
		else:
			flag[n]=0

if 0 in flag: # if Deadlock
	print "System is not safe.Processes in deadlock:"
	count=0
	for f in xrange(no_of_processes):
		if flag[f] is 0:
			print "P"+str(f)
else:# if no Deadlock
	print "System Safe"
