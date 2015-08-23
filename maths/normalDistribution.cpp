#include<cstdio>
/*
	Normal random variable is a continuous random variable

	Parameter : mu and sigma^2

	f(x) = { 1/[ σ * sqrt(2π) ] } * e^(-(x - μ)^2)/2σ^2,  -inf < x < inf

	Attains max value at x = μ => 1/(σ*sqrt(2*π))

	E[x] = μ
	Var(x) = σ^2

	If X is normal with mean mu and variance sigma^2 then 

	1. Y = aX + b is normal with mean a*μ + b and variance a^2 * σ^2

	And 
	2. Z = (X - μ)/σ
	   is a normal random variable with mean 0 and variance 1.
	   Such a random variable is said to have a standard or unit 
	   normal distribution.	
	   
	   the probability density function of the standard normal distribution is :
		
	   Phi(x) = 1/sqrt(2π) * e^(-(x^2)/2), -inf < x < inf
		
		

*/

/*
	
    1. The total area under the normal curve is equal to 1.

    2. The probability that a normal random variable X equals any particular value is 0.
	
    3. The probability that X is greater than a equals the area under the normal curve 
	   bounded by a and plus infinity.
	
    4. The probability that X is less than a equals the area under the normal curve 
	   bounded by a and minus infinity.

*/


