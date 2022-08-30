// Custom boilerplate: using configure user's snippet in the manage.
#include <stdio.h>

// void printArray(int A[], int n){
//     for(int i = 0;i<n;i++){
//         printf("%d ", A[i]);
//     }
// }
//**************************
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubblesortAdaptive(int A[], int n) // Will only run till the array is sorted.
{

    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    { // for number of passes.
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - i - 1; j++)
        { // for comparison in each pass.
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

void bubblesort(int A[], int n)
{

    for (int i = 0; i < n - 1; i++)
    { // for number of passes.
        for (int j = 0; j < n - i - 1; j++)
        { // for comparison in each pass.
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;

            }
        }
    }
}

int main()
{

    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {1,2,3,4,7,6};
    int n = 6;

    printArray(A, n); // Printing the array before sorting

    // bubblesort(A, n); // Function to sort the array.
    bubblesortAdaptive(A, n); // Function to sort the array Adaptively.

    printArray(A, n); // Printing after the sorting of array.

    return 0;
}