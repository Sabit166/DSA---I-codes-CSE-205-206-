#include <bits/stdc++.h>
using namespace std;
int n,arr[100];

void insertion_sort()
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i],j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    insertion_sort();
    for(int i=0;i<n;i++) cout << arr[i] << ' ';
}