function out1 = EquationFunc (A, b, X_k, delta)

  temp = A*X_k - b;
  out1 = X_k - delta*(A')*temp;
  
endfunction
