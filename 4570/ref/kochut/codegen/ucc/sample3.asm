$main1
    alloc	1                       # allocate space for i
    enter	1			# call scanf to read-in i
    pushs	"%d"			# push format
    pusha	5			# push i's address
    call	$scanf, 2		# make the call
    popI	4			# dispose of the left-over value
    enter	1			# start the calling sequence for count
    pusha	5			# address of i
    fetchI				# retrieve the r-value
    call	$count2, 1		# call count
    popI	4			# dispose of the left-over value
    enter	1			# write out sum
    pushs	"%d\n"			# push format
    pushga	1, 5			# push sum
    fetchI				# retrieve the r-value
    call	$printf, 2              # make the call
    popI	4			# dispose of the left-over value
    returnf
$count2					# procedure count
    alloc	1			# allocate storage for i (offset 6)
    pusha	6			# push i's address
    pushcI	1			# push constant 1
    storeI				# i := 1
    popI	4			# dispose of the left-over value
    pushga	1, 5			# push sum's address (global var)
    pushcI	0			# push constant 0
    storeI				# sum := 0
    popI	4			# dispose of the left-over value
$1					# while loop begins
    pusha	6			# push i's address
    fetchI				# retrieve the r-value
    pusha	5			# push 1-st argument (passed by value)
    fetchI				# retrieve the r-value
    leI					# compare
    jumpz	$2			# jump to $2 if i > n
    pushga	1, 5			# push sum's address
    pushga	1, 5			# push sum's address
    fetchI				# retrieve the r-value
    pusha	6			# push i's address
    fetchI				# retrieve the r-value
    addI				# add them (sum + i)
    storeI				# store it in sum
    popI	4			# dispose of the left-over value
    pusha	6			# push i's address
    pusha	6			# push i's addresss
    fetchI				# retrieve the r-value
    pushcI	1			# push 1
    addI				# add
    storeI				# store in i
    popI	4			# dispose of the left-over value
    jump	$1			# go again
$2					# end of the loop
    returnf				# return from count
main
    enter       0			# start global environment
    alloc       1			# allocate space for global 'sum'
    enter       0			# start 'main' environment
    call        $main1, 0		# make the call
    return				# stop and exit
