#include <algorithm>
#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];

    // count element less than pivot
    int count = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // place pivot at right index
    int pivotindex = s + count;
    swap(arr[s], arr[pivotindex]);

    // left and right element ko sambhal lete hai
    int i = s;
    int j = e;
    while (i < pivotindex && j > pivotindex) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotindex && j > pivotindex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotindex;
}
void quicksort(int *arr, int s, int e) {
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    // left part karo
    quicksort(arr, s, p - 1);
    // right part sort karo
    quicksort(arr, p + 1, e);
}
int main() {
    int arr[9] = {24, 9, 5, 66, 1, 0, 8, 4, 7};
    int n = 9;

    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
