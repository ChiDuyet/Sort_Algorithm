#include <stdio.h>
#include <string.h>

void printArray(int array[], int size) {
   for (int i = 0; i < size - 1; i++) {
      printf("%d,", array[i]);
   }
   printf("%d\n", array[size - 1]); 
}

void insertionSort(int array[], int size) {
   for (int step = 1; step < size; step++) {
      int key = array[step];
      int j = step - 1;

      while (key > array[j] && j >= 0) {
         array[j + 1] = array[j];
         --j;
      }
      array[j + 1] = key;

      printArray(array, size);
   }
}

int main() {
   int data[100];
   int n = 0;
   char input[1000];

   printf("Nhap day so: ");
   fgets(input, 1000, stdin);

   char *token = strtok(input, ",");
   while (token != NULL) {
      sscanf(token, "%d", &data[n]);
      n++;
      token = strtok(NULL, ",");
   }

   insertionSort(data, n);
   printf("Mang sau khi sap xep:\n");
   printArray(data, n);
}

