#include<stdio.h>
#include<omp.h>

int main(){
    int i,n, sum=0;
    scanf("%d", &n);
    int arr[n];
    srand(42);
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }
    omp_set_num_threads(4);
    int ID;
    int idsum[4];
    #pragma omp parallel
    {
        ID=omp_get_thread_num();
        idsum[ID]=0;
        #pragma omp for
        for(i=0;i<n;i++)
            idsum[ID]+=arr[i];
        printf("id: %d, Sum of this id, %d\n", ID, idsum[ID]);
    } 
    for(int i=0;i<4;i++){
        sum+=idsum[i];
    }
    printf("Sum: %d", sum);
    return 0;
}