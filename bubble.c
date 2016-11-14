#include<stdio.h>
#include<stdlib.h>
//two kind of the bubble sort
//1.the right side
/**
 * @brief right_bubble 用i记录冒泡多少次
 * 
 *
 * @param arr the arr of the number
 * @param len the length of the arr
 */
void right_bubble(int *arr, int len){
	int i;
	int j;
	int tmp;
	for(i = 0;i<len-1;i++){
		for(j = 0;j<len-1-i;j++){
			//compare the two num 	
			if(arr[j] > arr[j+1]){
				tmp = arr[j];			
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}	
	
	}
	return ;
}



//2.the left side
void left_bubble(int *arr, int len){
	int i;
	int j;
	int tmp;
	for(i=0;i<len-1;i++){
		for(j=len-1;j>i;j--){
			if(arr[j] < arr[j-1]){
				tmp = arr[j];	
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}		
		}	
	}
	return ;
}


//3.print the arr
void show(int *arr, int len){
	int i;
	for(i=0;i<len;i++){
		printf("%d\n",arr[i]);	
	}
	
	printf("----------------\n");
	return ;
}

//test function
int main()
{
	int arr_left[6] = {5,2,4,6,1,3};		
	int arr_right[6] = {5,2,4,6,1,3};		
	left_bubble(arr_left, 6);
	show(arr_left,6);
	right_bubble(arr_right,6);
	show(arr_right,6);

	return 0;
}

