
#ifndef MEMBER_H
#define MEMBER_H

#include "service_directory.h"

// Member obj, contains all SENSITIVE information pertaining to a member of ChocAn
// Functions include create, display
// Functions to implement: search, compare, get/return

struct location_info
{
    string street;
    string city;
    string state;
    int zip_code;
};

class member
{
public:
    member();
    ~member();
    int create_member(location_info set_adr, string set_name, string set_status, int set_balance, int set_id);
    int display(void);
    int compare(int to_compare);
    int get_balance();
    int get_status();

private:
    location_info address; // street, city, state, zip_code
    string name;           // member first and last
    string status;         // active or suspended
    int balance;           // any fees owed
    int id;                // unique 9 digit int
};

// Member Directory obj, contains a vector of members
// Functions include insert, load, display.
// Functions to implement: search, compare
class member_directory
{
public:
    member_directory();
    ~member_directory();
    int insert(const member &to_add);
    int load(string file_name);
    int display(void);
    int verify(int id);
    int compare(int compareto);
    int sign_up();

private:
    vector<member> member_list;
};

#endif