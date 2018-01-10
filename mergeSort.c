#include<stdio.h>

void merge(int *arr, int l, int mid, int r){
    int i, j ,k;
    int n1 = mid - l + 1;//no of elements in first half
    int n2 = r - mid;//no of elements in second half

    int l1[n1], l2[n2];//temp arrays to store values

    for(i = 0; i < n1; i++)//copy first half to l1 array
        l1[i] = arr[l + i];
    for(i = 0; i < n2; i++)//copy second half to l2 array
        l2[i] = arr[mid + 1 + i];

    i = 0;//first index of l1
    j = 0;//first index of l2
    k = l;//first index of merged array

    while(i < n1 && j < n2){//insert elements in ascending order in merged array
        if(l1[i] <= l2[j]){
            arr[k] = l1[i];
            i++;
        }
        else{
            arr[k] = l2[j];
            j++;
        }
        k++;
    }

    while(i < n1)//if elements of l1 remain copy them to arr
    {
        arr[k] = l1[i];
        i++;
        k++;
    }

    while(j < n2)//if elements of l2 remain copy them to arr
    {
        arr[k] = l2[j];
        j++;
        k++;
    }
}

void sort(int *arr, int l, int r){
    if(l < r){
        int mid = (l + r) / 2;

        sort(arr, l, mid);
        sort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int n, i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i< n;i++)
        scanf("%d",&arr[i]);
    sort(arr, 0, n-1);
    for(i = 0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
