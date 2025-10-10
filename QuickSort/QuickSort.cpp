#include <stdio.h>
void afficher(int arr[], int high) {
    for (int b = 0; b <= high; b++) {
        printf("%d", arr[b]);
        printf("\n");
    }
}
int partition(int arr[], int low, int high) {
    int i = low - 1, a;
    int pivot = arr[high];
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            a = arr[j];
            arr[j] = arr[i];
            arr[i] = a;
        }
        else {
        }
    }

    arr[high] = arr[i + 1];
    arr[i + 1] = pivot;

    return i;

}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi);
        quicksort(arr, pi + 1, high);
    }
}

int main(int argc, char** argv)
{
    int tab[300000], val = 0, low = 0;
    int i = 0, taille = 0;
    while (val != -1 && i <= 300000) {
        if (val == -1) {
            break;
        }
        scanf_s("%d", &tab[i]);
        val = tab[i++];
    }

    taille = i - 2;
    quicksort(tab, low, taille);
    afficher(tab, taille);
    return 0;
}

