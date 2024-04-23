#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[largest])
        largest = left;

    if (right < n && arr[right] < arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);

        for(int j=0; j<n; j++)
            printf("%d,", arr[j]);
        printf("\n");
    }
}

int main() {
    int arr[100];
    int n = 0;
    char input[1000];

    printf("Nhap day so: ");
    fgets(input, 1000, stdin);

    char *token = strtok(input, ",");
    while (token != NULL) {
        sscanf(token, "%d", &arr[n]);
        n++;
        token = strtok(NULL, ",");
    }

    heapSort(arr, n);
    printf("Mang sau khi sap xep: ");
    for(int i = 0; i < n; i++) {
        printf("%d,", arr[i]);
    }
    return 0;
}

