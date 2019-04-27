#include <stdio.h>

void reverse_array(int *arr, size_t size);
int array_size(int *arr);

int main(void)
{
  /* if you create an array in array notation, how do you
     access it with a pointer? or can you not?

     only strings are null terminated, so we can't look for \0.
     i guess we just have to pass the length? what if we set a pointer
     equal to the array?
     */

  int arr[] = {1, 2, 3, 42, 4, 5, 6, 7};
  printf("length of array is %ld\n", sizeof(arr) / sizeof(int));
  // this doesn't work...how do you determine the types in an array?
  /* printf("type of array is %s", typeof (arr[0])); */

  /* with a local array declared with [], we can do this */
  printf("size of arr is %ld\n", sizeof(arr));
  printf("size of an int is %lu\n", sizeof(int));
  printf("Therefore, the size is %ld\n", sizeof(arr) / sizeof(int));
  int size = sizeof(arr) / sizeof(int);
  int *p = arr;
  reverse_array(p, size);

}

void reverse_array(int *arr, size_t size)
{
  /* printf("array is %d\n", *arr); */
  /* printf("second is %d\n", *(arr + 1)); */
  /* printf("length of array is %d\n", array_size(arr)); */
  /* int i = array_size(arr); */
  /* printf("i is %d\n", i); */
  for (int i = 0; i< size; i++) {
    printf("%d\n", *(arr + i));
  }
}

/* I don't think a function like this can work since arrays
   aren't null-terminated? */
int array_size(int *arr)
{
  int i;
  printf("int size is %lu\n", sizeof(int));
  for(i = 0; *(arr + i) != '\0'; i++)
    printf("%d\n", *(arr + i));
  return i;
}

/* aha! here we go: https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
   so we have to always pass a parameter with the size of the array */
