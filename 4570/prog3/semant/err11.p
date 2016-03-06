{ Test 11 -- Invalid type in array index }
program err;
  type vector =  array[1..10] of real;
  var v  : vector;
      sum :  real;
begin
   v[1] := 11;
   v[2.1] := 22.2e3;
   writeln;
end.
