$main1
        alloc   3			# allocate 3 words for x, y, and z
#                     x is at 5
#                     z is at 6
#                     y is at 7
        enter   1			# start calling scanf
	pushs	"%f"			# push the format string
	pusha	5			# push address (l-value) of x
	call	$scanf, 2		# now call scanf
	popI	4			# dispose of the left-over value
	pusha	6			# push z's address
	pushcI	9			# push constant 9
	pusha	5			# push x's address
	fetchR				# retrieve the r-value (float!)
	pushcI	8			# push constant 8
	flt				# convert 8 to float
	mulR				# multiply x*8.0
	fltb				# convert 9 to float
	addR				# add	9.0 + x*8.0
	storeR				# save it in z's location
	popI	4			# dispose of the left-over value
	pusha	7			# push y's address
	pushcI	9			# push constant 9
	pusha	5			# push x's address
	fetchR				# retrieve the r-value (float!)
	pushcI	8			# push constant 8
	flt				# convert 8 to float
	mulR				# multiply x*8.0
	fltb				# convert 9 to float
	addR				# add	9.0 + x*8.0
	int				# convert to int (truncate)
	storeI				# save it in y's location
	popI	4			# dispose of the left-over value
	enter	1			# start calling printf
	pushs	"Result (int) is %d\n"	# push the format
	pusha	7			# push value of y
	fetchI				# retrieve the r-value
	call	$printf, 2		# call printf
	popI	4			# dispose of the left-over value
	enter	1			# start calling printf
	pushs	"Result (float) is %f\n"	# push the format
	pusha	6			# push value of z
	fetchR				# retrieve the r-value
	call	$printf, 2		# call printf
	popI	4			# dispose of the left-over value
	returnf				# return from main
main
	enter	0			# setup the main stack frame
        enter   0			# start calling main
        call    $main1, 0		# make the call
	popI	4			# dispose of the left-over value
        return
