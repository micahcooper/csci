#!/bin/csh -f
onintr -
#
set PGM=$1
set DIR=/home/work/csx570/TEST.pascal
#
echo ------------------
echo parsing Test1 correct
$PGM ${DIR}/semant/test1.p
echo ------------------
echo parsing Test2 correct
$PGM ${DIR}/semant/test2.p
echo ------------------
echo parsing Test3 correct
$PGM ${DIR}/semant/test3.p
echo ------------------
echo parsing ERROR No1:Line 9: Incompatible types in assignment
$PGM ${DIR}/semant/err1.p
echo ------------------
echo parsing ERROR No2:Line 19: Too many parameters in procedure call
$PGM ${DIR}/semant/err2.p
echo ------------------
echo parsing ERROR No3:Line 7: Undeclared variable: i
$PGM ${DIR}/semant/err3.p
echo ------------------
echo parsing ERROR No4:Line 5: Multiple declarations of i
$PGM ${DIR}/semant/err4.p
echo ------------------
echo parsing ERROR No5:Line 9: Incompatible types in addition
$PGM ${DIR}/semant/err5.p
echo ------------------
echo parsing ERROR No6:Line 19: Actual parameter with no l-value
$PGM ${DIR}/semant/err6.p
echo ------------------
echo parsing ERROR No7:Line 21: writeln called with a parameter
$PGM ${DIR}/semant/err7.p
echo ------------------
echo parsing ERROR No8:Line 19: Type mismatch in procedure call
$PGM ${DIR}/semant/err8.p
echo ------------------
echo parsing ERROR No9:Line 14: Non-Boolean expression used in a while stmt
$PGM ${DIR}/semant/err9.p
echo ------------------
echo parsing ERROR No10: Line 4: Unknown type in declaration of variable
$PGM ${DIR}/semant/err10.p
echo ------------------
echo parsing ERROR No11: Line 8: Invalid type in array index
$PGM ${DIR}/semant/err11.p
echo ------------------
echo parsing ERROR No12: Line 6: Unknown function return type
$PGM ${DIR}/semant/err12.p
echo ------------------
echo parsing ERROR No13: Line 15: Incompatible type in array element assignment
echo skipping, causes infinite loop.
echo ------------------
echo parsing ERROR No14: Line 36: Type mismatch in parameter passing
$PGM ${DIR}/semant/err14.p
echo ------------------
echo parsing ERROR No15: Line 6: Incompatible type in assignment of function value
$PGM ${DIR}/semant/err15.p
