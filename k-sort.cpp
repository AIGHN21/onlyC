#include<iostream>
using namespace std;

void ksort(int arr[], int &k, int n) {
    int j;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            j = i - 1;
            if (arr[i] < arr[j]) {
                k += arr[j] - arr[i];
                arr[i] = arr[j];  
            }
        }
    }
    if(k==1){
        k=0;
    }
    cout << k;
}
int main(){
    int arr[]={1,7,9};
    int k=1;
    int n=3;
    ksort(arr,k,n);
}