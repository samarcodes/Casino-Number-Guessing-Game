#include<iostream>
//#include"display.h"
#include"player.h"

int main()
{
	class PlayerInfo obj_player ;
	char choice;
	//init game
	obj_player.init();
	//Set wallet amount
	obj_player.setAmount();
	do
	{
		cout << "\n\nYour current balance is $" << obj_player.getAmount() << "\n";
		//Set bet amount
		obj_player.setBettingAmount();
		//Set guess number
		obj_player.setGuessNumber();
		//Check whether player lose or win the game
		const bool isPlayerWin = obj_player.isPlayerWin();
		//Update wallet amount
		obj_player.updateAmount(isPlayerWin);
		//Display the result after each play
		obj_player.displayMessageAfterPlay(isPlayerWin);
		//Check wallet amount and accordingly ask the player
		//to play again
		if (obj_player.getAmount() == 0.00f)
		{
			cout << "\nYou have no money to play, Good Bye..";
			break;
		}
		//Ask use choice for replay
		cout << "\n\n-->Do you want to play again (y/n)? ";
		cin >> choice;
	}
	while (choice == 'Y' || choice == 'y');
	cout << "\n\n\n";
	obj_player.drawLine(70, '=');
	cout << "\nThanks for playing game. Your balance amount is $" << obj_player.getAmount() << "\n\n";
	obj_player.drawLine(70, '=');
	cin.ignore();
	getchar();
	return 0;
}