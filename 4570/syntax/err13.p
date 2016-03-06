{ missing right bound in array type decl }
program intsort;

   type vector = array[1..] of integer;

   var a: vector;
       i: integer;

begin

  i := 1;
  while (i <= 5) do
    begin
      write('enter an integer for sorting: ');
      readln(a[i]);
      i := i + 1;
    end;

end.
