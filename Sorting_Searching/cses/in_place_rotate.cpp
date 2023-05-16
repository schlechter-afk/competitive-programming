#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        arr[i] = arr[i-1];
        arr[i+1] = arr[i];
    }
    int xorbit = 0;
    for(int i=0;i<n;i++)
    {
        xorbit ^= arr[i];
    }
    cout << xorbit << "endl";
}