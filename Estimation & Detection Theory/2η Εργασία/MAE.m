function J=MAE(Z,X)
  %This function calculates the Mean Absolute Error of a real vector(dataset) 
  %X with respect to the real variable Z.
 
  f=@(z,x,i) abs(x(i)-z) ;
  N=length(X);
  
  J=sum(f(Z,X,[1:N]))/N;
 endfunction