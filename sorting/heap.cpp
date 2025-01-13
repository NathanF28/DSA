#include <iostream>
#include <vector>
using namespace std;

void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

void maxHeapify(vector<int>& arr, int size, int index){
    int largest = index;
    int left = 2*index + 1; //left node
    int right = 2*index + 2; //right node

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != index){
        swap(arr[index], arr[largest]);
        maxHeapify(arr,size,largest); // continue down from the node
    }
}

void heapSortmax(vector<int>& arr, int size){
    for(int i = size/2 - 1; i >= 0 ;i--){ // start from n/2 -1 bcs thats the point where non leaf nodes start, therefore targeting them all until the root
        maxHeapify(arr,size,i);
    }
    for(int i = size-1; i > 0;i--){
        swap(arr[0],arr[i]); // Push max to the last 
        maxHeapify(arr,i,0); // Build Max heap again since the swap messed it up, but decrease size bcs last element is already getting sorted at the end
    }
}

void minHeapify(vector<int>& arr, int size, int index){
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index+2;

    if(left < size && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < size && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest !=  index){
        swap(arr[index],arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}

void heapSortmin(vector<int>& arr, int size){
    for(int i = size/2 - 1; i >= 0; i--){
        minHeapify(arr,size,i);
    }
    for(int i = size-1;i>0;i--){
        swap(arr[0],arr[i]);
        minHeapify(arr,i,0);
    }
}