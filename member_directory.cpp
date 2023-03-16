// This file contains the implementation for the member_directory ADT

// This file contains the implementation for the member_directory ADT

#include "member_directory.h"

// constructor
member::member(void)
{
    address.street = "";
    address.city = "";
    address.state = "";
    address.zip_code = 0;
    name = "";
    status = "";
    balance = 0;
    id = 0;
}

// destrucutor
member::~member(void)
{
}

// Function to display member status, name, and id
int member::display(void)
{
    cout << "\n\t{name: " << name;
    cout << "\n\tid: " << id;
    cout << "\n\tstatus: " << status << "}";
    return 1;
}

int member::compare(int to_compare)
{
    if (to_compare != id)
        return 0;
    return 1;
}

int member::create_member(location_info set_adr, string set_name, string set_status, int set_balance, int set_id)
{
    address.street = set_adr.street;
    address.city = set_adr.city;
    address.state = set_adr.state;
    address.zip_code = set_adr.zip_code;
    name = set_name;
    status = set_status;
    balance = set_balance;
    id = set_id;
    return 1;
}

int member::get_status()
{
    if (status == "ACTIVE")
        return 1;
    return 0;
}

int member::get_balance()
{
    return balance;
}

/*******************/

// constructor
member_directory::member_directory(void)
{
}

// destructor
member_directory::~member_directory(void) {}

// wrapper function to insert a new member into the vector of members
int member_directory::insert(const member &to_add)
{
    member_list.push_back(to_add);
    return 1;
}

// loads a list of members from a .txt file, delimiter ',' comma
int member_directory::load(string file_name)
{
    member a_member;
    location_info adr;

    char a_name[WORD_SIZE];
    char a_status[WORD_SIZE];
    char a_street[WORD_SIZE];
    char a_city[WORD_SIZE];
    char a_state[WORD_SIZE];
    int a_zip_code;
    int a_balance;
    int a_id;

    ifstream file_in;
    file_in.open(file_name);

    if (file_in)
    {
        cout << "File opened\n";

        file_in >> a_id;
        file_in.ignore(100, ',');

        while (file_in && !file_in.eof())
        {
            file_in.get(a_name, WORD_SIZE, ',');
            file_in.ignore(100, ',');

            file_in.get(a_street, WORD_SIZE, ',');
            file_in.ignore(100, ',');

            file_in >> a_zip_code;
            file_in.ignore(100, ',');

            file_in.get(a_city, WORD_SIZE, ',');
            file_in.ignore(100, ',');

            file_in.get(a_state, WORD_SIZE, ',');
            file_in.ignore(100, ',');

            file_in.get(a_status, WORD_SIZE, ',');
            file_in.ignore(100, ',');

            file_in >> a_balance;
            file_in.ignore(100, '\n');

            adr.street = a_street;
            adr.city = a_city;
            adr.state = a_state;
            adr.zip_code = a_zip_code;

            a_member.create_member(adr, a_name, a_status, a_balance, a_id);
            insert(a_member);

            file_in >> a_id;
            file_in.ignore(100, ',');
        }
        file_in.close();
    }
    return 1;
}

// iterates through the vector of members and displays their information
int member_directory::display(void)
{
    for (size_t i = 0; i < member_list.size(); ++i)
    {
        member_list[i].display();
    }
    return 1;
}
int member_directory::verify(int id)
{
    for (size_t i = 0; i < member_list.size(); ++i)
    {
        if (member_list[i].compare(id))
        {
            // member found, check account status
            if (member_list[i].get_status())
            {
                // valid account status, return 1 true
                return 1;
            }
            else
            {
                // account invalid, return balance
                return member_list[i].get_balance();
            }
        }
    }
    return 0;
}
int member_directory::compare(int compareTo)
{
    for (size_t i = 0; i < member_list.size(); ++i)
    {
        if (member_list[i].compare(compareTo))
            return 1;
        return 0;
    }
    return 1;
}

// Prompts for member necessary information as if sign up process were occuring
// Generate 9-digit id automatically? To decrease chance matching id conflict..?
int member_directory::sign_up()
{
    member a_member;
    location_info adr;
    char a_name[26];
    char a_status[] = "ACTIVE";
    char a_street[26];
    char a_city[15];
    char a_state[3];
    int a_zip_code{0};
    int a_balance{0};
    int a_id{0};

    cout << "\nPlease enter the following information...";

    cout << "\nName: ";
    cin.get(a_name, 26, '\n');
    cin.ignore(100, '\n');

    cout << "9-digit ID number: ";
    cin >> a_id;
    cin.ignore(100, '\n');
    while (a_id > 1000000000 || a_id < 99999999)
    {
        cout << "\nOops, please enter a 9-digit number";
        cout << "\nEnter here: ";
        cin >> a_id;
        cin.ignore(100, '\n');
    }

    cout << "Street: ";
    cin.get(a_street, 26, '\n');
    cin.ignore(100, '\n');

    cout << "City: ";
    cin.get(a_city, 26, '\n');
    cin.ignore(100, '\n');

    cout << "State: ";
    cin.get(a_state, 3, '\n');
    cin.ignore(100, '\n');

    cout << "Zip: ";
    cin >> a_zip_code;
    cin.ignore(100, '\n');

    cout << "\nYou entered:" << a_name << endl;
    cout << a_street << endl;
    cout << a_city << endl;
    cout << a_state << endl;
    cout << a_zip_code << endl;

    adr.street = a_street;
    adr.city = a_city;
    adr.state = a_state;
    adr.zip_code = a_zip_code;

    a_member.create_member(adr, a_name, a_status, a_balance, a_id);
    insert(a_member);

    cout << "\nMember added to ChocAn" << endl;

    return 1;
}