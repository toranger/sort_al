#include<stdio.h>
#include<stdlib.h>
#include<limits.h>//INT_MAX int biggest num
#include"show.h"

//notice when finish the code find   
// seg default becasue of : in merge_sort the mid = (low+high)/2
// wrong sort  becasue of : when merge the two arr the index i or j 
//							cross the line
//						    final use the biggest num to be the line of the 
//							son arr

/**
 * @brief merge 
 * 将两个已经排好序的数组合并到原数组中
	*the min is the low = 0 mid = 0 high = 1
 * @param arr[]]
 * @param low
 * @param mid
 * @param high
 */
void merge(int arr[],int low, int mid, int high){
	//count the num of the arr you want to init;
	int size_l = mid - low + 1;		
	int size_r = high - mid ;
	int arr_l[size_l+1];
	int arr_r[size_r+1];
	int i;
	int j;
	int k;
	//put the left num in arr to the arr_l	
	for(i=0;i<size_l;i++){
		arr_l[i] = arr[low+i];	
	}
	//put the right num in arr to the arr_r
	for(j=0;j<size_r;j++){
		arr_r[j] = arr[mid+j+1];	
	}
	//put the biggest int num to the end of son arr
	arr_l[size_l] = INT_MAX;
	arr_r[size_r] = INT_MAX;
	i = 0;
	j = 0;
	//select num from each arr into the arr index from low to high
	for(k = low;k<=high;k++){
		if(arr_l[i] <= arr_r[j] ){
			arr[k] = arr_l[i];
			i++;
		}else{
			arr[k] = arr_r[j];	
			j++;	
		}	
	
	}
	return ;

}
/**
 * @brief merge_sort 
 * sprit two equal arr to sort
 * like the 5,2,4,6,1,3,7
 * {5,2}{4,6}{1,3}{7}
 * {2,4,5,6}{1,3,7}
 * {1,2,3,4,5,6,7}
 * 
 * @param arr[]
 * @param len
 */
void merge_sort(int arr[],int low, int high){
	if(arr == NULL){
		return ;	
	}	
	int mid;
	//若low >= high则该字数组最多有一个元素
	if(low < high){
		mid = (low+high)/2;	
		merge_sort(arr, low ,mid);	
		merge_sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
	return ;
}
int main()
{
	int arr[6] = {5,2,4,6,1,3};
	merge_sort(arr,0,5);
	show(arr,6);
	return 0;

}

