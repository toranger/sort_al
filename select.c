#include<stdio.h>

/**
 * @brief select_sort 
 * all the al function need to be sure the param can use
*
* select the min num to the lowest index
* 遍历数组从除去选中元素剩余的数列中进行比较选择较小数的下标交换数
* 依次从数列中选择较小或较大的数排列
 * @param arr[]]
 * @param len
 */
void low_select_sort(int arr[], int len){
	int i;
	int j;
	int min;
	int tmp;
	for(i=0;i<len-1;i++){
		min = i;		
		for(j = i+1;j<len;j++){
			if(arr[j] < arr[min]){
				//keep the min index	
				min = j;
			}	
		}
		//whether have the min num
		if(min != i){
			tmp = arr[i];		
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	
	}
	return ;

}
//select the max num to the arr
void high_select_sort(int arr[], int len){
	int i ;	
	int j; 
	int max;
	int tmp;
	for(i = len-1;i>0;i--){
		max = i;	
		for(j = i-1;j>=0;j--){
			//select the max index in the rest arr	
			if(arr[max] < arr[j]){
				max = j;	
			}
		}
		//max index have been changed
		if(max != i){
			//change the num 		
			tmp = arr[max];
			arr[max] = arr[i];
			arr[i] = tmp;
		}
	
	}
	return ;
}
void show(int arr[], int len){
	int i;
	for(i=0;i<len;i++){
		printf("%d\n",arr[i]);	
	}
	printf("----------\n");
}
int main()
{
	int arr[6] = {5,2,4,6,1,3};
	int arr1[6] = {5,2,4,6,1,3};
	low_select_sort(arr,6);
	show(arr,6);
	high_select_sort(arr1,6);
	show(arr1,6);
	return 0;
}

