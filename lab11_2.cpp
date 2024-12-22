#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	return rand() % 13 + 1;
}

int calScore(int x,int y,int z){
	int score_x = cardScores[x];
	int score_y = cardScores[y];
	int score_z = cardScores[z];
	return (score_x + score_y + score_z) % 10;
	//Write the function to calculate the score with is the rightmost digit of summation of the scores from three cards.
	//Return the score. 
}

int findYugiAction(int s){	
	if(s == 9) return 2; // Yugi will definitely stay (2) when current score (s) is equal to 9
	else if(s < 6) return 1; // Yugi will definitely draw (1) when current score (s) is less than 6
	else{// If current score is 6,7,8, Write conditions here using random number 
		if( rand() % 100 + 1 <= 69 ){
			return 1; //Yugi will draw with probability 69% 
		}else {
			return 2; //will stay with probability 31% 
		}
		
	}
}

void checkWinner(int p, int y){
	// Write condition for cout in this function
		cout << "\n---------------------------------\n";
	    if ( p > y){
			cout << "|         Player wins!!!        |\n";
	}else if (y > p){
		    cout << "|          Yugi wins!!!         |\n";
	}else {
		    cout << "|             Draw!!!           |";
	}
	    cout << "---------------------------------\n";
	
}

int main(){	
    srand(time(0)); //This line of code is not completed. Fill the correct input of srand(); 

	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0};//This line of code is not completed. You need to initialize value of yugiCards[].
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2); //This line of code is not completed. You need to set the condition to do loop if user's input is not 1 or 2. 
	if(playerAction == 1){
		playerCards[2] = drawCard();
  		playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[playerCards[2]] <<"\n";
		cout << "Your new score: " << playerScore << "\n";
		
	}
	cout << "------------ Turn end -------------------\n";
	
	
	
	cout << "\n---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		yugiCards[2] = drawCard();
		yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] << "\n";
		cout << "Yugi's new score: " << yugiScore << "\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore);
}
