#include<cstdio>
#include<cmath>

/*
	Poisson Random variable is a discrete random variable.

	Probability Mass function
	P(X = i) = e^(-lambda) * (lambda)^i/i!

	computing the poisson distribution function
	P(X = i+1)/P(X = i) = lambda/(i+1)

	Expectation:
	E[X] = lambda

	Variance:
	Var(X) = lambda

*/
void computeProbability(double lambda, int i)
{
	double P[i+1];
	P[0] = exp(-lambda);
	double sum = P[0];
	for(int k = 1; k <= i; k++)
	{
		P[k] = (lambda/k) * P[k-1];
		sum += P[k];
	}
	printf("Probability(X = %d) : %lf\n",i,P[i]);

	// Cumulative distribution function or distribution function of poisson 
	// random variable F(x) = P(X <= x):
    // F(i) = P(X <= i)
	printf("Probability(X <= %d) : %lf\n",i,sum);
}

inline double computeExpectation(double lambda)
{
	return lambda;
}

inline double computeVariance(double lambda)
{
	return lambda;
}

int main()
{
	double lambda;
	printf("Enter the value of the parameter \"lambda\" : ");
	scanf("%lf",&lambda);
	int i;
	printf("Enter the value of i : ");
	scanf("%d",&i);
	computeProbability(lambda, i);
	printf("Expectation of poisson random variable : %lf\n",computeExpectation(lambda));
	printf("Variance of poisson random variable : %lf\n",computeVariance(lambda));
	return 0;
}
