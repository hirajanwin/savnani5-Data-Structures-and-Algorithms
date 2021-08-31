#include <iostream>
#include <stdio.h>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    
    for (int i=0; i<(n-k+1); i++)
    {
        int max=0;
        for (int j=i; j<i+k; j++)
        {
           if (arr[j]>max) max = arr[j]; 
        }
        printf("%d ", max);
    }
	printf("\n");
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
