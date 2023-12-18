#include<iostream>
#include<string>
#include <fstream>
#include<cstdlib>
#include<ctime>
#include<stdlib.h>
using namespace std;
string name, usr_n,pass;
int choice, rout_selection, window;

struct Distance
{
    int Lahore = 434;
    int Islamabad = 102;
    int Mardan = 80;
    int Peshawar = 125;
};

bool login();
void sign_up();
void ticket();
void seat_assign();
void bus_timing();
int price_calc(int rout_selection, Distance distances);
void refund();
void complaint();
int main()
{
    Distance distances;

    cout << "|-----------------------------------------------|" << endl;
    cout << "            Welcome to GIKI Transport            " << endl;
    cout << "               Management System                 " << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "_________________________________________________" << endl;
    cout << "|                     |                         |" << endl;
    cout << "| 1. LOGIN            | 2. SIGN UP              |" << endl;
    cout << "|_____________________|_________________________|" << endl;
    cout << "|                     |                         |" << endl;
    cout << "| 3. REFUND           | 4. COMPLAINT            |" << endl;
    cout << "|_____________________|_________________________|" << endl;
    cout << "Option no: ";
    cin >> choice;

    system("CLS");

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        sign_up();
        login();
        break;
    case 3:
        refund();
        break;
    case 4:
        complaint();
        break;
    default:
        cout << "Invalid Selection";
    }

    system("CLS");

    cout << "|-----------------------------------------------|" << endl;
    cout << "                     WELCOME                     " << endl;
    cout << "|-----------------------------------------------|" << endl << endl;

    cout << "Option  Destinations       Duration   Fare" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1.      GIKI to Lahore     6:21 hrs   " << price_calc(1, distances) << " Rs" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "2.      GIKI to Islamabad  1:30 hrs   " << price_calc(2, distances) << " Rs" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "3.      GIKI to Mardan     3:30 hrs   " << price_calc(3, distances) << " Rs" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "4.      GIKI to Peshawar   2:10 hrs   " << price_calc(4, distances) << " Rs" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Option no: ";
    cin >> rout_selection;
    
    int a = login();
    if (a == 1) {
        switch (rout_selection)
        {
        case 1:
            ticket();
            cout << "| GIKI TO LAHORE " << endl << "|" << endl;
            cout << "| PRICE: " << price_calc(1, distances) << " Rs" << endl << "|" << endl;
            cout << "| DURATION: 6 Hours 20 Minutes" << endl << "|";
            break;
        case 2:
            ticket();
            cout << "| GIKI TO ISLAMABAD" << endl << "|" << endl;
            cout << "| PRICE: " << price_calc(2, distances) << " Rs" << endl << "|" << endl;
            cout << "| DURATION: 1 Hour 20 Minutes" << endl << "|";
            break;
        case 3:
            ticket();
            cout << "| GIKI TO MARDAN" << endl << "|" << endl;
            cout << "| PRICE: " << price_calc(3, distances) << " Rs" << endl << "|" << endl;
            cout << "| DURATION: 1 Hour" << endl << "|";
            break;
        case 4:
            ticket();
            cout << "| GIKI TO PESHAWAR " << endl << "|" << endl;
            cout << "| PRICE: " << price_calc(4, distances) << " Rs" << endl << "|" << endl;
            cout << "| DURATION: 2 Hours and 15 Minutes" << endl << "|";
            break;
        default:
            cout << "Invalid Selection";
            break;
        }
        cout << endl;
        cout << "| Please arrive on time." << endl;
        cout << "|_________________________________" << endl << endl;
    }
}
bool login()
{
    cout << "|-----------------------------------------------|" << endl;
    cout << "                      LOGIN                      " << endl;
    cout << "|-----------------------------------------------|" << endl << endl;

    string check_usr;
    string check_pass;
    int count = 0;

    cout << "ENTER NAME: ";
    cin >> name; cout << endl;

    do
    {
        cout << "GIKI REG NO: ";
        cin >> check_usr; cout << endl;

        cout << "PASSWORD: ";
        cin >> check_pass; cout << endl;

        ifstream userFile("username.txt");
        ifstream passFile("password.txt");

        string stored_usr;
        string stored_pass;

        userFile >> stored_usr;
        passFile >> stored_pass;

        if (check_usr != stored_usr ||check_pass != stored_pass)
        {
            cout << "INVALID CREDENTIALS PLEASE TRY AGAIN" << endl;
            return false;
        }
        else
        {
            cout << "Login successful!" << endl;
            break;
            return true;
        }

        count++;
        if (count > 1)
        {
            cout << 5 - count << " Attempts remaining " << endl;
        }
    } while (count == 5);
}
