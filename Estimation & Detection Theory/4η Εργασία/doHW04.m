clc;
clear;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

A1 = [1 2 3 4 5];
A2 = [6 7 8 9 10];
A3 = [5 4 2 7 8];
A4 =[6 1 2 12 9];
A = [A1' A2'];

b = [1 2 3 4 5]';

X0 = [0 0]';

delta = 1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

X_kapelo = EquationFunc3(A, b);

X1 = EquationFunc(A, b, X_kapelo, delta);

A = [A1' A2' A3' A4'];

b = [1 2 3 4 5]';

N = 2;
M= 4;
X2 = EquationFunc2(A, b, X0, N,M)

X2_1  = (A'*A)\(A'*b)
a = (A'*A)*X2 - (A'*b)
a_1 = (A'*A)*X2_1 - (A'*b)

