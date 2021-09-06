
#include <iostream>
using namespace std;
void swap(int &x,int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void bubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
            if(a[j] > a[j+1] )
                swap(a[j],a[j+1]);
    }
}

void selectionSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
            if(a[j] < a[i])
                swap(a[i],a[j]);
    }
}

void insertionSort(int a[],int  n)
{
    int j,temp;
    for(int i=1;i<n;i++)
    {
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j] > temp )
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

int partition(int a[],int start,int end)
{
    int pivot = a[end];
    int pivotIndex = start;
    for(int i=start;i<end;i++)
    {
        if(a[i] <= pivot)
        {
            swap(a[i],a[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(a[pivotIndex],a[end]);
    return pivotIndex;
}

void quickSort(int a[],int start,int end)
{
    if(start < end){
        int pivot  = partition(a,start,end);
        quickSort(a, start, pivot-1);
        quickSort(a, pivot+1, end);
    }
}
int countInversion = 0;
void merge(int a[],int l,int mid,int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    
    int L[n1],R[n2];
    
    for(int i =0;i<n1;i++)
        L[i] = a[l+i];
    for(int j=0;j<n2;j++)
        R[j] = a[mid+ 1 + j];
    
    int i = 0;
    int j = 0;
    int k = l;
    
    while (i < n1 && j < n2) {
           if (L[i] <= R[j]) {
               a[k] = L[i];
               i++;
           }
           else {
               a[k] = R[j];
               countInversion = countInversion + (n1 - i);
               j++;
           }
           k++;
       }
       while (i < n1) {
           a[k] = L[i];
           i++;
           k++;
       }
       while (j < n2) {
           a[k] = R[j];
           j++;
           k++;
       }
}

void mergeSort(int a[],int l,int r)
{
    if(l < r)
    {
        int mid  = (l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout <<endl;
}
int main()
{
    int n;
    cout << "Enter the Number of Elements :";
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    cout << "Given Array : ";
    print(a,n);
    
    bubbleSort(a, n);
    cout << "Sorted Array using Bubble Sort: ";
    print(a,n);

    selectionSort(a, n);
    cout << "Sorted Array using Selection Sort: ";
    print(a,n);

    insertionSort(a, n);
    cout << "Sorted Array using Insertion Sort: ";
    print(a,n);

    quickSort(a,0,n-1);
    cout << "Sorted Array using Quick Sort: ";
    print(a,n);
    
    mergeSort(a,0,n-1);
    cout << "Sorted Array using Merge Sort: ";
    print(a,n);
    
    return 0;
}


