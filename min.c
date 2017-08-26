#include <stdlib.h>
#include <stdio.h>

void left_rotate(int *nums, int nums_size, int k);

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

   min = a[0];

   low = 1;
   upp = size - 1;

   while (low <= upp) {
      mid = (low + upp) >> 1; 

      if (a[mid] < min) {
         min = a[mid];
         upp = mid - 1;
      } else if (a[mid] > min) {
         low = mid + 1;
      } else {
         // equal
//         upp = mid - 1;
      }
   }
   return min;
}

void test(int size)
{
	int i, j;
	int *a;

	if (size < 1)
		return;

	a = (int *)malloc(size * sizeof(int));
	if (!a)
		return;

	for (i = 0; i < size; i++) {
		// initialize
		for (j = 0; j < size; j++)
			a[j] = j;

		// rotation
		left_rotate(a, size, i);
		for (j = 0; j < size; j++)
			printf("%2d ", a[j]);
		printf("\n");

		printf("min: %d\n\n", min_bin(a, size));
	}

	free(a);
}

int main(int argc, char *argv[])
{
   test(1);
   test(2);
   test(3);
   test(4);
   test(5);
   test(32);

   return 0;
}
