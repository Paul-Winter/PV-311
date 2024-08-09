//ЗАДАНИЕ 4
//Написать функцию, выводящую на экран переданную ей игральную карту.

#include <iostream>
using namespace std;

void showCard(int suit, int num)
{
	char charCard[13] = {'6','7','8','9','0','V','D','K','T'};

	cout << "\t.--------.\n\t|";
	if (num == 10) cout << "1";
	cout << charCard[num - 6];
	if (num != 10) cout << " ";
	cout << "      |" << endl;

	switch (suit) {
	case 1:
		cout << "\t|   _    |\n\t|  ( )   |\n\t| (_x_)  |\n\t|   A    |" << endl;
		break;
	case 2:
		cout << "\t|   /\\   |\n\t|  /  \\  |\n\t|  \\  /  |\n\t|   \\/   |" << endl;
		break;
	case 3:
		cout << "\t|  _  _  |\n\t| ( \\/ ) |\n\t|  \\  /  |\n\t|   \\/   |" << endl;
		break;
	case 4:
		cout << "\t|   .    |\n\t|  / \\   |\n\t| (_,_)  |\n\t|   A    |" << endl;
		break;
	}

	cout << "\t|      ";
	if (num != 10) cout << " ";
	if (num == 10) cout << "1";
	cout << charCard[num - 6] << "|\n\t'--------'" << endl;
}

int main()
{
	int suit, num;

	cout << "Viberi mast:\ntrefy (1), bubny (2), chervy (3), piky (4): ";
	cin >> suit;
	
	cout << "Viberi kartu:\n6 (6), 7 (7), 8 (8), 9 (9), 10 (10), valet (11), dama (12), korol (13), tuz (14): ";
	cin >> num;

	showCard(suit, num);

	return 0;
}