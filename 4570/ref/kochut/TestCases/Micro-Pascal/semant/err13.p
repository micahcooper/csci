{ Test 13 -- type mismatch in array assignment }
program intsort;
   type vector = array[1..10] of integer;
                 
   var a: vector;
       i: integer;

begin
  i := 1;
  while i <= 10 do
    begin
      if i > 5 then
	a[i] := i
      else
        a[i] := 'a string';
      i := i + 1
    end;
end.
