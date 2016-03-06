{ a simple program with records }
program records;

  type complex = record
                   re, im: real
		 end;
		 
  procedure add( var a, b, c: complex );
  begin
    c.re := a.re + b.re;
    c.im := a.im + b.im;
  end;
  
  var a, b, c: complex;
  
begin

  readln( a.re );
  readln( a.im );
  readln( b.re );
  readln( b.im );
  
  add( a, b, c );
  
  write( 'Result is: (' );
  write( c.re );
  write( ', ' );
  write( c.im );
  write( ')' );
  writeln
end.

