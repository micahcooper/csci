$print1
#			b is at 5 (note this is the address of the actual)
#			i is at 6
#
	alloc	1		# allocate space for i
	pusha	6		# push i's address
	pushcI	0		# push 0
	storeI			# save it in i
	popI	4		# dispose of the left-over value
$loop1
	pusha	6		# push i's address
	fetchI			# retrieve the r-value
	pushcI	5		# push 5
	ltI			# compare
	jumpz 	$loop2		# if false (0) skip to $loop2
	enter	1		# start calling printf
	pushs	"value %d "	# push format
	pusha	6		# push i's address
	fetchI			# retrieve r-value
	pushcI	1		# push 1
	addI			# add i + 1
	call	$printf, 2	# make the call
 	popI	4		# dispose of the left-over value
	enter	1		# start calling printf
	pushs	" = %d\n"	# push format
	pusha	5		# push b's address
	fetchI			# retrieve the r-value (actual's address)
	pusha	6		# push i's address
	fetchI			# retrieve the r-value
	addI			# compute the final offset
	fetchI 			# retrieve the r-value (i.e. b[i])
	call	$printf, 2	# make the call
 	popI	4		# dispose of the left-over value
	pusha	6		# push i's addr
	pusha	6		# push i's addr
	fetchI			# retrieve the r-value
	pushcI	1		# push 1
	addI			# add i + 1
	storeI			# save it in i
 	popI	4		# dispose of the left-over value
	jump	$loop1		# go again...
$loop2
	returnf			# return
$sort2
# 			c    is at 5 (parameter)
	alloc	3		# allocate local var space
# 			i    is at 6
# 			j    is at 7
# 			temp is at 8
	pusha	6		# push i's address
	pushcI	0		# push 0
	storeI			# save in i
	popI	4		# dispose of the left-over value
$loop3			
	pusha	6		# push i's address
	fetchI			# retireve r-value
	pushcI	4		# push 4
	ltI			# compare
	jumpz	$loop4		# skip if false (0)
	pusha	7		# push j's address
	pusha	6		# push i's address
	fetchI			# retrieve r-value
	pushcI	1		# push 1
	addI			# add  i + 1
	storeI			# save it in j
	popI	4		# dispose of the left-over value
$loop5
	pusha	7		# push j's address
	fetchI			# retrieve r-value
	pushcI	5		# push 5
	ltI			# compare
	jumpz	$loop6		# skip if false (0) 
	pusha	5		# push c's address
	fetchI			# now we have actual's address (array!)
	pusha	6		# push i's address
	fetchI			# get the r-value
	addI			# compute final offset
	fetchI 			# get the r-value (of the array element c[i])
	pusha	5		# push c's address
	fetchI			# now we have actual's address (array!)
	pusha	7		# push j's address
	fetchI			# get the r-value
	addI			# compute final offset
	fetchI 			# get the r-value (of the array element c[j])
	gtI			# compare (c[i] > c[j])
	jumpz	$if7		# skip if false
	pusha	8		# push temp's address
	pusha	5		# push c's address
	fetchI			# now we have actual's address (array!)
	pusha	6		# push i's address
	fetchI			# get the r-value
	addI			# compute final offset
	fetchI 			# get the r-value (of the array element c[i])
	storeI			# store it in temp
	popI	4		# dispose of the left-over value
	pusha	5		# push c's address
	fetchI			# now we have actual's address (array!)
	pusha	6		# push i's address
	fetchI			# get the r-value
	addI			# compute final offset (lhs, i.e. c[i])
	pusha	5		# push c's address
	fetchI			# now we have actual's address (array!)
	pusha	7		# push j's address
	fetchI			# get the r-value
	addI			# compute final offset
	fetchI			# get the r-value of c[j]
	storeI			# store it in c[i]
	popI	4		# dispose of the left-over value
	pusha	5		# push c's address
	fetchI			# now we have actual's address (array!)
	pusha	7		# push j's address
	fetchI			# get the r-value
	addI			# compute final offset (lhs, i.e. c[j])
	pusha	8		# push temp's address
	fetchI			# get the r-value
	storeI			# store it in temp
	popI	4		# remove the left-over value
$if7
	pusha	7		# push j's address
	pusha	7		# push j's address
	fetchI			# retrieve r-value
	pushcI	1		# push 1
	addI			# add  (j + 1)
	storeI			# save it in j
	jump	$loop5		# go again (inner loop)
$loop6
	pusha	6		# push i's address
	pusha	6		# push i's address
	fetchI			# get the r-value
	pushcI	1		# push 1
	addI			# add i and 1
	storeI			# save it in i
	popI	4		# dispose of the left-over value
	jump	$loop3		# go again (outer loop)
$loop4
	returnf			# and now return
$main3
	alloc	11		# allocate space for i and array a (1 + 10)
#			a starts at 5 (takes up 10 words)
#			i is at 15
	enter 	1		# start calling printf
	pushs	"Please enter 5 integers for sorting.\n\n"
	pushcI	0		# supply "fake" parameter to $printf
	call	$printf, 2	3 make the call
	popI	4		# drop the left-over value
	pusha	15		# push i
	pushcI	0		# push 0
	storeI			# store it in i
	popI	4		# drop the left-over value
$loop9
	pusha	15		# push i
	fetchI			# retrieve r-value
	pushcI	5		# push 5
	ltI			# compare (i < 5 )
	jumpz	$loop10		# skip if false
	enter	1		# start calling printf
	pushs	"enter an integer for sorting: "
	pushI	0		# placeholder
	call	$printf, 2	# make the call
	popI	4		# drop the left-over value
	enter	1		# start calling scanf
	pushs	"%d"		# push format
	pusha	5		# push a's address (first location)
	pusha	15		# push i's address
	fetchI			# retrieve the r-value
	addI			# compute the final offset
	call	$scanf, 2	# make the call
	popI	4		# dispose of the left-over value
	pusha	15		# push i's address
	pusha	15		# push i's address
	fetchI			# retrieve the r-value
	pushcI	1		# push 1
	addI			# add i + 1
	storeI			# save it in i
	popI	4		# drop the left-over value
	jump	$loop9		# go back to the beginning ot loop
$loop10
	enter	1		# start calling printf
	pushs	"the original input:\n"
	pushcI	0		# placeholder
	call	$printf, 2	# make the call
	popI	4		# drop the left-over value
	enter	1		# start calling printvector
	pusha	5		# push the address of a
	call	$print1, 1	# make the call
	popI	4		# drop the left-over value
	enter	1		# start calling sortvector
	pusha	5		# push the address of a
	call	$sort2, 1	# make the call
	popI	4		# drop the left-over value
	enter	1		# start calling printf
	pushs	"the sorted numbers:\n"
	pushcI	0		# placeholder
	call	$printf, 2	# make the call
	popI	4		# drop the left-over value
	enter	1		# start calling print
	pusha	5		# push a's address
	call	$print1, 1	3 make tha call
	popI	4		# drop the left-over value
	returnf			# return from main
main
	enter	0		# setup the main stack frame
        enter   0		# start calling main
        call    $main3, 0	# make the call
	popI	4		# dispose of the left-over value
        return			# stop and exit
