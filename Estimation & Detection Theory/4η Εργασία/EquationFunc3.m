function f = EquationFunc3 (A, b)
  
  f = ((A')*A).^(-1)*(A')*b;
  
endfunction
