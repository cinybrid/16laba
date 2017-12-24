//in the pipeline

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
   int i,q;
   char c;


   do {
    printf ("write the quantity of massive\n");
    scanf ("%d", &q);
     }
        while (!((q>0) && (q<=100)));
   printf ("the quantity of the massive is %d", q);

   int a[q];

   printf ("do you want to set the value? y/n \n");
   scanf ("%c", &c);

   switch (c)  //vvod znachenii massiva
   {
    case 'y':
        for (i=1; i<=q; i++)
          do {
            printf ("a[%d] = ", i);
            scanf ("%d", &a[i]);
             }
    while (!(a[i]<0));
        break;
    case 'n':
     {
        srand (time(NULL));
        for (i=1; i<=q; i++)
     	a[i] = rand ();
     }

      break;
    default: printf ("dude wtf start over\n");
   }

   for (i=1; i<=q; i++)   // recap of massive
    printf ("%6d", a[i]);



}
