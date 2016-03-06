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
	enter	1		# start calling factorial
	pusha	5		# push n's address
	fetchI			# retrieve the r-value
	pusha	6		# push fact's address (by reference!)
	call	$fact1,	2	# make the call
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
	alloc	1		# allocate space for n
	pusha	5		# push n's address
	fetchI			# retrieve the r-value
	pushcI	1		# push 1
	leI			# compare with <=
	jumpz	$else1		# jump if not <=
	pusha	6		# push fact's address (contains address too!)
	fetchI			# now we have the actual param's address
	pushcI	1		# otherwise, push 1
	storeI			# save it in *fact = 1
	jump	$end1		# bypass else
$else1
	pusha	7		# push aux's address
	pusha	5		# push n's address
	fetchI			# retrieve the r-value
	pushcI	1		# push constant 1
	subI			# subtract (n - 1)
	storeI			# save it in aux
	enter	1		# prepare to call recursively
	pusha	7		# push aux's address
	fetchI			# retrieve the r-value
	pusha	6		# push fact's address
	fetchI			# retrieve the r-value (it is still address!)
	call	$fact1,	2	# call factorial
	pusha	6		# push fact's address
	fetchI			# dereference (i.e. *fact)
	pusha	6		# push fact's address
	fetchI			# dereference (i.e. *fact)
	fetchI			# get the r-value (needed here for multipl.)
	pusha	5		# push n's address
	fetchI			# get the r-value
	mulI			# multiply:   *fact * n
	storeI			# save the result in:   *fact
$end1
	returnf			# return (not really used... )
main
	enter       0		# start global environment
	enter       0		# start 'main' environment
	call        $main1, 0	# make the call to main
	return			# stop and exit
