#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x)
{
    double return_val;
    return_val = x * x;
    return return_val;
}
/*
Approximate function for pi
double pi(double x){
    double return_val;
    return_val = 4.0/(1.0 + x*x);
}
*/
double Trap(double a, double b, int n, int thread_count)
{
    double h, approx;
    int i;
    h = (b - a) / n;
    approx = (f(a) + f(b)) / 2.0;
#pragma omp parallel for num_threads(thread_count) reduction(+: approx) schedule(dynamic)
    for (i = 1; i <= n - 1; i++)
    {
        approx += f(a + i * h);
    }
    approx = h * approx;
    return approx;
}

int main(){
    double result=0.0, a, b;
    int n, thread_count=4;
    scanf("%lf %lf %d", &a, &b, &n);
    result=Trap(a, b, n, thread_count);
    printf("a = %lf , b=%lf, result= %14e\n", a,b, result);
    return 0;
}