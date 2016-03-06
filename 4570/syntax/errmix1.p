{ error mix: progname, type in var decl, param type, expr in assign }
program ;
  var i, sum: ;
  procedure count( n: integer; var sum: );
    var i: integer; { local variable }
  begin
    i := 1;
    sum := 0;
    while ( i <= n ) do { set-up the loop }
      begin
        sum := sum  i;
        i := i + 1;
       end
  end;
begin
  readln(i);     { get i }
  count(i, sum); { call count }
  write(sum);    { write result }
  writeln;
end.
