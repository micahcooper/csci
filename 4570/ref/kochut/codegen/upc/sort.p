{ sort -- on an array of integers }
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
	 write('value ');
	 write(i);
	 write(' = ');
	 write(b[i]);
	 writeln;
         i := i + 1;
      end;
   end;

   procedure sortvector( var c: vector );

     var i, j, temp: integer;

   begin
      i := 1;
      while (i < 5) do
        begin
          j := i + 1;
	  while (j < 6) do
	    begin
	      if (c[i] > c[j]) then
	        begin
	          temp := c[i];
	          c[i] := c[j];
	          c[j] := temp;
                end;
              j := j + 1;
            end;
          i := i + 1;
        end;
   end;

begin
  write('Please enter 5 integers for sorting.');
  writeln;  
  writeln;

  i := 1;
  while (i <= 5) do
    begin
      write('enter an integer for sorting: ');
      readln(a[i]);
      i := i + 1;
    end;

  write('the original input: ');
  writeln;
  printvector(a);
  sortvector(a);
  write('the sorted numbers: ');
  writeln;
  printvector(a)
end.
