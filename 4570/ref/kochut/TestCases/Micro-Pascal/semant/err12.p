{ Test 12 -- Unknown function return type }
program test;

  var n: integer;

  function fact( n: integer ): int;
  begin
    if ( n <= 1 ) then
      fact := 1
    else
      fact := n * fact( n-1 );
  end; { fact }

begin
   write('Enter an integer: ');
   readln(n);
   write('Factorial of ');
   write(n);
   write(' is ');
   write( fact(n) );
   writeln
end.
