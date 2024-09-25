#include <iostream>
#include <vector>
using namespace std;

void merge(int* arr, int s, int e) {
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    // copy values
    int Index = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[Index++];
    }

    Index = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[Index++];
    }

    // Merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    Index = s;
    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[Index++] = first[index1++];
        } else {
            arr[Index++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[Index++] = first[index1++];
    }

    while (index2 < len2) {
        arr[Index++] = second[index2++];
    }
}
void mergesort(int* arr, int s, int e) {
    if (s >= e)
        return;

    int mid = (s + e) / 2;
    // left part ko recursion sort krdega
    mergesort(arr, s, mid);
    // right part ko recursion sort krdega
    mergesort(arr, mid + 1, e);
    // merge left part and right part
    merge(arr, s, e);
}
int main() {
    int arr[9] = {24, 19, 8, 3, 4, 7, 0, 1, 2};
    int n = 9;
    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
