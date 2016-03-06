$count1					# procedure count
    alloc	1			# allocate storage for i (offset 7)
    pushcI	1
    popI	7			# i := 1
    pushI	6			# push address of the 2-nd argument
    pushcI	0
    popiI				# save 0 in 2-nd argument
$1					# while loop begins
    pusha	7			# push i
    fetchI
    pusha	5
    fetchI
    leI					# compare
    jumpz	$2			# jump to $2 if i > n
    pushI	6
    pushI	6
    fetchI
    pusha	7
    fetchI
    addI				# this is sum + i
    popiI				# store it in sum
    pusha	7			# push i
    fetchI
    pushcI	1			# push 1
    addI				# add
    popI	7			# store in i
    jump	$1			# go again
$2					# end of the loop
    return				# return from count
main
    enter	0
    alloc	2
    enter	0
    pusha	5
    call	$ReadInt, 1
    enter	0			# start the calling sequence 
    pushI	5			# i (offset 5)
    pusha	6			# address if sum (offset 6)
    call	$count1, 2		# call count
    enter	0			# write out sum
    pusha	6
    fetchI
    call	$WriteInt, 1
    enter	0			# write out NEWLINE
    call	$WriteLn, 0
    return
