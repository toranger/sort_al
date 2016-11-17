#include<stdio.h>
#include"show.h"
/**
 * @file heap.c
 * @brief  the heap sort is one of the select sort n^lgn
 * 结果是递减
 * @author tmd
 * @version 
 * @date 2016-11-17
 */


/**
 * @brief min_heapify 
 * 从index处够建小顶堆的性质
 * @param arr[]
 * @param index
 * @param len use to the sort function 
 */
void min_heapify(int arr[],int index, int size){
	if(arr == NULL){
		return ;	
	}
	int left = 2*index + 1;
	int right = 2*index + 2;
	int smallest;
	int tmp;
	if(left < size && arr[left] < arr[index]){
		smallest = left;	
	}else{
		smallest = index;	
	}
	if(right < size && arr[right] < arr[smallest]){
		smallest = right;	
	}
	if(smallest != index){
		//exchange arr[index] with arr[largest]	
		tmp = arr[index];
		arr[index] = arr[smallest];
		arr[smallest] = tmp;
		min_heapify(arr,smallest,size);
	}		
	
	return ;
}
/**
 * @brief build_small_heap according to the function of the  min_heapify
 *
 * @param arr[]]
 * @param len
 */
void build_min_heap(int arr[], int len){
	if(len <= 0 || arr == NULL)
		return;
	int i;//the index
	//from the end to the front let the root meet the max_heapify
	for(i = (len-1)/2;i>=0;i--){
		min_heapify(arr,i,len);	
	}
	return ;
}
/**
 * @brief small_heap_sort 
 * 大顶堆
 * @param arr[]
 * @param len
 */
void small_heap_sort(int arr[],int len){
	if(arr == NULL){
		return ;	
	}
	int i;// the index
	int tmp;
	int size = len;
	for(i=len-1;i>0;i--){
		//exchange arr[i] with arr[0]	
		tmp = arr[i];	
		arr[i] = arr[0];
		arr[0] = tmp; //the end num is the biggest num 
		//get small for the arr len
		size--;	
		//from index = 0 to let the rest of num in arr meet the max_heapify
		min_heapify(arr,0,size);

	}
	return ;
}


int main()
{
	int arr[6] = {5,2,4,6,1,3};
	build_min_heap(arr,6);
	small_heap_sort(arr,6);	
	show(arr,6);
	return 0;
}

