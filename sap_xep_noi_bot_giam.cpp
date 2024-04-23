#include <stdio.h>
#include <string.h>

void printArray(int array[], int size) {
   for (int i = 0; i < size - 1; i++) {
      printf("%d,", array[i]);
   }
   printf("%d\n", array[size - 1]);
}

void bubbleSortDescending(int array[], int size) {
   for (int step = 0; step < size - 1; ++step) {
      for (int i = 0; i < size - step - 1; ++i) {
         if (array[i] < array[i + 1]) {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
         }
      }
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

   bubbleSortDescending(data, n);
   printf("Mang sau khi sap xep:\n");
   printArray(data, n);
}

