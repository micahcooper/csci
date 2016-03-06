{ Test 14 -- type mismatch in procedure parameter passing }
program intsort;

   type vector = array[1..10] of integer;
                 
   var a: vector;
       i: integer;

   procedure printvector( var b: vector );

     var i: integer;

   begin
     i := 1;
     while (i <= 5) do
       begin
         write('b[');
         write(i);
         write('] = ');
         write(b[i]);
         writeln;
         i := i + 1;
      end;
   end;

begin
  i := 1;
  while (i <= 10) do
    begin
       a[i] := i;
      i := i + 1
    end;

  write('the original input: ');
  writeln;
  printvector( 'hello' )

end.
