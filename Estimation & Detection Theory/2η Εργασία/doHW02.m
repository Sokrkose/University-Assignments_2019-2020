%This script calculates for a predetermined real vector X:
%-The optimal value of Z for min MAE (Z_opt)
%-The minimum Mean Absolute Error (J_min)

#Generating a 1x10 vector 
X=[-5.1 7 9.2 -16 28.3 -6.5 -22 -7.3 74 22.6] ;


#Calculating optimal Z
z=myFun01(X) ;
Z_opt=(z(1)+z(2))/2 
#We use the mean of the Z interval so we don't have to calculate it differently 
#for odd or even length of X

#Calculating min MAE
J_min=MAE(Z_opt,X)

