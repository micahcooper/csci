{ test program #2 -- correct }
program test2;
  var i: integer;
      j: real;
begin
  readln(i); 
  if (i < 20 ) then
    begin
      j := 9 + i * 8.3e3 ;  
      write( 'Result is ' );
      write( j ); 
      writeln;
    end
  else
    begin
      write ( 'Oops!' );
      writeln;
    end
end.
