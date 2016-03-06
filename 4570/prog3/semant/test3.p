{ test program #3 }
program test2;
  var i: integer;
  procedure absolute( var n: integer );
  begin
    if n < 0 then
    begin
      n := - n;
    end;
  end;
begin
  readln(i); 
  absolute(i); 
  write(i); 
  writeln;

end.
