#include <iostream>
using namespace std;

int arr[] = {2,8,4,9,3,6,4};

void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

void shellSort(int arr[], int size){
    for(int gap = size/2; gap > 0 ; gap/=2){
        for(int i = gap; i < size; i++){
            for(int j = i-gap; j >= 0; j-=gap){
                if(arr[j+gap] >= arr[j]){
                    break;
                }
                else{
                    swap(arr[j], arr[j+gap]);
                }
            }
        }
    }

}

void insertionSort(int arr[],int size){
    for(int i = 1; i < size; i++)
    {
        int j = i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j+1],arr[j]);
            j--;
        }
    }
}



int main(){

    shellSort(arr,7);
    return 0;
}