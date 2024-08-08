#include <stdio.h>

void swap (int *a, int *b)
{
    int  temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int i;
    int j;
    int n;
    int a[] = {100, 3232, 324, 6657 ,767,65, 4, 10, 1, 12, 32, 2 , 3, 4, 6, 54 , 7, 2, 8, 9, 2, 12, 21,332, 32 ,32, 32, 32};
    i = 0;
    n = sizeof (a) / 4;
    int temp;
    
    i = 1;
    while (i < n)
    {
        // store a[1] in temp then begin comparison with the sorted array (j--)   
        temp = a[i];
        // j is always oneindex less than i
        j = i - 1;
        // is the index before i greater? if yes then enter the loop and shift it to the right
        while (j >= 0 && a[j] > temp)
        {
            //switch the greater index to the right
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
        i++;
    }
    
    
    i = 0;
    while (i < n)
    {
        printf ("%d ", a[i]);
        i++;
    }
}