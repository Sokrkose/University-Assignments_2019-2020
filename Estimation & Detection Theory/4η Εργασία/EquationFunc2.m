function out = EquationFunc2 (A, b, X, N, M)
  An = A(1:N, :);
  bn = b(1:N);
  Gn = An'*An;
  hn = An'*bn;
  xn = Gn\hn;
  
  xm = xn;
  Gm=Gn ;
  hm =hn;
  for i=N+1:M
      Gm = Gm + A(i,:)'*A(i,:);
      hm = hm + A(i,:)'*b(i);
      
  end
  xm = Gm\hm;
  out = xm;
  
endfunction