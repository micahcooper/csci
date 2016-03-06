program sample3;
  type vector = array[1..10] of real;
  var v:   vector;
      sum: real;
  procedure count( var v: vector; n: integer; var sum: real );
    var i: integer;  { local variables }
  begin
    i := 1;
    sum := 0.0;
    while ( i <= n )  do { set-up the loop }
    begin
      sum := sum + v[i];
      i := i + 1;
    end;
  end;
begin
  v[1] := 11;
  v[2] := 22.2e3;
  v[3] := 33.3e-1;
  v[4] := 44.9;
  count(v, 4, sum); { call procedure count }
  write(sum);       { write result }
  writeln;
end.
