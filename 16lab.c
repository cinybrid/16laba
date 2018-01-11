#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    // function of hoar sort
    void quickSort(int *numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right)
    {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}


int main ()
{
   int i,q,n,j,c,k,m,p;

    do {
            fflush(stdin);
    printf ("write the quantity of massive\n");
    scanf ("%d", &q);
     if (!((q>0) && (q<=100)))
        printf ("value should be from 1 to 100 restart the code\n");
    } while (!((q>0) && (q<=100)));

   int a[q];

   printf ("do you want to set by yourself the values? y(1)/n(2) \n");
   scanf ("%d", &c);

   if  (c == 1)
        for (i=1; i<=q; i++)
           {
            printf ("a[%d] = ", i);
            scanf ("%d", &n);
             a [i] = n;
             }
    if (c == 2)
     {
        srand (time(NULL));
        for (i=1; i<=q; i++)
     	a[i] = rand ()%100;
     }
   for (i=1; i<=q; i++)   // recap of massive
    printf ("%6d", a[i]);
    printf ("\n");

    //sort of bubble
    for (i=1; i<=q; i++)
        for (j=1; j<=q-1; j++)
           if (a[i]<a[j])
    {
        k = a[j];
        a[j] = a[i];
        a[i] = k;
    }
    for (i=1; i<=q; i++)   // recap of massive
    printf ("%6d", a[i]);

    //hoar sort function call
   quickSort(a, 1, q-1);
   printf ("\n");
   for (i=1; i<=q; i++)
     printf ("%6d", a[i]);


   // m max and n min
   printf ("\n");
   printf ("write M-max and P-min that you want to find\n");
   scanf ("%d %d", &m, &p);
   quickSort(a, 0, q-1);
   printf ("your max is %d\n", a[q-m+1]);
   printf ("your min is %d\n", a[p]);

   // deleting double members
   int b[q];
   i=2, j=2;
   b[1]=a[1];
   quickSort(a, 1, q-1);
   while (i<=q)
   {
       if (a[i]!=b[j-1])
       {
           b[j]=a[i];
           j++;
       }
       i++;
   }

   for (i=1; i<=j-1; i++)
   printf ("%6d", b[i]);

}
