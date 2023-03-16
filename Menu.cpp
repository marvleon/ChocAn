// This file contains the simulated menu for the testing the ChocAn terminal

#include "choc_an.h"

int primary_menu(choc_an);
int options(void);

int main()
{
    // service_directory service_list; // obj containing a vector of service objects
    // member_directory member_list;    // obj containing a vector of member objects
    // provider_directory provider_list; // obj containing a vector of provider objects
    choc_an client_test; // data members are class objects for providers, members, and services
                         // should also include service ledger and report generator
    primary_menu(client_test);

    return 0;
}
int primary_menu(choc_an client_test)
{
    int user_choice{0};

    do
    {
        user_choice = options();
        switch (user_choice)
        {
        case 1: // Provider Terminal
            client_test.provider_menu();
            break;
        case 2: // Manager Terminal
            client_test.manager_menu();
            break;
        case 3: // Operater Terminal
            client_test.operator_menu();
        default:
            break;
        }
    } while (user_choice != 0);
    return 1;
}

int options(void)
{
    int user_choice{0};

    cout << "\n**** ChocAn Terminal Build ****";
    cout << "\nPlease select an option from menu below:";
    cout << "\n\t(1) Provider Terminal";
    cout << "\n\t(2) Manager Terminal";
    cout << "\n\t(3) Operator Terminal";
    cout << "\n\t(0) QUIT";
    cout << "\nEnter here: ";

    cin >> user_choice;
    cin.ignore(100, '\n');

    while (user_choice > 3)
    {
        cout << "\nOops, thats not an option, please enter a value between 1-2 or 0 to quit";
        cout << "\nEnter here: ";
        cin >> user_choice;
        cin.ignore(100, '\n');
    }

    return user_choice;
}
