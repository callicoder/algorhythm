#include<cstdio>
/*
	Uniform random variable is a continuous random variable.
	
	A random variable X is said to be uniformly distributed over the interval
	[a, b] if its probability density function is given by
	
	f(x) = 1/(b - a), if a <= x <= b
		 = 0		  Otherwise

	cumulative distribution function : F(x) = [-inf to x] integral(f(x)dx)	
	
	F(x) = 0 , 			if -inf < x < a
		 = (x-a)/(b-a), if a <= x < b
		 = 1 ,			if b <= x < inf

	Expectation :
	E[x] = (a+b)/2

	Variance :
	Var(x) = ((a-b)^2)/12
*/
