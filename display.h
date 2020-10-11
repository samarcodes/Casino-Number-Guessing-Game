#include<iostream>
#include<string.h>

using namespace std;

//class for display related methods
class Display
{
public:
	void printMessageCenter(const char* message);
	void headMessage(const char *message);
	void welcomeMessage();
	void drawLine(int n, char symbol);
	void rules();
};
void Display::drawLine(int n, char symbol)
{
	for (int i = 0; i < n; i++)
		cout << symbol;
	cout << "\n" ;
}
void Display::rules()
{
	headMessage("RULES OF THE GAME");
	cout << "\n\n\n\n";
	drawLine(80, '-');
	cout << "\t1. Choose any number between 1 to 10\n";
	cout << "\t2. If you win you will get 10 times of money you bet\n";
	cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
	drawLine(80, '-');
	cout << "\n\n\n\t\t\t Enter any key to continue.....";
	getchar();
}
//Align the message
void Display::printMessageCenter(const char* message)
{
	int len = 0;
	int pos = 0;
	//calculate how many space need to print
	len = (78 - strlen(message)) / 2;
	//print spaces
	for (pos = 0 ; pos < len ; pos++)
	{
		cout << " ";
	}
	//print message
	cout << message;
}
//Head message
void Display::headMessage(const char *message)
{
	system("cls");
	cout << "###########################################################################";
	cout << "\n############                                                   ############";
	cout << "\n############             Casino Game Project in C++            ############";
	cout << "\n############                                                   ############";
	cout << "\n###########################################################################";
	cout << "\n------------------------------------------------------------------------------\n";
	printMessageCenter(message);
	cout << "\n------------------------------------------------------------------------------";
}
//Display message
void Display::welcomeMessage()
{
	headMessage("");
	cout << "\n";
	cout << "\n\t   **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
	cout << "\n\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
	cout << "\n\t        =                                           =";
	cout << "\n\t        =                    WELCOME                =";
	cout << "\n\t        =                      TO                   =";
	cout << "\n\t        =                 CASINO GAME               =";
	cout << "\n\t        =                                           =";
	cout << "\n\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
	cout << "\n\n\t   **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
	cout << "\n\n\n\t\t\t Enter any key to continue.....";
	getchar();
}