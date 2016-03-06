main
	enter	0			# setup the main stack frame
	alloc	2			# allocate 2 words for variables
	enter	0			# input integer
	pusha	5			# save value in i
	call	$ReadInt, 1
	pushcI	9			# push constant 9
	pusha	5			# push i's contents
	fetchI
	pushcR	8.3e3			# push constant 8.3e3
	fltb
	mulR				# multiply i*8.3e3
	fltb
	addR				# add	9 + i*8.3e3
	popR	6			# save it in j's location
	enter	0			# print 'Result is '
	pushs	'Result is '
	call	$WriteStri, 1
	enter	0			# print j (offset is 4)
	pusha	6
	fetchR
	call	$WriteReal, 1
	enter	0			# print '\n'
	call	$WriteLn, 0
	return				# stop and exit
