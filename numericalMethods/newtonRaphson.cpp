#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
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

double df(double x)
{
	double dfx = 0;
	for(int i = 1; i <= degree; i++)
	{
		dfx += coef[i] * (i * pow(x, i-1));
	}
	return dfx;
}

void newtonRaphson(double x0, int iter, double err)
{
	printf("\n ******************************************************");
    printf("\n ITERATION    X0    FX0    F'X0  X1");
    printf("\n **********************************************************");
	double fx0, dfx0, x1, h;
	for(int i = 0; i <= iter; i++)
	{
		fx0 = f(x0);
		dfx0 = df(x0);
		h = fx0/dfx0;
		x1 = x0 - h;
		if(fabs(h) < err) //If the difference between the 2 approximations is below the max error
			break;
		x0 = x1;
		printf("\n %d   %lf        %lf  %lf  %lf ",i,x0,fx0,dfx0,x1);
	}				
	printf("\n__________________________________________________________\n");
	printf("\n\nApp.root = %f\n",x1);
		
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

	printf("Enter the first approximation, the max error and the number of iterations\n");
	double x0, err;
	int iter;
	scanf("%lf%lf%d",&x0,&err,&iter);
	newtonRaphson(x0, iter, err);
	return 0;
}
