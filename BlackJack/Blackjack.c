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

	int RandomNumbers()
	{
	    for (int i = 0; i < 1; i++)						//prints only single number
	    {
	        int num = (rand() % (10 - 1 + 1)) + 1;				//prints random numbers from specified limits
	        return num;
	    }
}

	int playerwon()
	{
		return printf("player won");					//to display that player has won
}

	int dealerwon()
	{
		return printf("Dealer won");					//to display that dealer has won
}

	int randAdd() {
		int a = RandomNumbers();
		int b = RandomNumbers();
		return a+b;							//Adds two random numbers
	}

	int main()
	{
	    srand(time(0));							//actualize the random numbers on every RUN
	    int Rnum1, Rnum2, Rnum3, Rnum4;

	    int TwoCardsofPlayer = randAdd(Rnum1, Rnum2);
	    int TwoCardsofDealer = randAdd(Rnum3, Rnum4);

	    printf(" %d ",TwoCardsofPlayer);					//prints what card got from deck
	    printf(" %d ",TwoCardsofDealer);

	    int P_Picks=TwoCardsofPlayer, D_Picks=TwoCardsofDealer;  //storing values of first two deal of cards for the further iteration

	    while(1) {
	    	char in;
	    	scanf ("%c ", &in);						//asks if player wants to play
	    		if(in =='y') {						//player hits y to starts to game
	    		int ThirdPick_P = RandomNumbers(); 			//Picking the third card of player
	    		int ThirdPick_D = RandomNumbers();				//picking third card of the dealer
	    		D_Picks = D_Picks+ThirdPick_D;					//Iterating the Card picks of the Dealer
	    		P_Picks = P_Picks+ThirdPick_P;					//Iterating the card picks of the player

	    		printf(" %d ",ThirdPick_P);						//Prints the Third card picked by Player
	    		printf("%d ",P_Picks);							//prints the sum of all card iterations

	    		printf(" %d ",ThirdPick_D);						//Prints the Third card picked by Dealer
	    		printf("%d ",D_Picks);							//prints the sum of all card iterations
	    		}

	    		if((P_Picks>21 && D_Picks<21)||(D_Picks==21))
	    		return dealerwon();

	    		if((P_Picks==21)||(D_Picks>21 && P_Picks<21))
	    		return playerwon();

	    		if(P_Picks>21 || D_Picks>21)
	    			return(1);

 }															//while loop end
}															//main ends
