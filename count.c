/**
 * @file count.c
 * @brief 计数排序 假设每个数都在0 到 k区间之内
 * 记录各数出各数出现的次数从而求比x小的个数得出x
 * 在数组中的位置
 * @author tmd
 * @version 1.0
 * @date 2016-11-19
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"show.h"
/**
 * @brief count_sort 
 *
 * @param arr_in[] 输入数组
 * @param arr_out[] 输出数组
 * @param len 
 */
void count_sort(int arr_in[], int arr_out[], int len){
	if(arr_in == NULL || arr_out == NULL || len <= 0)
		return ;
	int min = arr_in[0];
	int max = arr_in[0];
	int size; //length of the arr_tmp
	int *tmp;
	int i ;
	//count the length of the arr_tmp
	for(i=1;i<len;i++){
		if(arr_in[i] < min){
			min = arr_in[i];	
		}	
		if(arr_in[i] > max){
			max = arr_in[i];	
		}
	}
	size = max - min + 1;
	tmp = (int*)malloc(sizeof(int)*size);
	//init ps:can not use the memset 
	for(i=0;i<size;i++){
		tmp[i] = 0;	
	}
	//count the num in arr_in occure times
	for(i=0;i<len;i++){
		tmp[arr_in[i] - min]++;	
	}
	//count the index the num has to insert
	for(i=1;i<size;i++){
		tmp[i] += tmp[i-1];	
	}
	//put the num in the right place of the arr_out
	//when have the same cut the occure num in the tmp arr	
	//the num in tmp is the sum num before but arr index from the 0
	for(i=0;i<len;i++){
		arr_out[tmp[arr_in[i] - min] - 1] = arr_in[i];	
		tmp[arr_in[i] - min]--;
	}
	return;

}

int main()
{
	int arr_in[8] = {2,5,3,0,2,3,0,3};
	int arr_out[8];
	count_sort(arr_in,arr_out,8);
	show(arr_out,8);
	return 0;
}

