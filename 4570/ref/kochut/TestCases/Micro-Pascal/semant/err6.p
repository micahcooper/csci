{ error program #6 -- Actual parameter with no l-value passed }

program test2;
  var i, sum: integer;
  procedure count( n: integer; var sum: integer );
    var i: integer; 
  begin
    i := 1 ;
    sum := 0 ;
    while ( i <= n ) do 
      begin
        sum := sum + i ;
        i := i + 1 ;
       end
  end;

begin
  readln(i); 
  count(i, sum + 1);
  write(sum); 
  writeln;

end.
