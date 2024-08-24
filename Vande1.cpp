#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }
}

void PhatSinhMang(int a[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand();
    }
}

void XuatMang(int a[], int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%10d", a[i]);
    }
    printf("\n");
}


int GhiMangVaoFileText(char* filename, int a[], int n) {
    FILE* f = fopen(filename, "w");
    if (!f)
        return 0;
    for (int i = 0; i < n; i++)
        fprintf(f, "%d\t", a[i]);
    fclose(f);
    return 1;
}


int DocFileTextVaoMang(char* filename, int a[], int &n) {
    FILE* f = fopen(filename, "r");
    if (!f)
        return 0;
    int i = 0;
    while (!feof(f)) 
    {
        fscanf(f, "%d", &a[i]); 
        i++;
    }
    n = i;
    fclose(f);
    return 1; 
}

int main() {
    int n, a[100];
    char filename[] = "mang.txt";
    
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);


    NhapMang(a, n);


    printf("Mang vua nhap:");
    XuatMang(a, n);
    printf("\n Mang sau khi phat sinh:");
    PhatSinhMang(a,n);
    XuatMang(a,n);
    if (GhiMangVaoFileText(filename, a, n)) {
        printf("Ghi mang vao file %s thanh cong!\n", filename);
    } else {
        printf("Ghi mang vao file %s that bai!\n", filename);
    }


    int m;
    if (DocFileTextVaoMang(filename, a, m)) {
        printf("Doc mang tu file %s thanh cong!\n", filename);
        printf("Mang vua doc:");
        XuatMang(a, m);
    } else {
        printf("Doc mang tu file %s that bai!\n", filename);
    }

    return 0;
}

