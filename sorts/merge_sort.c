/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

void merge_recursion(int *a, int start, int mid, int high)
{
    int i;
    int j;
    int k;
	int *b;

	b = malloc (high);
    
    k = start;
    j = mid + 1;
    i = start;
    while (i <= mid && j <= high)
    {
        if (a[j] >= a[i])
        {
            b[k] = a[i];
            i++;
        }
        else 
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    i = start;
    while (i <= high)
    {
        a[i] = b[i];
        i++;
    }
	free (b);
}

void merge_sort (int *a, int start, int high)
{
    int mid;
    mid = (start + high) / 2;
    if (start < high)
    {
        merge_sort (a, start, mid);
        merge_sort (a, mid+1, high);
        merge_recursion(a, start, mid, high);
    }
}

int main()
{
    int n;
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,534,645,756,8,78,6754,6,4553,32,4657,86,9};
    n = sizeof (a) / sizeof(int);
    int i = -1;
    while (++i < n)
        printf ("%d ", a[i]);
        printf ("\n");
    i = -1;
    merge_sort (a, 0, n-1);
    i = -1;
    while (++i < n)
        printf ("%d ", a[i]);
}
