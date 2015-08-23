/*
	Exponential random variable is a continuous random variable

	1. Two parameter exponential random variable :
	
	f(x) = (1/b)* e^(-(x-a)/b), x >= a
		 = 0, 					otherwise

	F(x) = 1 - e^(-(x-a)/b), if x >= a
		 = 0,				 elsewhere
 
	
	2. One parameter exponential random variable :
	putting a = 0 and b = 1/lambda

	f(x) = lambda * e^(-lambda*x), if x >= 0
		 = 0, 					   if x < 0

	F(x) = 1 - e^(-lambda*x), x >= 0
		 = 0, 				  elsewhere

	E[x] = 1/lambda

	Var(x) = 1/lambda^2
*/
