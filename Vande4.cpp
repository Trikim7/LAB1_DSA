#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;


int LinearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x)
            return i;
    }
    return -1;
}


int BinarySearch(int a[], int left, int right, int x) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    if (x == a[mid])
        return mid;
    else if (x < a[mid])
        return BinarySearch(a, left, mid - 1, x);
    else
        return BinarySearch(a, mid + 1, right, x);
}


void PhatSinhMangTang(int a[], int n) {
    srand(time(NULL));
    a[0] = rand() % 50;
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + rand() % 10;
    }
}


void CompareLinearBinarySearch(int A[], int n, int k) {
    auto start = steady_clock::now();
    auto stop = steady_clock::now();


    start = steady_clock::now();
    cout << "Ket qua tim kiem tuyen tinh: " << LinearSearch(A, n, k) << endl;
    stop = steady_clock::now();
    duration<double> t1 = stop - start;


    start = steady_clock::now();
    cout << "Ket qua tim kiem nhi phan: " << BinarySearch(A, 0, n - 1, k) << endl;
    stop = steady_clock::now();
    duration<double> t2 = stop - start;


    if (t1.count() < t2.count())
        cout << "Linear search faster than binary search\n";
    else if (t2.count() < t1.count())
        cout << "Binary search faster than linear search\n";
    else
        cout << "Linear search equal to binary search\n";


    cout << "Thoi gian tim kiem tuyen tinh la: " << t1.count() << " giay\n";
    cout << "Thoi gian tim kiem nhi phan la: " << t2.count() << " giay\n";
}

int main() {
    int a[100000], n, x;

    printf("Ban can phat sinh mang co bao nhieu PT? ");
    scanf("%d", &n);

    PhatSinhMangTang(a, n);

    printf("Nhap khoa can tim: ");
    scanf("%d", &x);


    clock_t start = clock();
    int kq1 = LinearSearch(a, n, x);
    clock_t end = clock();
    double t_linear = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Thoi gian tim kiem tuyen tinh (clock) la: %f giay\n", t_linear);


    start = clock();
    int kq2 = BinarySearch(a, 0, n - 1, x);
    end = clock();
    double t_binary = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Thoi gian tim kiem nhi phan (clock) la: %f giay\n", t_binary);


    CompareLinearBinarySearch(a, n, x);

    return 0;
}

