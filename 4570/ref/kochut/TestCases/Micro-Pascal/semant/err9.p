{ error program #9 -- Non-Boolean expression used in a while stmt }

program test2;
  var i, sum: integer;
  var d: real;
  
  procedure count( n: integer; var sum: integer; var d: real );
    var i: integer; 
  begin
    i := 1 ;
    d := 1.0 ;
    sum := 0 ;
    while ( 'test' ) do 
      begin
        sum := sum + i;
        i := i + 1 ;
        d := d + 1.0 ;
       end
  end;

begin
  readln(i); 
  count(i, sum, d); 
  write(sum); 
  writeln;

end.
