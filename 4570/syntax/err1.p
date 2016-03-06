{ missing program ident }
program ;
  var i, j: integer;
begin
  readln(i);             { get i }
  j := 9 + i * 8;        { evaluate j }
  write( 'Result is ' );
  write( j );            { print j }
  writeln
end.
