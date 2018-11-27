#include<bits/stdc++.h>
#define LL long long
using namespace std;
int cross(int arr[], int low, int mid, int high)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = mid; i >= 1; i--)
    {
        sum += arr[i];
        if(sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for(int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if(sum > right_sum)
            right_sum = sum;
    }
    int cr = (left_sum + right_sum);
    return (left_sum + right_sum);
}
int sub_set_sum(int arr[], int low, int high)
{
    int mid;
    if(low == high)
    {
        int x = arr[high];
        return arr[high];
    }
    else mid = (low + high) / 2;
tiling problem divide and conquer
    int left_tree = sub_set_sum(arr, low, mid);
    int right_tree = sub_set_sum(arr, mid + 1, high);
    int cross_sum = cross(arr, low, mid, high);

    if(left_tree >= right_tree and left_tree >= cross_sum)
        return left_tree;
    else if(right_tree >= left_tree and right_tree >= cross_sum)
        return right_tree;
    else return cross_sum;
}
int main()
{
    int arr[100], n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << sub_set_sum(arr, 1, n) << endl;
}

