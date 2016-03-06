$count1
	alloc	1
	pushcI	1
	popI	7
	pushcI	0
	popI	6
$2
	pushcI	1
	pusha	5
	fetchI
	leI
	jumpz	$3
	pusha	6
	fetchI
	pusha	7
	fetchI
	addI
	popI	6
	pusha	7
	fetchI
	pushcI	1
	addI
	popI	7
	return
	jump	$2
$3
	return
main
	enter	0
	alloc	0
	enter	0
	pusha	5
	call	$ReadInt, 1
	enter	0
	pusha	5
	fetchI
	pusha	6
	fetchI
	call	$count1, 2
	enter	0
	pusha	6
	fetchI
	call	$WriteInt, 1
	enter	0
	call	$WriteLn, 0
	return
