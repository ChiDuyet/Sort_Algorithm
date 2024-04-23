#include <stdio.h>
#include <string.h>

void printArray(int array[], int size) {
   for (int i = 0; i < size - 1; i++) {
      printf("%d,", array[i]);
   }
   printf("%d\n", array[size - 1]); 
}

int partitionAscending(int array[], int low, int high) {
   int pivot = array[high];
   int i = (low - 1);

   for (int j = low; j < high; j++) {
      if (array[j] <= pivot) {
         i++;
         int temp = array[i];
         array[i] = array[j];
         array[j] = temp;
      }
   }

   int temp = array[i + 1];
   array[i + 1] = array[high];
   array[high] = temp;

   return (i + 1);
}

void quickSortAscending(int array[], int low, int high) {
   if (low < high) {
      int pi = partitionAscending(array, low, high);

      printArray(array, high + 1);

      quickSortAscending(array, low, pi - 1);
      quickSortAscending(array, pi + 1, high);
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

   quickSortAscending(data, 0, n - 1);
   printf("Mang sau khi sap xep:\n");
   printArray(data, n);
}

