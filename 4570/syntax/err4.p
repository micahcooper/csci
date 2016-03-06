{ missing type in var decl }
program sample1;
  var i, j: ;
begin
  readln(i);             { get i }
  j := 9 + i * 8;        { evaluate j }
  write( 'Result is ' );
  write( j );            { print j }
  writeln
end.
