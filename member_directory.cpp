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
    cout << "\n\tstatus: " << status;
    cout << "\n\tname: " << name;
    cout << "\n\tid: " << id;
    return 1;
}

int member::compare(int to_compare)
{
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