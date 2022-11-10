#include <stdio.h>
#include <omp.h>
#include <stdbool.h>
#include <time.h>
int main()
{
    bool f = false;
    clock_t start, end;
    start = clock();
    #pragma omp parallel for
    for (int i = 2; i < 1000000; i++)
    {
        f = false;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                f = true;
                break;
            }
        }
        if (f == false)
        {
            // printf("%d", i);
        }
    }
    end = clock();
    printf("Parallel: %lf", (double)(end - start) / CLOCKS_PER_SEC);
    start=clock();
    for (int i = 2; i < 10000000; i++)
    {
        f = false;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                f = true;
                break;
            }
        }
        if (f == false)
        {
            // printf("%d", i);
        }
    }
    end=clock();
    printf("\nSerial: %lf", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}