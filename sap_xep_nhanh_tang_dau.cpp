#include<stdio.h>
#include<string.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[low];
    int i = (low + 1);

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return (i - 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        printf("Pivot: %d\n", arr[pi]);
        for(int i = low; i <= high; i++) {
            printf("%d,", arr[i]);
        }
        printf("\n");

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, n-1);
    printf("Mang sau khi sap xep: ");
    for(int i = 0; i < n; i++) {
        printf("%d,", arr[i]);
    }
    return 0;
}

