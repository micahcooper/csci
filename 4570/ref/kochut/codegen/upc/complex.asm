# procedure add( var a, b, c: complex )	
#	
#	a at offset 5
#	b at offset 6
#	c at offset 7
#	
$add1
	pushI 	7	# push the address of c
	pushcI  0	# offset of re in complex
	addI		# now we have the address of c.re
	pushI	5	# push the address of a
	pushcI  0	# offset of re in complex
	addI		# now we have the address of a.re
	fetchR		# get r-value of a.re
	pushI	6	# push the address of a
	pushcI  0	# offset of re in complex
	addI		# now we have the address of b.re
	fetchR		# get r-value of b.re
	addR		# a.re + b.re
	storeR		# save it in c.re
	pushI 	7	# push the address of c
	pushcI  1	# offset of im in complex
	addI		# now we have the address of c.im
	pushI	5	# push the address of a
	pushcI  1	# offset of im in complex
	addI		# now we have the address of a.im
	fetchR		# get r-value of a.im
	pushI	6	# push the address of a
	pushcI  1	# offset of im in complex
	addI		# now we have the address of b.im
	fetchR		# get r-value of b.im
	addR		# a.im + b.im
	storeR		# save it in c.im
	return
main
#
#	a is at 5
#	b is at 7
#	c is at 9
#
	enter 	0
	alloc   6
	enter 	0
	pusha	5	# push the address of a
	pushcI  0	# offset of re in complex
	addI		# now we have the address of a.re
	call	$ReadReal, 1
	enter 	0
	pusha	5	# push the address of a
	pushcI  1	# offset of im in complex
	addI		# now we have the address of a.im
	call	$ReadReal, 1
	enter 	0
	pusha	7	# push the address of b
	pushcI  0	# offset of re in complex
	addI		# now we have the address of b.re
	call	$ReadReal, 1
	enter 	0
	pusha	7	# push the address of a
	pushcI  1	# offset of im in complex
	addI		# now we have the address of b.re
	call	$ReadReal, 1
	enter   0
	pusha	5
	pusha	7
	pusha	9
	call	$add1, 3
	enter	0
	pushs	'Result is: ('
	call	$WriteStri, 1
	enter	0
	pusha	9
	pushcI	0
	addI
	fetchR
	call	$WriteReal, 1
	enter	0
	pushs	', '
	call	$WriteStri, 1
	enter	0
	pusha	9
	pushcI	1
	addI
	fetchR
	call	$WriteReal, 1
	enter	0
	pushs	')'
	call	$WriteStri, 1
	enter	0
	call	$WriteLn, 0
	return
