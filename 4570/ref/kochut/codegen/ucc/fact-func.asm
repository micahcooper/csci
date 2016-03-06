$main1
	alloc	2		# allocate space for n and fact
	enter	1		# start calling printf
	pushs	"Enter an integer: "
	pushcI	0		# must be supplied!
	call	$printf, 2	# make the call
	popI	4		# dispose of the left-over value
	enter	1		# start calling scanf
	pushs	"%d"		# push the format string
	pusha	5		# push address of n
	call	$scanf, 2	# make the call
	popI	4		# dispose of the left-over value
	pusha	6		# push fact's address
	enter	1		# start calling factorial
	pusha	5		# push n's address
	fetchI			# retrieve the r-value
	call	$fact1,	1	# make the call
	storeI			# store the result in fact
	popI	4		# dispose of the left-over value
	enter	1		# start calling printf
	pushs	"Factorial of %d "
	pusha	5		# push n's address
	fetchI			# retrieve the r-value
	call	$printf, 2	# make the call
	popI	4		# dispose of the left-over value
	enter	1		# start calling printf
	pushs	"is %d\n"	# push format
	pusha	6		# push fact's address
	fetchI			# retrieve the r-value
	call	$printf, 2	# make the call
	popI	4		# dispose of the left-over value
	returnf			# return
$fact1
	pusha	5		# push n's address
	fetchI			# retrieve the r-value
	pushcI	1		# push 1
	leI			# compare with <=
	jumpz	$else1		# jump if not <=
	pushcI	1		# otherwise, push 1
	setrvI			# set return value
	returnf			# return
	jump	$end1		# bypass else
$else1
	pusha	5		# push n's address
	fetchI			# retrieve the r-value
	enter	1		# prepare to call recursively
	pusha	5		# push n's address
	fetchI			# retrieve the r-value
	pushcI	1		# push constant 1
	subI			# subtract
	call	$fact1,	1	# call factorial
	mulI			# multiply n by returned value
	setrvI			# set it as the return value of this call
	returnf			# and return
$end1
	returnf			# return (not really used... )
main
	enter       0		# start global environment
	enter       0		# start 'main' environment
	call        $main1, 0	# make the call to main
	return			# stop and exit
