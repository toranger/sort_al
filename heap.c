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
void heap_sort(int arr[],int len){
	if(arr == NULL){
		return ;	
	}
}

int main()
{
	int arr[6] = {5,2,4,6,1,3};
	heap_sort(arr,6);	
	show(arr,6);
	return 0;
}

