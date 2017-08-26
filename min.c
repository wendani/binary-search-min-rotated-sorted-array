#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int (*min_func_t)(int a[], int size);

void left_rotate(int *nums, int nums_size, int k);


// linear search
int min_element(int a[], int size)
{
   int i;
   int min = a[0];

   for (i = size - 1; i > 0 && a[i] < min; i--)
         min = a[i];

   return min;
}

// binary search
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
      } else {
	 // a[mid] > min
	 // equal case must not happen
	 // because all elements must be distinct
	 assert(a[mid] != min);

	 low = mid + 1;
      }
   }
   return min;
}

// binary search improved
// remove the use of min to keep track of the minimum value
int min_bin_imprv(int a[], int size)
{
	int low, upp, mid;

	low = 0;
	upp = size - 1;
	while (a[low] > a[upp]) {
		mid = (low + upp) >> 1;

		if (a[mid] >= a[low]) {
			if (a[mid] == a[low])
				assert(mid == low);
			low = mid + 1;
		} else {
			// a[mid] < a[low]
			assert(a[mid] < a[upp]);
			upp = mid;
		}
	}
	return a[low];
}

// test harness
void test(int size, min_func_t min)
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

		printf("min: %d\n\n", min(a, size));
	}

	free(a);
}

int main(int argc, char *argv[])
{
   int i, size;
   int a[] = {0, 1, 0};

   printf("linear search\n");
   test(1, min_element);
   test(2, min_element);
   test(3, min_element);
   test(4, min_element);
   test(5, min_element);

   printf("binary search\n");
   test(1, min_bin);
   test(2, min_bin);
   test(3, min_bin);
   test(4, min_bin);
   test(5, min_bin);
   test(32, min_bin);

   printf("binary search improved\n");
   test(1, min_bin_imprv);
   test(2, min_bin_imprv);
   test(3, min_bin_imprv);
   test(4, min_bin_imprv);
   test(5, min_bin_imprv);
   test(32, min_bin_imprv);

   // test assert when equal elements are found
#if 0
   size = sizeof(a) / sizeof(int);
   for (i = 0; i < size; i++)
      printf("%2d ", a[i]);
   printf("\n");
   printf("min: %d\n", min_bin(a, size));
#endif

   return 0;
}
