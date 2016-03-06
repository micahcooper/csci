{ missing expression in array reference }
program intsort;

   type vector = array[1..10] of integer;

   var a: vector;
       i: integer;

begin

  i := 1;
  while (i <= 5) do
    begin
      write('enter an integer for sorting: ');
      readln(a[ ]);
      i := i + 1;
    end;

end.
