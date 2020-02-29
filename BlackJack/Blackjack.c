/*
 * Blackjack.c
 *
 *  Created on: Feb. 28, 2020
 *      Author: Srikanth Pendem
 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

	int printRandoms()
	{
	    for (int i = 0; i < 1; i++) {
	        int num = (rand() % (10 - 1 + 1)) + 1;
	        return num;
	    }
	}

	int playerwon(){return printf("player won");}
	int dealerwon(){return printf("Dealer won");}

	int main()
	{
	    srand(time(0));
	    char d;								//creating a char variable to question the player
	    //scanf ("%c ", &d);					//asks if player wants to play
	    int a = printRandoms(); 		//prints a random number card from deck
	    int b = printRandoms();
	    int c = a+b;
	    int a1 = printRandoms(); 		//prints a random number card from deck
	    int b1 = printRandoms();
	    int c1 = a1+b1;
	    printf(" %d ",c);				//prints what card got from deck
	    printf(" %d ",c1);
	    int i=c, k=c1;
	    int j;
	    while(1) {
	    	char d;								//creating a char variable to question the player
	    	scanf ("%c ", &d);					//asks if player wants to play
	    		if(d=='y') {						//if the player hits y to start game
	    		int e = printRandoms(); 		//prints a random number card from deck
	    		j = printRandoms();
	    		k = k+j; 				//Dealer's next card
	    		i = i+e;						//Deal the next card and add to previous card

	    		printf(" %d ",e);				//prints what card got from deck
	    		printf("%d ",i);				//prints the total. player

	    		printf(" %d ",j);				//prints what card got from deck
	    		printf("%d ",k);				//prints the total dealer
	    		}
	    		if(d=='n') {
	    			j = printRandoms();
	    			k = k+j;
	    		}

	    		if((i>21 && k<21)||(k==21))
	    		return dealerwon();

	    		if((i==21)||(k>21 && i<21))
	    		return playerwon();

	    		if(i>21 || k>21)
	    			return(1);

 }										//while loop end
}											//main ends
