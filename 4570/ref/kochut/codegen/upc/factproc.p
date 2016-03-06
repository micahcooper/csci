program factproc;
  var i, n: integer;
  procedure fact( i: integer;  var n: integer );
  begin
    if ( i <= 1 ) then
      n := 1
    else begin
      fact( i - 1, n );
      n := n * i
    end
  end;
begin
  write('Enter an integer: ');
  readln(i);
  fact(i, n);
  write('Factorial of ');
  write(i);
  write(' is ');
  write(n);
  writeln
end.
