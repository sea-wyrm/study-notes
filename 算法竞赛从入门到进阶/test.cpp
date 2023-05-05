#include <iostream>

using namespace std;

const int N = 1e7 + 10;

int a[N], tmp[N];

void quickSort(int l, int r) {
    if (l >= r) return;

    int x = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        while (a[++i] < x);
        while (a[--j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    quickSort(l, j);
    quickSort(j + 1, r);
}

void mergeSort(int l, int r) {
    if (l >= r) return;

    int mid = l + r >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int i = l, j = 0; i <= r; i++, j++) {
        a[i] = tmp[j];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}