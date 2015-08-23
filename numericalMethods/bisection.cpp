#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
#define ESP 0.001

int degree;
vector<double> coef;

double f(double x)
{
	double fx = 0.0;
	for(int i = 1; i <= degree; i++)
		fx += coef[i] * (pow(x,i));
	fx += coef[0];
	return fx;
}

void bisection(double x0, double x1, int iter)
{
	printf("\n__________________________________________________________________\n");
    	printf("\niteration    x0\t\tx1\t  x2\t   f0\t    f1\t      f2");
    	printf("\n__________________________________________________________________\n");
	double x2;
	double f0,f1,f2;
	for(int i = 0; i <= iter; i++)	// Alternatively, We can also check the approximation error
	{								// and iterate while(fabs(f2) > ESP)
		x2 = (x0 + x1)/2;
		f0 = f(x0);
		f1 = f(x1);
		f2 = f(x2);

		printf("\n%7d\t %f %f %f %lf %lf %lf", i, x0,x1,x2,f0,f1,f2);

		if(f0*f2 < 0)
			x1 = x2;
		else	
			x0 = x2;
	}
	printf("\n__________________________________________________________\n");
	printf("\n\nApp.root = %f\n",x2);
}

int main()
{
	printf("Enter the degree of the polynomial : ");
	scanf("%d",&degree);
	double c;
	for(int i = 0; i <= degree; i++)
	{
		printf("\n\t x^%d :: ", i);
		scanf("%lf",&c);
		coef.push_back(c);
	}
	printf("\n");
	printf("The polynomial is ::: \n");
	
	for(int i = degree; i > 0; i--)
		printf("(%lf)x^%d + ",coef[i],i);
	printf("(%lf)x^%d\n",coef[0],0);
	printf("\n");

	double x0;
	printf("Enter the first approximation to the root : ");
    	scanf("%lf",&x0);
	double x1;
    	printf("Enter the second approximation to the root : ");
    	scanf("%lf",&x1);
	int iter;
	printf("Enter the number of iterations you want to perform : ");
    	scanf("%d",&iter);

	bisection(x0, x1, iter);
	
	return 0;
}
