#include <bits/stdc++.h>
using namespace std;
int arr[100],n;

void selectionSort()
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++) if(arr[j]<arr[min_index]) min_index=j;
        int temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    selectionSort();
    for(int i=0;i<n;i++) cout << arr[i] << ' ';
}