{ Error #5 -- Invalid type in addition }

program test2;
  var i, sum: integer;

begin
  readln(i); 

  sum := 14 + 'hello';

  write(sum); 

  writeln;

end.
