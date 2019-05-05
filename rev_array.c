#include <stdio.h>

void reverse_array(int *arr, int size);
int array_size(int *arr);
int total_array(int *arr, int len);

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
  printf("Therefore, the length is %ld\n", sizeof(arr) / sizeof(int));
  int size = sizeof(arr) / sizeof(int);
  int *p = arr;
  reverse_array(p, size);
  int total = total_array(arr, size);
  printf("total of array is %d\n", total);

  return 0;

}

void reverse_array(int *arr, int size)
{
  /* printf("array is %d\n", *arr); */
  /* printf("second is %d\n", *(arr + 1)); */
  /* printf("length of array is %d\n", array_size(arr)); */
  /* int i = array_size(arr); */
  /* printf("i is %d\n", i); */
  int *begin, *end;
  printf("size is %d\n", size);
  printf("size of arr is %ld\n", sizeof(*arr));
  printf("total is %p\n", arr + size);
  /* what would happen if we tried to assign to an int instead of
    a pointer? */
  printf("begin and end are now initialized.\n");
  /* attempting to access the unitialized pointers causes 
     a seg fault */
  /* noo - it's not that they're uninitialized. it's that they
     don't have pointees. you can access unitialized data and get
     garbage back, but you can't access memory you haven't allocated */
  begin = arr;
  end = (begin + size - 1);
  /* the above line works, but why don't we need to use
     begin + sizeof(int)? is it because end is an int
     pointer, so it knows every move to advance by four bytes?
     I think that's exactly the reason. */
  /* printf("begin is at address %p and stores value %d\n", begin, *begin); */
  /* printf("end is at address %p and stores value %d\n", end, *end); */

  for (int i = 0; i< size; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");

  while (end > begin) {
    /* printf("begin is %d\n", *begin); */
    /* printf("end it %d\n", *end); */
    int tmp = *begin;
    *begin = *end;
    *end = tmp;
    end--;
    begin++;
  }
  printf("reversed array:\n");
  for (int i = 0; i< size; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
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

int total_array(int *arr, int len)
{
  int total = 0;
  for (int i = 0; i < len; i++) {
    total += *(arr + i);
  }
  return total;
}
