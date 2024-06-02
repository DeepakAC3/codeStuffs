#include <iostream>
using namespace std;
// #define swap(a, b) a^=b, b^=a, a^=b

int partition(int* arr, int l, int r) {
    int pi = arr[l];
    while (true) {
        while (arr[l] < pi) l++;
        while (arr[r] > pi) r--;

        if (l >= r) return r;

        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void quicksort(int* arr, int l, int r) {
    if (l < r) {
        int q = partition(arr, l, r);
        quicksort(arr, l, q);
        quicksort(arr, q + 1, r);
    }
}

int main() {
    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}