// This file contains the menu interface for the ChocAn terminal

#include <iostream>
#include <cstring>

using namespace std;

void welcome(void);
int menu(void);

int main()
{
    int user_choice{0};

    cout << "\n**** ChocAn Terminal Build 0.1 ****";

    do
    {
        user_choice = menu();
        switch (user_choice)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 0:

            break;
        default:
            break;
        }
    } while (user_choice != 0);

    return 0;
}

void welcome(void)
{
    char response = 'a';

    cout << "\n******** Welcome to client testing ********";

    cout << "\nWould you like to load in a file? y or n: ";
    cin >> response;
    cin.ignore(100, '\n');

    if (response == 'y')
    {
        cout << "\nPlease type in a file name below (ex: list.txt)";
        cout << "\nEnter here: ";
    }
}
// Menu options for the user
int menu()
{
    int user_choice{0};

    cout << "\nPlease select an option from the menu below:";
    cout << "\n(1) Verify member number";
    cout << "\n(2) Provider Directory";
    cout << "\n(3) Manager Report";
    cout << "\n(4) Provider Report";
    cout << "\n(5) Member Report";
    cout << "\n(6) EFT Report";
    cout << "\n(0) QUIT";
    cout << "\nEnter here: ";

    cin >> user_choice;
    cin.ignore(100, '\n');

    while (user_choice > 7)
    {
        cout << "\nOops, thats not an option, please enter a value between 1-6 or 0 to quit";
        cout << "\nEnter here: ";
        cin >> user_choice;
        cin.ignore(100, '\n');
    }

    return user_choice;
}
