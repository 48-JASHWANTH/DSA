#include <stdio.h>

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++){
        if (arr[i] == x){
            return i;
        }    
    }        
    return -1;
}

int main()
{
	int n,x;
	printf("enter size:");
	scanf("%d",&n);
	int arr[n];
	printf("enter elements:\n");
	for(int i=0;i<n;i++){
	    scanf("%d",&arr[i]);
	}
	printf("enter element to search:");
	scanf("%d",&x);
	int result = linearSearch(arr, n, x);
	(result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d",result);
	return 0;
}
