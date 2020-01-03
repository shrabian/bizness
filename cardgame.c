#include <stdio.h>
#include <stdlib.h>

#define DECK 52								//The number of cards in a deck
#define MAX_RANK 13					        //Highest card rank
#define SUITS 4								//Number of card suits
#define SHUFFLENESS 1000					//The level cards are shuffled by
						
#define PLAYERS 4							//Number of players in the game
#define HAND 5								//Number of cards dealt per player
#define TRIALS 10000						//Number of games played

#define SEED 987234							//For randomness

//All cards have a rank and suit (unique) and can either be dealt or not
typedef struct{
	int rank, dealt;
	char suit;
}card_t;

void make_deck(card_t *);
void shuffle(card_t *);
int deal(card_t *);

//Simulates a 'TRIALS' number of games
int
main(int argc, char *argv[]){
	card_t cards[DECK];
	int i, j, pairs=0;
	
	//Fills 'cards' with 'DECK' unique cards
	make_deck(cards);
	srand(SEED);
	
	/*Plays 'TRIALS' games, each time shuffling 'cards', dealing and counting 
	the number of pairs dealt */
	for(i=0; i<TRIALS; i++){
		shuffle(cards);
		for(j=0; j<PLAYERS; j++){	
			pairs += deal(cards);
		}
	}
	printf("%4.3lf of %d hands dealt were pairs\n", 
		(double)pairs/(TRIALS*PLAYERS), TRIALS*PLAYERS);

	return 0;
}

//Deals a 'HAND' number of cards
int
deal(card_t *cards){
	card_t hand[HAND];
	int i=0, j, index, pairs=0, num_same;
	
	//Deals 'HAND' cards to a player ensuring, dealt cards are not redealt
	while(i < HAND){
		index = rand()%DECK;
		if(!cards[index].dealt){
			hand[i] = cards[index];
			cards[index].dealt = 1;  
			i++;
		}
	} 
	
	//Counts the number of pairs in 'hand'
	for(i=0; i<HAND; i++){
		num_same = 0;
		for(j=0; j<HAND; j++){
			if(hand[i].rank == hand[j].rank){
				if(i<j){
					num_same ++;
				}
				//Prevents double counting
				else if(i>j){
					break;
				}
			}
		}
		//Ensures only pairs (and not for example triples) are counted
		if(num_same == 1){
			pairs++;
		}
	}
	return pairs;
}

//Gives each card in 'cards' a suit and rank
void
make_deck(card_t *cards){
	int i, j;
	char suit[SUITS] = {'C', 'D', 'H', 'S'}; //Suits present in a normal deck
	
	//Assigns 'DECK' cards a unique rank and suit combination
	for(i=0; i<MAX_RANK; i++){
		for(j=0; j<SUITS; j++){
			cards[i*SUITS + j].rank = i+1;
			cards[i*SUITS + j].suit = suit[j];
		}
	}
}

//Randomises 'cards' order
void 
shuffle(card_t *cards){
	int i, c1, c2;
	card_t tmp;
	
	/*Makes the 'dealt' member false since shuffling takes place before
	play when cards are returned to the deck */
	for(i=0; i<DECK; i++){
		cards[i].dealt = 0;
	}
	
	/* Chooses two cards random cards in 'cards' and swaps them, repeats
	until 'SHUFFLENESS' level is reached */
	for(i=0; i<SHUFFLENESS; i++){
		c1 = rand()%DECK;
		c2 = rand()%DECK;
		while(c1==c2){
			c2 = rand()%DECK;
		}
		tmp = cards[c1];
		cards[c1] = cards[c2];
		cards[c2] = tmp;
	}
}

		
	