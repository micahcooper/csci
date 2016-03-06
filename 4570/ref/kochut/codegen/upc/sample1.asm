main
	enter	0			# setup the main stack frame
	alloc	2			# allocate 2 words for variables
	enter	0			# input integer
	pusha	5			# save it in i's location
	call	$ReadInt, 1
	pushcI	9			# push constant 9
	pusha	5			# push i's contents
	fetchI
	pushcI	8			# push constant 8
	mulI				# multiply i*8
	addI				# add	9 + i*8
	popI	6			# save it in j's location
	enter	0			# print 'Result is '
	pushs	'Result is '
	call	$WriteStri, 1
	enter	0			# print j (offset is 6)
	pusha	6
	fetchI
	call	$WriteInt, 1
	enter	0			# print NEWLINE
	call	$WriteLn, 0
	return				# stop and exit
