// Custom boilerplate: using configure user's snippet in the manage.
#include<stdio.h>


void selectionSort(int *A, int n){
    for(int i = 0;i<n;i++){
        int min = 100;
        for(int j = i;j<n;j++){
            if(A[j]<min){
                min = A[j];
            }
            int temp = A[i];
            A[j] = temp;
            A[i] = min;
            
        }
        
        
    }
}
void printArray(int *A, int n){
    for(int i = 0;i<n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}


int main(){

    int A[] = {8,0,7,1,3};
    int n = 5;

    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}