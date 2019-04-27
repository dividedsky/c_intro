#include <stdio.h>

void reverse_array(int *arr);
int main(void)
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  printf("length of array is %ld\n", sizeof(arr) / sizeof(int));
  // this doesn't work...how do you determine the types in an array?
  /* printf("type of array is %s", typeof (arr[0])); */
  reverse_array(arr);

}

void reverse_array(int *arr)
{
  printf("array is %d\n", *arr);
  printf("length of array is %ld\n", sizeof(*arr) / sizeof(int));
}

