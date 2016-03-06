{ missing expr in assignment }
program sample1;
  var i, j: integer;
begin
  readln(i);             { get i }
  j := ;                 { evaluate j }
  write( 'Result is ' );
  write( j );            { print j }
  writeln
end.
