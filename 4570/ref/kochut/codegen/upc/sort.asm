#
#	b	- offset 5 (passed by ref)
#	i	- offset 6 (local var)
#
$PRINTVECTOR1
   alloc     1
   pushcI    1
   popI      6
$LOOP1
   pusha     6
   fetchI
   pushcI    5
   leI
   jumpz     $LOOP2
   enter     0
   pushs     'value '
   call	     $WriteStri, 1
   enter     0
   pusha     6
   fetchI
   call      $WriteInt, 1
   enter     0
   pushs     ' = '
   call      $WriteStri, 1
   enter     0
   pushI     5
   pusha     6
   fetchI
   pushcI    1
   subI
   addI
   fetchI 
   call      $WriteInt, 1
   enter     0
   call      $WriteLn, 0
   pusha     6
   fetchI
   pushcI    1
   addI
   popI      6
   jump      $LOOP1
$LOOP2
   return
#
#	c	- offset 5 (passed by ref)
#	i	- offset 6 (local var)
#	j	- offset 7   "
#	temp	- offset 8   "
#
$SORTVECTOR2
   alloc     3
   pushcI    1
   popI      6
$LOOP3
   pusha     6
   fetchI
   pushcI    5
   ltI
   jumpz     $LOOP4
   pusha     6
   fetchI
   pushcI    1
   addI
   popI      7
$LOOP5
   pusha     7
   fetchI
   pushcI    6
   ltI
   jumpz     $LOOP6
   pushI     5
   pusha     6
   fetchI
   pushcI    1
   subI
   addI
   fetchI 
   pushI     5
   pusha     7
   fetchI
   pushcI    1
   subI
   addI
   fetchI 
   gtI
   jumpz     $IF7
   pushI     5
   pusha     6
   fetchI
   pushcI    1
   subI
   addI
   fetchI 
   popI      8
   pushI     5
   pusha     6
   fetchI
   pushcI    1
   subI
   addI
   pushI     5
   pusha     7
   fetchI
   pushcI    1
   subI
   addI
   fetchI 
   popiI
   pushI     5
   pusha     7
   fetchI
   pushcI    1
   subI
   addI
   pusha     8
   fetchI
   popiI
$IF7
   pusha     7
   fetchI
   pushcI    1
   addI
   popI      7
   jump      $LOOP5
$LOOP6
   pusha     6
   fetchI
   pushcI    1
   addI
   popI      6
   jump      $LOOP3
$LOOP4
   return
main
   enter     0
   alloc     11
   enter     0
   pushs     'Please enter 5 integers for sorting.'
   call      $WriteStri, 1
   enter     0
   call      $WriteLn, 0
   enter     0
   call      $WriteLn, 0
   pushcI    1
   popI      15
$LOOP9
   pusha     15
   fetchI
   pushcI    5
   leI
   jumpz     $LOOP10
   enter     0
   pushs     'enter an integer for sorting: '
   call      $WriteStri, 1
   enter     0
   pusha     5
   pusha     15
   fetchI
   pushcI    1
   subI
   addI
   call      $ReadInt, 1
   pusha     15
   fetchI
   pushcI    1
   addI
   popI      15
   jump      $LOOP9
$LOOP10
   enter     0
   pushs     'the original input: '
   call      $WriteStri, 1
   enter     0
   call      $WriteLn, 0
   enter     0
   pusha     5
   call      $PRINTVECTOR1,  1
   enter     0
   pusha     5
   call      $SORTVECTOR2,  1
   enter     0
   pushs     'the sorted numbers: '
   call      $WriteStri, 1
   enter     0
   call      $WriteLn, 0
   enter     0
   pusha     5
   call      $PRINTVECTOR1,  1
   return
