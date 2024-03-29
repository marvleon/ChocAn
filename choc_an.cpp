
/*This file contains the implementation for the simulated client and ChocAn data center
    choc_an available data members are
    provider_directory provider_list;
    service_directory service_list;
    member_directory member_list;
*/

#include "choc_an.h"

//  Constructor
choc_an::choc_an()
{
}

choc_an::~choc_an()
{
}

// Load sample data from .txt files
int choc_an::load()
{
    cout << "\nLoading sample members, providers, and services...\n";
    // Load .txt file containing services, codes, and costs
    service_list.load("sample_service_list.txt");
    service_list.display();

    // Load .txt file containing sample ChocAn members
    member_list.load("sample_member_list.txt");
    member_list.display();

    // Load .txt file containing sample ChocAn providers
    provider_list.load("sample_provider_list.txt");
    provider_list.display();

    return 1;
}

// Loop through provider menu
int choc_an::provider_menu()
{
    int user_choice{0};
    do
    {
        user_choice = provider_options();
        switch (user_choice)
        {
        case 1:
            // Function prompts for member ID and checks through the member_list data member
            member_verify();
            break;
        case 2:
            // Function prompts to enter billing/service information of a serivce provided
            break;
        case 3:
            // Function prompts for service code and checks throguh the service_list data member
            service_search();
            break;
        case 4:
            // Function generates a report for the provider user, should use the ledger object?
            break;
        case 0:
            // QUIT
            break;
        default:
            break;
        }
    } while (user_choice != 0);
    return 1;
}

// Displays the provider options menu
int choc_an::provider_options()
{
    int user_choice{0};

    cout << "\n**** Provider Terminal ****";
    cout << "\nPlease select an option from the menu below:";
    cout << "\n(1) Verify member number"; // Verifies member number passed in
    cout << "\n(2) Bill a service";       // Records and logs provided service information
    cout << "\n(3) Service Directory";    // List of services, codes, and fees
    cout << "\n(4) Provider Report";      // Generates a report for a particular provider
    cout << "\n(0) QUIT";
    cout << "\nEnter here: ";

    cin >> user_choice;
    cin.ignore(100, '\n');

    while (user_choice > 4)
    {
        cout << "\nOops, thats not an option, please enter a value between 1-6 or 0 to quit";
        cout << "\nEnter here: ";
        cin >> user_choice;
        cin.ignore(100, '\n');
    }

    return user_choice;
}

// Loops through the manager menu
int choc_an::manager_menu()
{
    int user_choice{0};

    do
    {
        user_choice = manager_options();
        switch (user_choice)
        {
        case 1:
            // Function to generate a weekly summary report for accounts payable
            break;
        case 2:
            // Function to generate a specific provider report, reuse from provider menu
            break;
        case 3:
            // Function to generate a specific member report
            break;
        case 4:
            // Function to generate an EFT report incl. provider name, ID, amount to be transferred
            break;
        case 0:
            // QUIT
            break;
        default:
            break;
        }
    } while (user_choice != 0);
    return 1;
}

// Displays the manager options menu
int choc_an::manager_options()
{
    int user_choice{0};

    cout << "\n**** Manager Terminal ****";
    cout << "\nPlease select an option from the menu below:";
    cout << "\n(1) Summary Report";  // Weekly report for accounts payable
    cout << "\n(2) Provider Report"; // Find a specific provider, display their report
    cout << "\n(3) Member Report";   // Find a specific member, display their report
    cout << "\n(4) EFT Report";      // List with provider name, number, amount to be transferred.
    cout << "\n(0) QUIT";
    cout << "\nEnter here: ";

    cin >> user_choice;
    cin.ignore(100, '\n');

    while (user_choice > 4)
    {
        cout << "\nOops, thats not an option, please enter a value between 1-6 or 0 to quit";
        cout << "\nEnter here: ";
        cin >> user_choice;
        cin.ignore(100, '\n');
    }

    return user_choice;
}

// Loops through the operator menu
int choc_an::operator_menu()
{
    int user_choice{0};

    do
    {
        user_choice = operator_options();
        switch (user_choice)
        {
        case 1:
            member_list.display();
            break;
        case 2:
            member_list.sign_up(); // ADD a member
            cout << "Member added to ChocAn";
            break;
        case 3:
            member_remove(); // Function to DELETE a member
            break;
        case 4:
            member_modify();
            break;
        case 5:
            provider_list.display();
            break;
        case 6:
            provider_list.sign_up(); // ADD a provider
            cout << "\nProvider added to ChocAn" << endl;
            break;
        case 7:
            provider_remove(); // Function to DELETE a provider
            break;
        case 8:
            provider_modify(); // Function to MODIFY a member
            break;
        case 0:
            // QUIT
            break;
        default:
            break;
        }
    } while (user_choice != 0);
    return 1;
}

// Displays the operator options menu
int choc_an::operator_options()
{
    int user_choice{0};

    cout << "\n**** Operator Terminal ****";
    cout << "\nPlease select an option from the menu below:";
    cout << "\n(1) DISPLAY members";
    cout << "\n(2) ADD member";
    cout << "\n(3) DELETE member";
    cout << "\n(4) UPDATE member";
    cout << "\n------------------";
    cout << "\n(5) DISPLAY providers";
    cout << "\n(6) ADD provider";
    cout << "\n(7) DELETE provider";
    cout << "\n(8) UPDATE provider";
    cout << "\n(0) QUIT";
    cout << "\nEnter here: ";

    cin >> user_choice;
    cin.ignore(100, '\n');

    while (user_choice > 8)
    {
        cout << "\nOops, thats not an option, please enter a value between 1-6 or 0 to quit";
        cout << "\nEnter here: ";
        cin >> user_choice;
        cin.ignore(100, '\n');
    }

    return user_choice;
}

// Enter member number and verify member status.
int choc_an::member_verify()
{
    int user_input;
    int result;

    cout << "\nPlease swipe or enter the member number below\n";
    cout << "Enter here: ";
    cin >> user_input;
    cin.ignore(100, '\n');

    // Input check for 9-digit number, could use an exit key
    while (user_input > 1000000000 || user_input < 99999999)
    {
        cout << "\nOops, please enter a 9-digit number";
        cout << "\nEnter here: ";
        cin >> user_input;
        cin.ignore(100, '\n');
    }

    cout << "\nYou entered: " << user_input;

    // returns 1 for valid account, 0 for invalid accout, or the balance of a suspended account
    result = member_list.verify(user_input);

    if (result == 1)
    {
        // valid member prompt
        cout << "\nVALIDATED";
    }
    else if (result == 0)
    {
        // invalid member prompt
        cout << "\nINVALID NUMBER\n";
    }
    else
    {
        // suspended account
        int balance = result; // store balance of member
        cout << "\nMEMBER SUSPENDED: FEES OWED: $" << balance;
    }

    return 1;
}

// Enter member number and removes from member_list
int choc_an::member_remove()
{
    int user_input;
    int result;
    member to_delete;

    cout << "\nPlease swipe or enter the member number below\n";
    cout << "Enter here: ";
    cin >> user_input;
    cin.ignore(100, '\n');

    // Input check for 9-digit number, could use an exit key
    while (user_input > 1000000000 || user_input < 99999999)
    {
        cout << "\nOops, please enter a 9-digit number";
        cout << "\nEnter here: ";
        cin >> user_input;
        cin.ignore(100, '\n');
    }

    cout << "\nYou entered: " << user_input;

    result = member_list.remove(user_input, to_delete);

    if (result == 1)
    {
        // member removed
        cout << "\nMember removed";
    }
    else
        cout << "Member with id " << user_input << " not found...";

    return 1;
}

// Enter member number and modifies contents
int choc_an::member_modify()
{
    int user_input;
    int result;
    member to_delete;

    cout << "\nPlease swipe or enter the member number below\n";
    cout << "Enter here: ";
    cin >> user_input;
    cin.ignore(100, '\n');

    // Input check for 9-digit number, could use an exit key
    while (user_input > 1000000000 || user_input < 99999999)
    {
        cout << "\nOops, please enter a 9-digit number";
        cout << "\nEnter here: ";
        cin >> user_input;
        cin.ignore(100, '\n');
    }

    cout << "\nYou entered: " << user_input;

    result = member_list.modify(user_input, to_delete);

    if (result == 1)
    {
        // member modified
        cout << "\nMember modified";
    }
    else
        cout << "\nMember with id " << user_input << " not found...";

    return 1;
}

// Enter provider number and removes from provider_list
int choc_an::provider_remove()
{
    int user_input;
    int result;
    provider to_delete;

    cout << "\nPlease swipe or enter the provider number below\n";
    cout << "Enter here: ";
    cin >> user_input;
    cin.ignore(100, '\n');

    // Input check for 9-digit number, could use an exit key
    while (user_input > 1000000000 || user_input < 99999999)
    {
        cout << "\nOops, please enter a 9-digit number";
        cout << "\nEnter here: ";
        cin >> user_input;
        cin.ignore(100, '\n');
    }

    cout << "\nYou entered: " << user_input;

    result = provider_list.remove(user_input, to_delete);

    if (result == 1)
    {
        // provider removed
        cout << "\nProvider removed";
    }
    else
        cout << "\nProvider with id " << user_input << " not found...";

    return 1;
}

// Enter provider number and modifies contents
int choc_an::provider_modify()
{
    int user_input;
    int result;
    provider to_delete;

    cout << "\nPlease swipe or enter the provider number below\n";
    cout << "Enter here: ";
    cin >> user_input;
    cin.ignore(100, '\n');

    // Input check for 9-digit number, could use an exit key
    while (user_input > 1000000000 || user_input < 99999999)
    {
        cout << "\nOops, please enter a 9-digit number";
        cout << "\nEnter here: ";
        cin >> user_input;
        cin.ignore(100, '\n');
    }

    cout << "\nYou entered: " << user_input;

    result = provider_list.modify(user_input, to_delete);

    if (result == 1)
    {
        // provider modified
        cout << "\nprovider modified";
    }
    else
        cout << "\nprovider with id " << user_input << " not found...";

    return 1;
}

// Test function to enter service code, return service name, and confirm
int choc_an::service_search()
{
    int user_input{0};
    int result{0};

    cout << "\nPlease enter the six-digit service code below\n";
    cout << "\nEnter here:";
    cin >> user_input;
    cin.ignore(100, '\n');

    // Input check for 6-digit number, could use an exit key
    while (user_input > 10000000 || user_input < 99999)
    {
        cout << "\nOops, please enter a 6-digit number";
        cout << "\nEnter here: ";
        cin >> user_input;
        cin.ignore(100, '\n');
    }
    cout << "\nYou entered: " << user_input;
    // Implement input check to make sure a six-digit number was entered.
    cout << "\n---Searching Service Directory---";

    result = service_list.search(user_input);
    if (result == 0)
    {
        cout << "\nService not found...";
    }

    // Output the name of the service and prompts confirmation that its correct.
    return 1;
}