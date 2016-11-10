def tprocessing(bt,qt):#Time processing
	if bt <= qt:
		return 0,bt
	else:
		return bt-qt,qt 

def qprocessing(queue): #Queue Processing
	if queue[0][1] is 0:
		print "\nProcess P"+str(queue[0][0])+" is finished"
		queue.remove(queue[0])
	else:
		to_be_removed = queue[0]
		queue.remove(to_be_removed)
		queue.append(to_be_removed)
	return queue

def queue_maker(bt):
	return [[pid,i] for pid,i in zip(xrange(len(bt)),bt)]

no_of_processes = int(raw_input('Enter no. of processes: ')) #input no. of processes
burst_time = map(int,raw_input('Enter list of burst times: ').split()) #input list of burst times
quantum_time = int(raw_input('Enter time slice: ')) #input time slice
queue = queue_maker(burst_time)
total_time = 0
while True:
	print "\nProcessing P"+str(queue[0][0])+" Time left: "+str(queue[0][1])
	queue[0][1],time_taken = tprocessing(queue[0][1],quantum_time)
	print "\nTime Taken: "+str(time_taken)
	queue = qprocessing(queue)
	total_time = total_time + time_taken
	if len(queue) is 0:
		print "\nQueue finished in "+str(total_time)
		break
