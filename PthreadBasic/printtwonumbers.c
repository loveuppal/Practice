#include<stdio.h>
#include<pthread.h>
int *threadFunction( int *v) {
	*v = 25;									//  to print this value(function)
	return 0;
}
int main() {
	int y = 19;									// also to print this value(main)
	pthread_t id;									// create a id
	pthread_create (&id, NULL, &threadFunction, &y);// joining id with the function
	printf("%d ", y);								// prints value(main)
	void *result;									// creates a result
	pthread_join (id, &result);							// joins id with result
	printf(" %d",y );								//prints value(function

}
