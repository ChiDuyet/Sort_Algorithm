#include <stdio.h>
#include <string.h>

void printArray(int array[], int size) {
   for (int i = 0; i < size - 1; i++) {
      printf("%d,", array[i]);
   }
   printf("%d\n", array[size - 1]);
}

void selectionSortDescending(int array[], int size) {
   for (int step = 0; step < size - 1; step++) {
      int max_idx = step;
      for (int i = step + 1; i < size; i++) {
         if (array[i] > array[max_idx])
            max_idx = i;
      }
      int temp = array[step];
      array[step] = array[max_idx];
      array[max_idx] = temp;

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

   selectionSortDescending(data, n);
   printf("Mang sau khi sap xep:\n");
   printArray(data, n);
}

