
function optimal_Z=myFun01(X)
%This function calculates optimal Z in order to minimize the Mean Absolute Error 
%given a real dataset of length N which proves to be the median of the set.
  
X=sort(X) ;
left_z=X(floor((length(X)+1)/2)) ;
right_z=X(ceil((length(X)+1)/2)) ;
optimal_Z=[left_z , right_z] ;
endfunction
