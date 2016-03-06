#
# procedure count
#      
#   parameters:  v   -- offset 5, passed by reference
#                n   -- offset 6, passed by value
#                sum -- offset 7, passed by reference
#
$count1					# procedure count
    alloc	1			# allocate storage for i (offset 8)
    pushcI	1
    popI	8			# i := 1
    pushI	7			# push sum (parameter by ref)
    pushcR	0.0
    popiR				# sum := 0.0
$1					# while loop begins
    pusha	8			# push i's l-value
    fetchI				# get r-value
    pusha	6			# push n
    fetchI				# get r-value
    leI					# compare with <=
    jumpz	$2			# jump to $2 if i > n
    pushI	7			# push sum (l-value of the actual param!)
    pushI	7			# push sum (l-value of the actual param!)
    fetchR				# note that sum is a real parameter
    pushI	5			# push 1-st arg (v, by reference)
    pusha	8			# push i
    fetchI
    pushcI	1
    subI
    addI
    fetchR				# fetch v[i]
    addR				# this is sum + v[i]
    popiR				# store it in sum
    pusha	8			# push i
    fetchI
    pushcI	1			# push 1
    addI				# add
    popI	8			# store in i
    jump	$1			# go again
$2					# end of the loop
    return				# return from count
main
    enter	0
    alloc	11
#			v - offset 5 (size 10 words)
#			sum - offset 15 (size 1 word)
#
    pusha	5			# address of v
    pushcI	1			# [1]
    pushcI	1			# lowest index is 1
    subI
    addI				# get v[1]'s l-value
    pushcI	11
    flt
    popiR
    pusha	5			# address of v
    pushcI	2			# [2]
    pushcI	1
    subI
    addI				# get v[2]'s l-value
    pushcR	22.2e3
    popiR
    pusha	5			# address of v
    pushcI	3			# [3]
    pushcI	1
    subI
    addI				# get v[3]'s l-value
    pushcR	33.3e-1
    popiR
    pusha	5			# address of v
    pushcI	4			# [4]
    pushcI	1
    subI
    addI				# get v[4]'s l-value
    pushcR	44.9
    popiR
    enter	0			# start the calling sequence 
    pusha	5			# l-valuesaof v (offset 5)
    pushcI	4			# k constant 4
    pusha	15			# l-value of sum (offset 15)       
    call	$count1, 3		# call count
    enter	0			# write out sum
    pusha	15			# sum's l-value
    fetchR				# get the r-value
    call	$WriteReal, 1
    enter	0			# write out NEWLINE
    call	$WriteLn, 0
    return
