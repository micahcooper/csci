{ missing function return type }
program test;

  var n: integer;

  function fact( n: integer ):  ;

  begin
    if ( n <= 1 ) then
      fact := 1
    else
      fact := n * fact( n-1 );
  end;

begin
  write('Enter an integer: ');
  readln(n);
  write('Factorial of ');
  write(n);
  write(' is ');
  write(fact(n));
  writeln
end.
