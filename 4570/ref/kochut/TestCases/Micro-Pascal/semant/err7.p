{ error program #7 -- writeln call }

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
  count(i, sum); 
  write(sum); 
  writeln( 'oops' );

end.
