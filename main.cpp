
#include<iostream>
#include<string>
using namespace std;
int main()
{
	char choice;
	cin >> choice;
	switch (choice)
	{
	case 'l':
		cout << "username "<<endl;
		cout << "password" << endl;
		break;

	case 'r':
		cout << "info" << endl;
		break;
	default:
		cout << "you have entered an invalid choice";
	}

	if (choice == 'r')
	{
		cout << "now login after registering" << endl;
	}
cout << "thank you for logging in " << endl;
cout << "now type two number to add" << endl;
int b, c;
cin >> b;
cin >> c;
cout << b + c;
}
