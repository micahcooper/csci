$main1
        alloc   2			# allocate 2 words for i and j
        enter   1			# start calling scanf
	pushs	"%d"			# push the format string
	pusha	5			# push address (l-value) of i
	call	$scanf, 2		# now call scanf
	popI	4			# dispose of the left-over value
	pusha	6			# push j's address
	pushcI	9			# push constant 9
	pusha	5			# push i's address 
	fetchI				# retrieve the r-value
	pushcI	8			# push constant 8
	mulI				# multiply i*8
	addI				# add	9 + i*8
	storeI				# save it in j's location
	popI	4			# dispose of the left-over value
	enter	1			# start calling printf
	pushs	"Result is %d\n"	# push the format
	pusha	6			# push value of j
	fetchI				# retrieve the r-value
	call	$printf, 2		# call printf
	popI	4			# dispose of the left-over value
	returnf				# return from main
main
	enter	0			# setup the main stack frame
	alloc	0			# no allocation -- not really needed
        enter   0			# start calling main
        call    $main1, 0		# make the call
	popI	4			# dispose of the left-over value
        return
