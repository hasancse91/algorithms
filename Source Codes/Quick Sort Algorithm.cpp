#include <stdio.h>
#include <stdbool.h>
#define MAX 8

int arr[MAX] = {2,7,1,8,6,3,5,4};

void printline(int count) {
   int i;

   for(i = 0;i <count-1;i++) {
      printf("=");
   }

   printf("=\n");
}

void display() {
   int i;
   printf("[");

   // navigate through all items
   for(i = 0;i<MAX;i++) {
      printf("%d ",arr[i]);
   }

   printf("]\n");
}

void swapFunction(int leftIndex, int rightIndex) {
   int temp = arr[leftIndex];
   arr[leftIndex] = arr[rightIndex];
   arr[rightIndex] = temp;
}

int partitionFunction(int left, int right, int pivot) {
   int leftPointer = left -1;
   int rightPointer = right;

   while(true) {

    printf("Left to right: ");
      while(arr[++leftPointer] < pivot) {
         //do nothing
         printf("%d ", arr[leftPointer-1]);
      }
      puts("");

    printf("Right to left: ");
      while(rightPointer > 0 && arr[--rightPointer] > pivot) {
         //do nothing
         printf("%d ", arr[rightPointer+1]);
      }
      puts("");

      if(leftPointer >= rightPointer) {
         break;
      } else {
         printf(" item swapped: a[%d]: %d, a[%d]: %d\n", leftPointer, arr[leftPointer], rightPointer, arr[rightPointer]);
         swapFunction(leftPointer,rightPointer); //swapFunctionping between [leftPointer] and [rightPointer]
      }
   }

   printf(" pivot swapped :%d,%d\n", arr[leftPointer], arr[right]);
   swapFunction(leftPointer,right);
   printf("Updated Array: ");
   display();
   return leftPointer;
}

void quickSort(int left, int right) {

    printf("quickSort(%d, %d)\n", left, right);
    printf("Array is:  ");
    for(int i=left; i<=right; i++)
        printf("%d ",arr[i]);
    puts("");

   if(right-left <= 0) {
      return;
   } else {
      int pivot = arr[right];
      int partitionPoint = partitionFunction(left, right, pivot);
      printf("partitionFunction Point: %d. Left was: %d, Right was: %d, Pivot: %d\n",partitionPoint, left, right, pivot);
      quickSort(left,partitionPoint-1);
      quickSort(partitionPoint+1,right);
   }
}

main() {
   printf("Input Array: ");
   display();
   printline(50);
   quickSort(0,MAX-1);
   printf("Output Array: ");
   display();
   printline(50);
}
