$PRINTVECTOR1
   alloc     1
   pushcI    1
   popI      4
$LOOP1
   pushI     4
   pushcI    5
   leI
   jumpz     $LOOP2
   enter     0
   pushs     'value '
   call	     $WriteStri, 1
   enter     0
   pushI     4
   call      $WriteInt, 1
   enter     0
   pushs     ' = '
   call      $WriteStri, 1
   enter     0
   pushI     3
   pushI     4
   pushcI    1
   subI
   addI
   fetchR
   call      $WriteReal, 1
   enter     0
   call      $WriteLn, 0
   pushI     4
   pushcI    1
   addI
   popI      4
   jump      $LOOP1
$LOOP2
   return
$SORTVECTOR2
   alloc     3
   pushcI    1
   popI      4
$LOOP3
   pushI     4
   pushcI    5
   ltI
   jumpz     $LOOP4
   pushI     4
   pushcI    1
   addI
   popI      5
$LOOP5
   pushI     5
   pushcI    6
   ltI
   jumpz     $LOOP6
   pushI     3
   pushI     4
   pushcI    1
   subI
   addI
   fetchR
   pushI     3
   pushI     5
   pushcI    1
   subI
   addI
   fetchR
   gtR
   jumpz     $IF7
   pushI     3
   pushI     4
   pushcI    1
   subI
   addI
   fetchR
   popR      6
   pushI     3
   pushI     4
   pushcI    1
   subI
   addI
   pushI     3
   pushI     5
   pushcI    1
   subI
   addI
   fetchR
   popiR
   pushI     3
   pushI     5
   pushcI    1
   subI
   addI
   pushR     6
   popiR
$IF7
   pushI     5
   pushcI    1
   addI
   popI      5
   jump      $LOOP5
$LOOP6
   pushI     4
   pushcI    1
   addI
   popI      4
   jump      $LOOP3
$LOOP4
   return
main
   enter     0
   alloc     11
   enter     0
   pushs     'Please enter 5 reals for sorting.'
   call      $WriteStri, 1
   enter     0
   call      $WriteLn, 0
   enter     0
   call      $WriteLn, 0
   pushcI    1
   popI      13
$LOOP9
   pushI     13
   pushcI    5
   leI
   jumpz     $LOOP10
   enter     0
   pushs     'enter a real for sorting: '
   call      $WriteStri, 1
   enter     0
   pusha     3
   pushI     13
   pushcI    1
   subI
   addI
   call      $ReadReal, 1
   pushI     13
   pushcI    1
   addI
   popI      13
   jump      $LOOP9
$LOOP10
   enter     0
   pushs     'the original input: '
   call      $WriteStri, 1
   enter     0
   call      $WriteLn, 0
   enter     0
   pusha     3
   call      $PRINTVECTOR1,  1
   enter     0
   pusha     3
   call      $SORTVECTOR2,  1
   enter     0
   pushs     'the sorted numbers: '
   call      $WriteStri, 1
   enter     0
   call      $WriteLn, 0
   enter     0
   pusha     3
   call      $PRINTVECTOR1,  1
   return
