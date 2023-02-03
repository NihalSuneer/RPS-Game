#include <iostream>
using namespace std;

int chooseDifficulty()
{
    int numberofrounds;
    int userinput;
	bool validChoice = false;
	
    cout<<"**************************"<<"\n";
    cout<<"******** RPS-GAME ********"<<"\n";
    cout<<"**************************"<<"\n";
    cout<<"choose difficulty level"<<"\n";
    cout<<"1. Easy (3 Rounds)"<<"\n";
    cout<<"2. Medium (5 Rounds)"<<"\n";
    cout<<"3. Hard (10 Rounds)"<<"\n";
    cout<<"**************************"<<"\n\n";
	
	while(!validChoice)
	{
		validChoice = true;
		cin>>userinput;
		switch (userinput)
		{
			case 1: numberofrounds = 3;
			break;
			case 2: numberofrounds = 5;
			break;
			case 3: numberofrounds = 10;
			break;
			default: cout<<"Invalid Choice";
			validChoice = false;
			break;
		}
		
	}
    
    return numberofrounds;            //number of rounds to be played
}

int gameChoices()
{
    int userChoice; //user selects an option
    
    cout<<"******************"<<"\n";
    cout<<"Rock-Paper-Scissors?"<<"\n";
    cout<<"1. Rock"<<"\n";
    cout<<"2. Paper"<<"\n";
    cout<<"3. Scissors"<<"\n";
    cout<<"**************************"<<"\n\n";
    cin>>userChoice;

    return userChoice;
}

char mapping(int playerChoice)
{
    char character;

	// character = (playerChoice == 1)? 'R' : (playerChoice == 2)? 'P' : 'S';
    switch (playerChoice)
    {
        case 1: character = 'R';
        break;
        case 2: character = 'P';
        break;
        case 3: character = 'S';
        break;
        default: character = 0;
        break;
    }
    return character;
}

char RandombotChoices()
{
    string allCharacters = "RPS";
	char randomCharacter;
	
	int randomIndex = rand() % allCharacters.size();
	randomCharacter = allCharacters[randomIndex];
	
	return randomCharacter;
}

string GetItem(int choice)		{	return (choice == 1)? "Rock" : (choice == 2)? "paper" : "Scissor";	}

int selectedChoices(char playerChoice, char botChoice)
{

	cout<<"You have selected: "<< GetItem(playerChoice) <<" |";
    cout<<"| Bot has selected: "<< GetItem(botChoice);
	
	switch (playerChoice)
    {
        case 'R': cout<<"\nYou have selected: Rock |"<<"\t";
        break;
        case 'P': cout<<"\nYou have selected: Paper |"<<"\t";
        break;
        case 'S': cout<<"\nYou have selected: Scissors |"<<"\t";
        break;
        default : cout<<"\nYou have'nt respond"<<"\t";
        break;
    }
    switch (botChoice)
    {
        case 'R': cout<<"| Bot has selected: Rock"<<"\n\n";
        break;
        case 'P': cout<<"| Bot has selected: Paper"<<"\n\n";
        break;
        case 'S': cout<<"| Bot has selected: Scissors"<<"\n\n";
        break;
        default : cout<<"| Bot didn't respond"<<"\n";
        break;
    }
    return 0;
}

double gameRules(char playerChoice, char botChoice)
{
    double statusofRound;
    
    if((playerChoice == 'R' && botChoice == 'S') || (playerChoice == 'S' && botChoice == 'P') || (playerChoice == 'P' && botChoice == 'R'))
    {
        statusofRound = 1;    //win condition
        cout<<"You Win :)"<<"\n";
    }    
    else if(playerChoice == botChoice)
    {
        statusofRound = 0;    //draw condition
        cout<<"It's a Draw :|"<<"\n";
    }
    else 
    {
        statusofRound = 0.5;    // lose condition
        cout<<"You Lose :("<<"\n";
    }
    return statusofRound;
}

double RPSgame(int round)    //main game function
{
    double statusofRound;
    int playerChoice; 
    char pyselectedChoice;
    char computerChoice;
    double totalPoint=0;  
    int count=0;
    
    for(int i=0; i<round; i++)
    {
        count = count+1;
        cout<<"\nRound"<<count<<"\t";
        
        playerChoice = gameChoices();    //player imput integer 1 2 3
        pyselectedChoice = mapping(playerChoice);    //player choice character R P S
        computerChoice = RandombotChoices();    // bot choice character R P S
        selectedChoices(pyselectedChoice, computerChoice);
        statusofRound = gameRules(pyselectedChoice, computerChoice);
        
        totalPoint += statusofRound;     //1+0.5+0+1     
    }
   
    return totalPoint;     //1+0.5+0+1   = 2.5 
}

int pointcalculate(double totalPoint)
{
    int score;
    
    score = 10*totalPoint;
     
    return score;                // score if win =10, lose =5
}

int main() 
{
    srand(time(0));
    int numberofRounds;
    double totalPoint;
    int score;

    //choose difficulty - Easy, medium, hard
    numberofRounds = chooseDifficulty();
    //RPS game rules 
        //player move
        //status of the round
        //total point
    totalPoint = RPSgame(numberofRounds);
        //Displya win/lose by analysing status of round
   
    //point calculate for each round win-10, lose -5
    score = pointcalculate(totalPoint);
    //cout<<"\n"<<"**************************"<<"\n";
    cout<<"\n\n"<<"Your Total Score is: "<<score<<"\n";
}