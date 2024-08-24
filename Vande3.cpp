#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BinarySearch(int a[],int left,int right,int x)
{
	if(left>right) return-1;
	int mid=(left+right)/2;
	if(x==a[mid])
		return mid;
	if(x<a[mid])
		return BinarySearch(a, left, mid-1, x);
	if(x>a[mid])
		return BinarySearch(a,mid+1,right,x);
}
	
void PhatSinhMangTang(int a[], int n)
{
	srand(time(NULL));
	a[0] = rand()%50;
	for(int i=1; i<n; i++)
	{
		a[i] = a[i-1] + rand()%10;
	}
}

int main(){
	int a[100], n, x;
	printf("Ban can phat sinh mang co bao nhieu phan tu ? :");
	scanf("%d", &n);
	PhatSinhMangTang(a, n);
	printf("Nhap khoa can tim: ");
	scanf("%d", &x);
	int kq = BinarySearch(a, 0, n-1, x);
	if(kq == -1)
		printf("Khong tim thay ");
	else
		printf("Tim thay tai vi tri %d", kq);
} 
