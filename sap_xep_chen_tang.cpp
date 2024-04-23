#include <stdio.h>
#include <string.h>

void printArray(int array[], int size) {
   for (int i = 0; i < size - 1; i++) {
      printf("%d,", array[i]);
   }
   printf("%d\n", array[size - 1]); // In ph?n t? cu?i c�ng kh�ng c� d?u ph?y
}

void insertionSort(int array[], int size) {
   for (int step = 1; step < size; step++) {
      int key = array[step];
      int j = step - 1;

      // So s�nh key v?i t?ng ph?n t? b�n tr�i cho d?n khi t�m th?y v? tr� ph� h?p
      while (key < array[j] && j >= 0) {
         // Di chuy?n ph?n t? nh? hon key v? sau m?t v? tr� so v?i v? tr� hi?n t?i
         array[j + 1] = array[j];
         --j;
      }
      array[j + 1] = key;

      // In ra m?ng sau m?i bu?c
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

