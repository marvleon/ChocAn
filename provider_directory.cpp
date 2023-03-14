// This file contains the implementation for the provider_directory ADT

#include "provider_directory.h"

// constructor
service::service(void)
{
    name = "";
    code = 0;
    cost = 0;
}

// destrucutor
service::~service(void)
{
}

// Function to display service name, code, and cost
int service::display(void)
{
    cout << "\n\tservice: " << name;
    cout << "\n\tcode: " << code;
    cout << "\n\tcost: $" << cost;
}

int service::compare(int to_compare)
{
}

int service::create_service(string set_name, int set_code, int set_cost)
{
    name = set_name;
    code = set_code;
    cost = set_cost;
}

/*******************/

// constructor
provider_directory::provider_directory(void)
{
}

// destructor
provider_directory::~provider_directory(void) {}

// wrapper function to insert a new service into the vector of services
int provider_directory::insert(const service &to_add)
{
    service_list.push_back(to_add);
}

// loads a list of services from a .txt file, delimiter ',' comma
int provider_directory::load(string file_name)
{
    service a_service;
    char a_name[WORD_SIZE];
    int a_code{0};
    int a_cost{0};

    cout << "Load function called\n";

    ifstream file_in;
    file_in.open(file_name);

    if (file_in)
    {
        cout << "File opened\n";
        file_in.get(a_name, WORD_SIZE, ',');
        file_in.ignore(100, ',');
        while (file_in && !file_in.eof())
        {
            file_in >> a_code;
            file_in.ignore(100, ',');

            file_in >> a_cost;
            file_in.ignore(100, '\n');

            a_service.create_service(a_name, a_code, a_cost);
            insert(a_service);
            file_in.get(a_name, WORD_SIZE, ',');
            file_in.ignore(100, ',');
        }
        file_in.close();
    }
}

// iterates through the vector of services and displays their information
int provider_directory::display(void)
{
    for (size_t i = 0; i < service_list.size(); ++i)
    {
        service_list[i].display();
    }
}