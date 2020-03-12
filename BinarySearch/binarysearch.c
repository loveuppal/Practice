#include <stdio.h>
int win() {
	printf("Guessed!");				//prints if number found in the array
}
int binarySearch(int x)
{
	int first = 0, last = 1000, arr[1000];

	for(int i = 0; i <= 1000; i++){
	    arr[i] = i;					//creating an array containing 1 to 1000 numbers
	}
    while (first <= last) {
        int middle = first + (last - first) / 2;	//calculating mid index of the array
        if (arr[middle] == x)				//if guessed number = mid index
            return win();				//returns to win
        if (arr[middle] < x)
            first = middle + 1;				//finds new mid index if guessed number is less than previous mid index
        else
            last = middle - 1;				//finds new mid index if guessed number is greater than previous mid index
    }
    printf("Out Reach");				//returns if guessed number is out of limits
    return 0;
}
int main() {

	int x;
	printf("enter the number: ");
	scanf("%d", &x);				//takes the guess number
	binarySearch(x);				//binarysearch function

}
