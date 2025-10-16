#include <stdio.h>
#include <stdlib.h>
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

void tribulle(int arr[], int low, int high) {

    int pluspetit = 0, plusgrand = 0;

    for (int j = low; j < high+1; j++) {

        for (int i = low; i < high+1; i++) {
            if (arr[i - 1] > arr[i]) {
                pluspetit = arr[i];
                plusgrand = arr[i - 1];
                arr[i] = plusgrand;
                arr[i - 1] = pluspetit;
            }
        }

    }
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        if (high - low < 0) {
            tribulle(arr, low, high);
        }
        else {
            int pi = partition(arr, low, high);
            quicksort(arr, low, pi);
            quicksort(arr, pi + 1, high);
        }
    }
}


int main(int argc, char** argv)
{
    int tailletab = 300000, *point = NULL;;
    int tab[300000], val = 0, low = 0;
    int i = 0, taille = 0;

    point = (int*)malloc(tailletab * sizeof(int));
    while (val != -1 && i <= 100000) {
        if (val == -1) {
            break;
        }
        scanf_s("%d", &tab[i]);
        val = tab[i++];
    }

    taille = i - 2;
    quicksort(tab, low, taille);
    afficher(tab, taille);
    //Liberer malloc
    free(point);
    point = NULL;
    return 0;
}

