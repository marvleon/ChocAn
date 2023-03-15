// This file contains the class interface for the provider directory class
// Standard namespace and template library vector located here

#ifndef SERVDIRECTORY_H
#define SERVDIRECTORY_H

using namespace std;
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const int WORD_SIZE{25};

// Service obj, contains data members for a service name, code, and cost
// Functions include create, display
// Functions to implement: search, compare, get/return
class service
{
public:
    service();
    ~service();
    int create_service(string set_name, int set_code, int set_cost);
    int display(void);
    int compare(int to_compare);

private:
    string name;
    int code;
    int cost;
};

// Provider Directory obj, contains a vector of services
// Functions include insert, load, display.
// Functions to implement: search, compare
class service_directory
{
public:
    service_directory();
    ~service_directory();
    int insert(const service &to_add);
    int load(string file_name);
    int display(void);

private:
    vector<service> service_list;
};

#endif