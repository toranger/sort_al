#include<stdio.h>
#include<stdlib.h>




//the insert sort
/**
 * @brief insert_sort 
 * 将要排序的数插入到之前已经排好序的数列中
 *
 * @param arr[]
 * @param len
 */
void insert_sort(int arr[], int len){
	int i ;
	int j ;
	int key;//to rember the num you want to insert
	for(i = 1;i < len; i++){
		key = arr[i];			
		j = i - 1;
		while(j>=0 && arr[j] > key){
			//look the site for your insert key	
			arr[j+1] = arr[j];
			j--;
		}
		//put the num in the right 
		arr[j+1]  = key ;
	}	
	return;
} 

//show
void show(int arr[], int len){
	int i;
	for(i=0;i<len;i++){
		printf("%d\n",arr[i]);
	}
	printf("------------\n");
	return;

}
//test function
int main()
{
	int arr[6] = {5,2,4,6,1,3}	;	
	insert_sort(arr, 6);
	show(arr, 6);
	return 0;
}

