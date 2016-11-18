#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"show.h"
/**
 * @file bucket.c
 * @brief 桶排序类似于计数排序根据最大值和最小值取hash链表大小 
 * 将对应数放到对应hash链中 ，链中用插入排序排好
 * 最后遍历链表把数组成arr
 * 此处省略free  hashlist 以及 node内存 Free();
 * @author tmd
 * @version 1.0
 * @date 2016-11-18
 */
typedef struct node{
	int value;
	struct node* pPre;
	struct node* pNext;
}Node;
/**
 * @brief push 将value放入到相应的hash list中
 * @param list
 * @param value
 */
void push(Node** list,int value){
	if(list == NULL)
		return ;
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	if((*list) == NULL){
		//对应链表为空	
		Node* head = (Node*)malloc(sizeof(Node));
		(*list) = head;
		head->value = 1;
		tmp->pNext = (*list);
		tmp->pPre = (*list);
		(*list)->pNext = tmp;
		(*list)->pPre = tmp;
	}else{
		//is not empty	
		tmp->pNext = (*list)->pNext;
		tmp->pPre = (*list);
		(*list)->pNext->pPre = tmp;
		(*list)->pNext = tmp;
		((*list)->value)++;
	}
	return ;

}
/**
 * @brief insert_sort 将对应hash list 中的数根据插入排序进行排序
 * 同时将排序好的数放到原数组中
 *
 * @param list
 * @param arr_origin[]
 * @param len the length of the arr_origin
 * @param have  the index to insert to the arr_origin
 *
 * @return     the index which this list num after this hash list num insert
 * to the arr_origin
 */
int insert_sort(Node* list ,int arr_origin[], int len,int have){
	if(list == NULL || arr_origin == NULL || len <= 0 || have == -1)
		return -1 ;
	int arr_len = (list)->value;
	int arr[arr_len];
	int i;
	int j;
	int key;
	int tmp;
	//put the num into the arr
	int count = list->value;
	list = list->pNext;
	for(i = 0;i < count;i++){
		arr[i] = list->value;	
		list = list->pNext;
	}

	for(i = 1;i < arr_len;i++){
		key = arr[i];	
		j = i - 1;
		while(j >= 0 && arr[j] > key){
			//exchange arr[j+1]	with arr[j]
			tmp = arr[j+1];	
			arr[j+1] = arr[j] ;
			arr[j] = tmp;
			j--;
		}
		arr[j+1] = key;
	}
	//put the order arr num to the origin arr 
	for(i = 0;i < arr_len;i++){
		arr_origin[have++] = arr[i];
	}

	return have;
}
/**
 * @brief bucket_sort 
 *
 * @param arr[]]
 * @param len
 */
void bucket_sort(int arr[], int len){
	if(arr == NULL || len <= 0)
		return ;
	int min = arr[0];	
	int max = arr[0];
	int MIN;
	int MAX;
	int size;
	int i;
	int have = 0 ;
	
	//get the min and max num in arr
	for(i = 0;i < len;i++){
		if(arr[i] < min){
			min = arr[i];	
		}	
		if(arr[i] > max){
			max = arr[i];	
		}
	}
	//according to the max and min num to build hash arr	
	MIN = min/1;//DIY
	MAX = max/1;
	size = MAX - MIN + 1;
	Node** hash_arr = (Node**)malloc(sizeof(Node*)*size);	
	memset(hash_arr,0,size*sizeof(Node*));
		
	//push the num into the hash  list
	for(i = 0;i < len;i++){
		int index = arr[i]/1 - MIN;	//find which hash list
		push(&hash_arr[index],arr[i]);
	}
	//use the insert sort to sort the each hash list 
	//and get the in order num in hash list to the arr
	for(i = 0;i < size;i++){
		have = insert_sort(hash_arr[i],arr,len,have);	
	}

	//last to free hash_arr and the node in each hash_list;
	//there to omitted
	//Free(hash_arr,size);
	return ;
}

int main()
{
	int arr[6] = {5,2,4,6,1,3};
	bucket_sort(arr,6);
	show(arr,6);
	return 0;
}

