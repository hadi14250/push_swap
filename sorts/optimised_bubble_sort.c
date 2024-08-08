/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b)
{
    int tmp;
    
    tmp = *b;
    *b = *a;
    *a = tmp;
}

int main()
{
    int n;
    int j;
    int i;
    int flag = 0;
    int a[] = {0, 1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    
    i = 0;
    j = 0;
    printf ("before bubble sort\n");
    n = sizeof(a) / 4;
    while (i < n)
    {
        printf ("%d\n", a[i]);
        i++;
    }
    i = 0;
   while (i < n-1)
    {
        // we reset flag here eveytime we enter the loop
        flag = 0;
        j = 0;
        while (j < n-1-i)
        {
            if (a[j] > a[j + 1])
            {
                swap (&a[j], &a[j + 1]);
                flag = 1;   
            }
            j++;
        }
        // if flag didn't enter the if loop and got changed then no need to continue comparing
        if (flag == 0)
         break;
        i++;
    }
    printf ("after bubble sort:\n");
    i = 0;
    while (i < n)
    {
        printf ("%d\n", a[i]);
        i++;
    }
}