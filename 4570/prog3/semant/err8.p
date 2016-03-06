{ error program #8 -- Type Mismatch parameters }

program test2;
  var i, sum: integer;
  procedure count( n: integer; var sum: integer; var d: real );
    var i: integer; 
  begin
    i := 1 ;
    d := 1.0 ;
    sum := 0 ;
    while ( i <= n ) do 
      begin
        sum := sum + i;
        i := i + 1 ;
       end
  end;

begin
  readln(i); 
  count(i, sum, sum); 
  write(sum); 
  writeln;

end.
