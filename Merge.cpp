#include<iostream>

using namespace std;


int a[10] = { 10, 14, 33, 35, 42, 44, 19, 26, 27, 31};
int b[10];
int n=10;

void merge(int L, int mid, int H)
{
    int L1,L2, i;
    for(L1=L,L2=mid+1,i=L; L1<=mid && L2<=H; i++)
    {
        if(a[L1]<=a[L2])
        {
            b[i]=a[L1];
            L1++;
        }
        else
        {
            b[i]=a[L2++];
        }
    }
    while(L1<=mid)
    {
        b[i++]=a[L1++];
    }
    while(L2<=H)
    {
        b[i++]=a[L2++];
    }

    for(i=L; i<=H; i++)
    {
        a[i]=b[i];
    }

}

void mergesort(int low, int high)
{

    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low, mid);
        mergesort(mid+1, high);
        merge(low, mid, high);
    }
    else
    {
        return;
    }

}

int main()
{
     printf("\nList before sorting\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    mergesort(0,n-1);

    printf("\nList after sorting\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }


    return 0;
}
