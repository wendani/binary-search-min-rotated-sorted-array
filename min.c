#include <stdlib.h>
#include <stdio.h>

#if 0
int min_element(int a[], int size)
{
   int i;
   int min = a[0];

   for (i = size - 1; i > 0; i--)
      if (a[i] < min)
         min = a[i];
      else
         return min;
}
#endif

int min_bin(int a[], int size)
{
   int min, low, upp, mid;

   if (size == 1)
      return a[0];

   min = a[0];

   low = 1;
   upp = size - 1;

   while (low <= upp) {
      mid = (low + upp) >> 1; 

      if (a[mid] < min) {
         min = a[mid];
         upp = mid - 1;
      }
      else if (a[mid] > min) {
         low = mid + 1;
      } else {
         // equal
//         upp = mid - 1;
      }
   }
   return min;
}

int main(int argc, char *argv[])
{

   int a[] = {4, 5, 6, 7, 0, 1, 2, 3};
   int b[] = {1};
   int c[] = {2, 1};
   printf("min: %d\n", min_bin(c, 2));

   return 0;
}
