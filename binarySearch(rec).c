#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
	if (l <= r) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x){
			return mid;
		}	
		else if (arr[mid] > x){
			return binarySearch(arr, l, mid - 1, x);
		}
		else{
		    return binarySearch(arr, mid + 1, r, x);
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
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d",result);
	return 0;
}
