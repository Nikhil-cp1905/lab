#include <stdio.h>

void insertionsort(int arr[],int n){
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while (j>=0 && arr[j]>key){
			arr[j+1] =arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void printArray(int arr[],int n){
	for (int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int main(){
	int arr[]={9,5,1,4,3};
	int n=sizeof(arr)/size(arr[0]);
	insertionSort(arr,n);
	printf("Sorted array:");
	printArray(arr,n);
	return 0;
}


