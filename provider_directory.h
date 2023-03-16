
#ifndef PROVIDER_H
#define PROVIDER_H

#include "member_directory.h"

// Provider obj, contains all information pertaining to a provider of ChocAn
// Functions include create, display
// Functions to implement: search, compare, get/return

class provider
{
public:
    provider();
    ~provider();
    int create_provider(location_info set_adr, string set_name, int set_id);
    int display(void);
    int compare(int to_compare);

private:
    location_info address; // street, city, state, zip_code
    string name;           // provider first and last
    int id;                // unique 9 digit int
};

// Provider Directory obj, contains a vector of providers
// Functions include insert, load, display.
// Functions to implement: search, compare
class provider_directory
{
public:
    provider_directory();
    ~provider_directory();
    int insert(const provider &to_add);
    int load(string file_name);
    int display(void);
    int sign_up();

private:
    vector<provider> provider_list;
};

#endif