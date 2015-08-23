#include<cstdio>
#include<cmath>

/*
	Binomial Random variable is a discrete Random Variable.

	Probability Mass Function :
	P(X = i) = C(n,i)* (p^i) * (i-p)^i 

	computing the binomial distribution function :
	P(X = k+1) = p/(1-p) * (n-k)/(k+1) * P(X = k)

	Expectation :
	E[X] = np
	
	Variance :
	Var(X) = np(1-p)
*/
void computeProbability(int n, double p, int i)
{
	double P[n+1];
	P[0] = pow((1-p), n);
	double sum = P[0];
	for(int k = 1; k <= i; k++)
	{
		P[k] = p/(1-p) * (n-k+1)/(k)*P[k-1];
		sum += P[k];
	}
	printf("Probability (Number of success = %d) : %lf\n",i,P[i]);

	// Cumulative distribution function or distribution function of 
	// binomial random variable F(x) = P(X <= x):
	// F(i) = P(X <= i)
	printf("Probability (Number of success <= %d): %lf\n",i,sum);
}

inline double computeExpectation(int n, double p)
{
	return n*p;
}

inline double computeVariance(int n, double p)
{
	return n*p*(1-p);
}

int main()
{
	int n;
	printf("Enter the value of n : ");
    scanf("%d",&n);
	double p;
	printf("Enter the value of p : ");
	scanf("%lf",&p);
	int i;
	printf("Enter the value of i : ");
	scanf("%d",&i);

	computeProbability(n, p, i);
	printf("Expectation of binomial random variable X : %lf\n",computeExpectation(n,p));
	printf("Variance of binomial random variable X : %lf\n",computeVariance(n,p));
	return 0;
}
