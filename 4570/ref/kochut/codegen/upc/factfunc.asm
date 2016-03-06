$fact1
	pusha	5
	fetchI
	pushcI	1
	leI
	jumpz	$else1
	pushcI	1
	setrvI
	jump	$end1
$else1
	pusha	5
	fetchI
	enter	1
	pusha	5
	fetchI
	pushcI	1
	subI
	call	$fact1,	1
	mulI
	setrvI
$end1
	returnf
main
	enter	0
	alloc	1
	enter	0
	pushs	'Enter an integer: '
	call	$WriteStri, 1
	enter	0
	pusha	5
	call	$ReadInt, 1
	enter	0
	pushs	'Factorial of '
	call	$WriteStri, 1
	enter	0
	pusha	5
	fetchI
	call	$WriteInt, 1
	enter	0
	pushs	' is '
	call	$WriteStri, 1
	enter	0			# start calling write
	enter	0			# start calling fact
	pusha	5
	fetchI
	call	$fact1,	1		# this call leaves value!
	call	$WriteInt, 1
	enter	0
	call	$WriteLn, 0
	return
