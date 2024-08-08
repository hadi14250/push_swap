
#include <stdio.h>

void swap (int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a[] = {7, 4, 10, 8, 3, 1};
    int min;
    int i;
    int j;
    int n;
        
    n = sizeof (a) / 4;
    printf ("after sort:\n");
    i = -1;
    while (++i < n)
        printf ("%d\n", a[i]);
    
    i = 0;
    j = i + 1;
    //unlike insertion sort, index of j will be one element after index
    // we will look for the least element and swap it with i
    while (i < n-1)
    {
        min = i;
        j = i + 1;
        while (j < n)
        {
            //we keep on looking for the least element until the end of the array
          if (a[min] > a[j])
            min = j;
          j++;
        }
        // if min value is changed, that means there is a new least element so we swap
        if (min != i)
          swap (&a[i], &a[min]);
          i++;
    }
    printf ("after sort:\n");
    i = -1;
    while (++i < n)
        printf ("%d\n", a[i]);
    
}
