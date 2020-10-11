#include<iostream>
#include"display.h"
#include<cstdlib>
#include<ctime>

using namespace std;

//Main class of the project
class PlayerInfo: public Display
{
public:
	int getGuessNumber();
	void setGuessNumber();
	void setAmount();
	float getAmount();
	int getdice();
	void updateAmount(const bool isWin);
	void setBettingAmount();
	bool isPlayerWin();
	void init();
	void displayMessageAfterPlay(const bool isWin);
	PlayerInfo(): m_amount(0.00), m_bettingAmount(0.00), m_guessNumber(-1)
	{
	}
private:
	float m_amount; //Total balance of player
	float m_bettingAmount; //Betting Amount
	int m_guessNumber; //Number guessed by player
};
//Set Wallet Amount
void PlayerInfo::setAmount()
{
	headMessage("Set Amount");
	do
	{
		cout << "\n\nEnter Deposit amount to play game : $";
		cin >> m_amount;
		if (m_amount < 0.01f)
		{
			cout << "\n\nPlease Enter valid amount to play the Game!!";
		}
	}
	while (m_amount < 0.01f);
}
//Get wallet Amount
float PlayerInfo::getAmount()
{
	return m_amount;
}
int PlayerInfo::getGuessNumber()
{
	return m_guessNumber;
}
//Get number from player
void PlayerInfo::setGuessNumber()
{
	headMessage("Set Guess Number");
	do
	{
		cout << "\n\nGuess your number to bet between 1 to 10 :";
		cin >> m_guessNumber;
		if (m_guessNumber <= 0 || m_guessNumber > 10)
			cout << "\n\nPlease check the number!! should be between 1 to 10\n"
			     << "\nRe-enter the number\n ";
	}
	while (m_guessNumber <= 0 || m_guessNumber > 10);
}
//Update wallet amount
void PlayerInfo::updateAmount(const bool isWin)
{
	m_amount = isWin ? (m_amount + (m_bettingAmount * 10)) : (m_amount - m_bettingAmount);
}
//Set betting amount
void PlayerInfo::setBettingAmount()
{
	headMessage("Set Bet Amount");
	do
	{
		cout << "\n\nEnter money to bet : $";
		cin >> m_bettingAmount;
		if (m_bettingAmount > m_amount)
		{
			cout << "\n\nYour wallet amount is $" << m_amount;
			cout << "\n\nYour betting amount is more than your current balance";
		}
	}
	while (m_bettingAmount > m_amount);
}
//Check is player w
bool PlayerInfo::isPlayerWin()
{
	// Will hold the randomly generated integer between 1 and 10
	const int dice = rand() % 10 + 1;
	return ((dice == getGuessNumber()) ? true : false);
}
//Init the game.
void PlayerInfo::init()
{
	welcomeMessage();
	// "Seed" the random generator
	srand(time(0));
	rules();
}
//Display message after each play
void PlayerInfo::displayMessageAfterPlay(const bool isWin)
{
	if (isWin)
	{
		cout << "\n\nGood Luck!! You won $" << m_bettingAmount * 10;
		cout << "\n\nNow update Amount is $" << m_amount;
	}
	else
	{
		cout << "\n\nBad Luck this time !! You lost $" << m_bettingAmount << "\n";
		cout << "\n\nNow update Amount is $" << m_amount;
	}
}