#include<omp.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

static long steps=1e9;
double step;

int main(){
    int i,j;
    double x;
    double pi,sum=0.0, start, delta;
    step=1.0/(double) steps;

    #pragma omp parallel for reduction(+:sum) private(x)
    for(i=0;i<steps;i++){
        x=(i+0.5)*step;
        sum+=4.0/(1.0+ x*x);
    }
    pi = step*sum;
    printf("%lf", pi);
}
