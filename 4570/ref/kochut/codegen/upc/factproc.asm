#
#               i is at offset 5 (by value)
#               n is at offset 6 (by reference)
#
$fact1
	pusha	5
	fetchI
	pushcI	1
	leI
	jumpz	$else1
	pushI	6
	pushcI	1
	popiI
	jump	$end1
$else1
	enter	1
	pusha	5
	fetchI
	pushcI	1
	subI
	pusha	6
	fetchI
	call	$fact1,	2
	pushI	6
	pushI	6
	fetchI
	pusha	5
	fetchI
	mulI
	popiI
$end1
	return
main
	enter	0
	alloc	2
	enter	0
	pushs	'Enter an integer: '
	call	$WriteStri, 1
	enter	0
	pusha	5
	call	$ReadInt, 1
	enter	0
	pusha	5
	fetchI
	pusha	6
	call	$fact1,	2
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
	enter	0
	pusha	6
	fetchI
	call	$WriteInt, 1
	enter	0
	call	$WriteLn, 0
	return
