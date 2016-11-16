#include<stdio.h>
#include"show.h"

/**
 * @file quick.c
 * @brief  the best is n^2, the worest is n^lgn
 * is the improve for the bubble use the merge method
 * the main way : how to imply the arr A[p,r] 原址排序
 * always use the   x = A[r] for the main element (A,p,r)
 * 以x为准划分左右数组满足左数组中的数都小于右数组中的数
 * x所插入的位置决定了排序的快慢最快类似于merge sort 最坏并不好过insert sort
 * example : 5,2,4,6,1,3
 * 2.5.4.6.1.3
 * 2.1.4.6.5.3
 * 2.1.3.6.5.4 the x = 3
 * @author tmd
 * @version 1.0
 * @date 2016-11-17
 */



/**
 * @brief partition 
 * 根据x = A[r]划分两个数组 返回x所插入的数组下标
 * @param arr[]
 * @param low
 * @param high index
 *
 * @return 
 */
int partition(int arr[], int low ,int high){
	if(arr == NULL){
		return -1;	
	}
	//rember the main element
	int x = arr[high];
	int j ;
	int i = low - 1;//count the index of number which smaller x
	int tmp;
	for(j = low;j<=high-1;j++){
		if(arr[j] <= x){
			i++;	
			//exchange arr[i] with arr[j]
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}	
	}
	//exchange the main element x with arr[i+1]
	tmp = arr[i+1];	
	arr[i+1] = x;
	arr[high] = tmp;
	//return the index of x(main element) in the arr 
	return i+1;
}



/**
 * @brief quick_sort 
 *
 * @param arr[]
 * @param low  index
 * @param high
 */
void quick_sort(int arr[],int low ,int high){
	int i;//划分俩数组的数的下标
	if(low < high){
		i = partition(arr,low,high);	
		quick_sort(arr,low,i-1);
		quick_sort(arr,i+1,high);
	}
	return;

}





int main()
{
	int arr[6] = {5,2,4,6,1,3};
	quick_sort(arr,0,5);
	show(arr,6);
	return 0;
}

