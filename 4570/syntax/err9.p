{ missing do after while }
program sample2;
  var i, sum: integer;
  procedure count( n: integer; var sum: integer );
    var i: integer; { local variable }
  begin
    i := 1;
    sum := 0;
    while ( i <= n ) 
      begin
        sum := sum + i;
        i := i + 1;
       end
  end;
begin
  readln(i);     { get i }
  count(i, sum); { call count }
  write(sum);    { write result }
  writeln;
end.
