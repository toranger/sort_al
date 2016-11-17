#include<stdio.h>
#include"show.h"
/**
 * @file heap.c
 * @brief  the heap sort is one of the select sort n^lgn
 * 完全二叉树可以通过数组下标快速定位 分为大顶堆和小顶堆
 * n left:2n right:2n+1  所以只需该改变length/2子树节点让其满足所在堆性质
 * 子树中所有节点的值都不大于或小于根节点的值
 * 交换堆顶数据 重新排序以满足性质
 * 
 * @author tmd
 * @version 
 * @date 2016-11-17
 */


/**
 * @brief max_heapify 
 * 从index处够建大顶堆的性质
 * @param arr[]
 * @param index
 * @param len use to the sort function 
 */
void max_heapify(int arr[],int index, int size){
	if(arr == NULL){
		return ;	
	}
	int left = 2*index + 1;
	int right = 2*index + 2;
	int largest;
	int tmp;
	if(left < size && arr[left] > arr[index]){
		largest = left;	
	}else{
		largest = index;	
	}
	if(right < size && arr[right] > arr[largest]){
		largest = right;	
	}
	if(largest != index){
		//exchange arr[index] with arr[largest]	
		tmp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = tmp;
		max_heapify(arr,largest,size);
	}		
	
	return ;
}
/**
 * @brief build_large_heap according to the function of the  max_heapify
 *
 * @param arr[]]
 * @param len
 */
void build_max_heap(int arr[], int len){
	if(len <= 0 || arr == NULL)
		return;
	int i;//the index
	//from the end to the front let the root meet the max_heapify
	for(i = (len-1)/2;i>=0;i++){
		max_heapify(arr,i,len);	
	}
	return ;
}
/**
 * @brief large_heap_sort 
 * 大顶堆
 * @param arr[]
 * @param len
 */
void large_heap_sort(int arr[],int len){
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
		max_heapify(arr,0,size);

	}
	return ;
}


int main()
{
	int arr[6] = {5,2,4,6,1,3};
	build_max_heap(arr,6);
	large_heap_sort(arr,6);	
	show(arr,6);
	return 0;
}

