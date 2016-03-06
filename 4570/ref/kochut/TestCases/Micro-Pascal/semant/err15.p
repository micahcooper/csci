{ Test 15 -- Incompatible type in assignment of function value }
program test;
  var x: real;
  function foo( n: real ): real;
  begin
     foo := n < 10;
  end; { foo }
begin
   x := foo( 10.1 );
   writeln
end.
