#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000+5];
int b[100000+5];
void merge(int l,int r);
void merge_sort(int l,int r)
{
    if(l >= r) return;
    merge_sort(l,(l+r)/2);
    merge_sort((l+r)/2+1,r);
    merge(l,r);
    // for(int i = 0; i < n; i++)
    // {
    //     printf("%d ",a[i]);
    // }
    // printf("\n");
}
void merge(int l,int r)
{
    int left = l;
    int right = (l+r)/2+1;
    int now = l;
    while(left <= (l+r)/2 && right <= r)
    {
        if(a[left] <= a[right])
        {
            b[now] = a[left];
            left++;
        }
        else
        {
            b[now] = a[right];
            right++;
        }
        now++;
    }
    while(left <= (l+r)/2)
    {
        b[now] = a[left];
        left++;
        now++;
    }
    while(right <= r)
    {
        b[now] = a[right];
        right++;
        now++;
    }
    for(int i = l;  i <= r; i++)
    {
        a[i] = b[i];
    }
}
int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    merge_sort(0,n-1);
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}