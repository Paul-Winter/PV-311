#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>


using namespace std;
int rollback = 5;
int banya = 7;
string* rang = new string[7]{ "Рядовой","Сержант","Старшина","Лейтенант","Капитан","Майор","Полковник" };
string* Rod = new string[4]{ "Сухопутные войска","Воздушные силы","Военно-Морской флот", "Ракетно-космические силы" };
string* oblast = new string[4]{ "Московская","Воронежская","Ставропольский край", "Ростовская" };


class RangManipulat {
public:
	RangManipulat() {}

};

class Tamagoji : public RangManipulat
{
public:
	string name;
	int health;
	int mood;

	Tamagoji() : health{ 75 }, mood{ 75 }
	{}
	Tamagoji(string name) : name{ name }, health{ 75 }, mood{ 75 }
	{}

	~Tamagoji() {}

	virtual int decrease_health()
	{
		return health -= 10;
	}
	virtual int increase_health()
	{
		return health += banya;
	}
	virtual int decrease_mood()
	{
		return mood -= 15;
	}
	virtual int increase_mood()
	{
		return mood += 15;
	}
};
class ment : public Tamagoji
{

public:
	int rang_num;
	string rang_name;
	ment() : Tamagoji(), rang_num{ 0 }, rang_name{ rang[0] }
	{}
	ment(string name) : Tamagoji(name), rang_num{ 0 }, rang_name{ rang[0] }
	{
		cout << "Name your's Ment: " << name << " Rang : " << rang_name << endl;
	}

	virtual int increase_rang()
	{
		return rang_num += 1;
	}
	virtual int decrease_rang()
	{
		return rang_num -= 1;
	}
	virtual string rename_rang()
	{
		return rang_name = rang[rang_num];
	}
	virtual int decrease_health()
	{
		return health -= 10;
	}
	virtual int increase_health()
	{
		return health += rollback;
	}
	virtual int decrease_mood()
	{
		return mood -= 15;
	}
	virtual int increase_mood()
	{
		return mood += banya;
	}

	int line_ment() {
		int sec = 1;
		char choise;
		cout << "Call your ment: ";
		cin >> name;
		while (health > 0 && mood > 0 && sec > 0) {
			sec = 1000;
			cout << "    __  ___   ______   _   __   ______" << endl;
			cout << "   /  |/  /  / ____/  / | / /  /_  __/" << endl;
			cout << "  / /|_/ /  / __/    /  |/ /    / / " << endl;
			cout << " / /  / /  / /___   / /|  /    / /" << endl;
			cout << "/_/  /_/  /_____/  /_/ |_/    /_/" << endl;
			decrease_health();
			cout << "Name :" << name << endl;
			cout << "Rang: " << rang_name << endl;
			cout << "HEALTH: " << health << endl;
			decrease_mood();
			cout << "MOOD: " << mood << endl;
			--sec;
			Sleep(sec);
			system("cls");
			cout << "Choose Yummy - Rollback(r) or Banya(b)";
			cin >> choise;
			switch (choise) {
			case'r':
				increase_health();
				cout << "+5\n";
				cout << "HEALTH: " << health << endl;
				Sleep(5000);
				system("cls");
				break;
			case'b':
				increase_mood();
				cout << "+7\n";
				cout << "MOOD: " << mood << endl;
				Sleep(5000);
				system("cls");
				break;
			default:
				cout << " ну смотри как дохнет..." << endl;
				continue;
			}

			if (health == 100 && mood == 100) {
				increase_rang();
				rename_rang();
			}
			else if (health < 35 || mood < 25) {
				decrease_rang();
				rename_rang();
			}
			else {
				continue;
			}

			if (health < 0 || mood < 0) {
				cout << "Congratulatons! Your MENT DIE! You WIN!" << endl;
				cout << "i'm joking" << endl;
				system("cls");
				Sleep(100000);
				return 0;
			}
			else if (health == 100 && mood == 100 && rang_num == 7) {
				cout << "OMG!!!! YOU ACTUALY WIN!!!!! HUUUUUGE RESPECT!!!!!!!" << endl;
				system("cls");
				return 0;
			}
			system("cls");

		}
	}
};

class voyaki : public ment, public RangManipulat
{
public:
	string RodV;

	voyaki() : ment(), RodV{ Rod[0] }
	{}
	voyaki(string name, char V) :ment(name), RodV{ Rod[V] }
	{
		cout << "Name your's voyaka: " << name << " Rod Voysk: " << RodV << endl;
	}
	~voyaki() {}
	int increase_rang() override
	{
		return rang_num += 1;
	}
	int decrease_rang() override
	{
		return rang_num -= 1;
	}
	virtual string rename_rang()
	{
		return rang_name = rang[rang_num];
	}
	int decrease_health() override
	{
		return health -= 10;
	}
	int increase_health() override
	{
		return health += rollback;
	}
	int decrease_mood() override
	{
		return mood -= 15;
	}
	int increase_mood() override
	{
		return mood += banya;
	}
	int line_voyaka() {
		char choise;
		cout << "Call your voyaka: ";
		cin >> name;
		char Rod;
		cout << "Сухопутные войска(S)\nВоздушные силы(V)\nВоенно - Морской флот(M)\nChoose Rod Voysk: ";
		cin >> Rod;
		switch (Rod)
		{
		case 'S':
			RodV = RodV[0];
			health -= 10;
			mood -= 10;
			break;
		case 'V':
			RodV = RodV[1];
			health += 10;
			mood -= 10;
			break;
		case 'M':
			RodV = RodV[2];
			health -= 10;
			mood += 10;
			break;
		default:
			break;
		}


		while (health > 0 && mood > 0) {
			cout << " _    __   ____   __  __   ___       __  __    ___" << endl;
			cout << "| |  / /  / __ \  \ \/ /  /   |     / / /_/  /   |" << endl;
			cout << "| | / /  / / / /   \  /  / /| |    / , <    / /| |" << endl;
			cout << "| |/ /  / /_/ /    / /  / ___ |   / /| |   / ___ |" << endl;
			cout << "|___/   \____/    /_/  /_/  |_|  /_/ |_|  /_/  |_|" << endl;
			decrease_health();
			cout << "Name :" << name << endl;
			cout << "Rang: " << rang_name << endl;
			cout << "HEALTH: " << health << endl;
			decrease_mood();
			cout << "MOOD: " << mood << endl;
			Sleep(10000);
			system("cls");
			cout << "Choose Yummy - Rollback(r) or Banya(b)";
			cin >> choise;
			switch (choise) {
			case'r':
				increase_health();
				cout << "+5\n";
				cout << "HEALTH: " << health << endl;
				Sleep(5000);
				system("cls");
				break;
			case'b':
				increase_mood();
				cout << "+7\n";
				cout << "MOOD: " << mood << endl;
				Sleep(5000);
				system("cls");
				break;
			default:
				cout << " ну смотри как дохнет..." << endl;
				system("cls");

				break;
			}
			if (health == 100 && mood == 100) {
				increase_rang();
				rename_rang();
				return 0;
			}
			else if (health < 35 || mood < 25) {
				decrease_rang();
				rename_rang();
				return 0;
			}
			else {
				continue;
			}

			if (health == 0 || mood == 0) {
				cout << "Congratulatons! Your Voyaka DIE! You WIN!" << endl;
				cout << "i'm joking" << endl;
				system("taskkill / im:Tamagoji.exe");
			}
			else if (health == 100 && mood == 100 && rang_num == 7) {
				cout << "OMG!!!! YOU ACTUALY WIN!!!!! HUUUUUGE RESPECT!!!!!!!" << endl;
				system("taskkill / im:Tamagoji.exe");
			}
			Sleep(10000);
			system("cls");
		}
	}
};

/*class chinusha : public Tamagoji, public RangManipulat
{
public:
	string Oblast;

	chinusha(){}
	chinusha(string name, string Oblast) : Tamagoji(name), Oblast{ Oblast }
	{
		cout << "Name your's Chinusha: " << name << " Oblast: " << Oblast << endl;
	}
	~chinusha(){}
	int decrease_health() override
	{
		return health -= 10;
	}
	int increase_health() override
	{
		return health += rollback;
	}
	int decrease_mood() override
	{
		return mood -= 15;
	}
	int increase_mood() override
	{
		return mood += banya;
	}

};*/




int main()
{
	setlocale(LC_ALL, "rus");

	ment playM;
	voyaki playV;
	//chinusha playCh;


	char choise;
	cout << "Обратите внимани!!! Что при вводе Rollback(r) добавляется 5 единиц к Здоровью,\n а при вводе Banya(b) добавляется 7 единиц к Настроение\n Помни в данной ситуации персонаж выбранный ниже твой друг,\n а не отвратительное существо над которым надо насмехаться!\n";
	cout << " do you wanna start game? y/n - ";
	cin >> choise;
	switch (tolower(choise))
	{
	case 'y':
		char choise_;
		cout << "Choose type of your tamagoji:\nM - Ment\nV - Voyaka" << endl;
		cin >> choise_;
		switch (tolower(choise_)) {
		case 'm':
			playM.line_ment();
			break;
		case 'v':
			playV.line_voyaka();
			break;
		default:
			break;
		}
	case 'n':
		cout << "ну как хочешь..." << endl;
		break;
	default:
		return 0;
	}
}

