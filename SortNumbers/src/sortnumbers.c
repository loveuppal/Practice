/*
 * sortnumbers.c
 *
 *  Created on: Feb. 25, 2020
 *      Author: Srikanth Pendem
 */
#include<stdio.h>
#include<stdlib.h>

			    /*Q-SORT FUNCTION*/
int compar(void *pa, void *pb) {
    int a =  *(int*)pa;
    int b = *(int*)pb;
    return (a-b);				//sorts ascending
}

			    /*MAIN FUNCTION*/
int main() {
    int array[] = {9, 3, 6, 19, 7, 21};		//array of numbers
    int L = sizeof(array)/sizeof(int);		//calculating the size of the array
    for(int j=0;j<L;j++)
	printf("%d ",array[j]); 		//prints the array as it is
    qsort(array, L, sizeof(int), compar);	//qsort function of quick-sort algorith
    printf("\n");
    for(int i=0;i<L;i++)
    	printf("%d ",array[i]);			//prints the sorted numbers
}
