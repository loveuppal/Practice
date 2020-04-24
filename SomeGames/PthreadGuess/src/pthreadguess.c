/*Creating two ptherads for two search algorithms*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int win() {
	printf("\nBinarySearch Guessed! ");							//Guesser1 wins
}
int win2() {
	printf("\nLinearSearch Guessed! ");							//Guesser2 wins
}

int binarySearch(int x)
{
	int first = 0, last = 1000, arr[1000];

	for(int i = 0; i <= 1000; i++){
	    arr[i] = i;									//creating an array containing 1 to 1000 numbers
	}
    while (first <= last) {
        int middle = first + (last - first) / 2;	//calculating mid index of the array

        if (arr[middle] == x)
            return win();							//if guessed number = mid index, return win1

        if (arr[middle] < x)
            first = middle + 1;						//finds new mid index if guessed number is less than previous mid index
        else
            last = middle - 1;						//finds new mid index if guessed number is greater than previous mid index
    }
    printf("Out Reach");							//returns if guessed number is out of limits
    return 0;
}

int linearsearch(int x)
{
    int i,j, arr[1000];
    for(int i = 0; i <= 1000; i++){
    	    arr[i] = i;								//creating an array containing 1 to 1000 numbers
    }
    for (j = 0; j < 1000; j++)
        if (arr[j] == x)							//checks if input is equal to contained numbers in the array
            return win2();
}


void *Guess1(int *x) {								//Guesser 1 thread that binary searches
	int n;
	*x =binarySearch(n);
	usleep(2000);									//sleeps for 2 seconds

}
void *Guess2(int *x) {								//Guesser 2 thread that binary searches
	int n;
	*x =linearsearch(n);
	usleep(2000);									//sleeps for 2 seconds

}

int main() {

	int x;
	printf("enter the number: ");
	scanf("%d", &x);							//takes in the guess number

	pthread_t id1, id2;
	pthread_create (&id1, NULL, &Guess1, &x);	// creates id with the Guess1  thread
	pthread_create (&id2, NULL, &Guess2, &x);	// creates id with the Guess2 thread

	void *result;								// creates a result
	pthread_join (id2, &result);				// joins id with result
	pthread_join (id1, &result);				// joins id with result
}
