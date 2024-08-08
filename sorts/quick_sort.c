#include <stdio.h>

void swap (int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int *a, int low, int high)
{
    // sway array is [0] [5] [6] [1] [2]
    // pivot is on first entry is [2]
    // second entry will be the index of pivot after first sort for ex:
    // after first sort array is [0] [1] [6] [5] [2] because we swap 1 with 5 as per below if loop
    // after the swap after the while loop the array will be: [0] [1] [2] [5] [6]; and we return index of the [2] which is 2
    int pivot_value = a[high];
    int j;
    int i;
    i = low;
    j = low;
    while (j < high)
    {
        // pivot value is always the last element of the array that is of size high
        if (a[j] <= pivot_value)
        {
            swap (&a[j], &a[i]);
            i++;
        }
        j++;
    }
    swap (&a[i], &a[high]);
    return (i);
}

void sort_recursion (int *a, int low, int high)
{
    int pivot_index;
    if (low < high)
    {
        pivot_index= partition (a, low, high);
        // if for example pivot_index is 0, the next function will enter and will exit on the if loop as condition won't be met
        sort_recursion (a, low, pivot_index-1);
        sort_recursion (a, pivot_index+1, high);
    }
}

void quicksort (int *a, int size)
{
    sort_recursion (a, 0, size-1);
}

int main()
{
  int a[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 23, 3,123,321 ,9866162,21,69420,3,213,21,3,21,321, 3,21321, 23,125565,7,4656,54,43, 1, 0};
  int n = sizeof (a) / sizeof (int);
  int i = -1;
  printf ("before quicksort:\n");
  while (++i < n)
    printf ("%d ", a[i]);
    printf ("\n");
    quicksort (a, n);
  printf ("after quicksort:\n");
  i = -1;
  while (++i < n)
    printf ("%d ", a[i]);
    printf ("\n");
  
}