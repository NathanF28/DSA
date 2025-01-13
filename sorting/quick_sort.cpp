#include <iostream>
#include <vector>
using namespace std;

void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
} 

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int start = low;
    int end = high;
    while (start < end){
        while (arr[start] <= pivot){
            start++;
        }
        while (arr[end] > pivot){
           end--; 
        }
        if(start < end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[end],arr[low]);
    return end;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pos = partition(arr,low,high);
        quickSort(arr,pos+1,high);
        quickSort(arr,low,pos-1);
    }
}
