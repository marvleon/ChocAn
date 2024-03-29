#include "Service_Record.hpp"
using namespace std;

Service_Record::Service_Record() : date(), sDate(), comments(), pID(), mID(), sID() {}

Service_Record::Service_Record(const Service_Record & source) : date(source.date), sDate(source.sDate), comments(source.comments), pID(source.pID), mID(source.mID), sID(source.sID) {}

Service_Record::Service_Record(string date, string sDate, string pID, string mID, string sID, string comments) : date(date), sDate(sDate), pID(pID), mID(mID), sID(sID), comments(comments) {}

Service_Record::Service_Record(nlohmann::json j) {
    date = j.value("date", "not found");
    sDate = j.value("sDate", "not found");
    comments = j.value("comments", "not found");
    pID = j.value("pID", "not found");
    mID = j.value("mID", "not found");
    sID = j.value("sID", "not found");
}

void Service_Record::display() {
    cout << "Date: " << this->date << endl;
    cout << "Service Date: " << this->sDate << endl;
    cout << "Provider ID: " << this->pID << endl;
    cout << "Member ID: " << this->mID << endl;
    cout << "Service ID: " << this->sID << endl;
    cout << "Additional Comments: " << this->comments << endl;
    return;
}

// setters/getters
void Service_Record::set_date(std::string date) {
    this->date = date;
}

void Service_Record::set_sDate(std::string sDate) {
    this->sDate = sDate;
}

bool Service_Record::set_comments(std::string comments) {
    this->comments = comments.substr(100);
    return true;
}

bool Service_Record::set_pID(string pID) {
    if (valid_id(9, sID)) {
        this->pID = pID;
        return true;
    }
    return false;
}

bool Service_Record::set_mID(string mID) {
    if (valid_id(9, sID)) {
        this->mID = mID;
        return true;
    }
    return false;
}

bool Service_Record::set_sID(string sID) {
    if (valid_id(6, sID)) {
        this->sID = sID;
        return true;
    }
    return false;
}

std::string Service_Record::get_date() {
    return this->date;
}

std::string Service_Record::get_sDate() {
    return this->sDate;
}

std::string Service_Record::get_comments() {
    return this->comments;
}

string Service_Record::get_pID() {
    return this->pID;
}

string Service_Record::get_mID() {
    return this->mID;
}

string Service_Record::get_sID() {
    return this->sID;
}


string Service_Record::to_string_exp() {
    using json = nlohmann::json;
    std::string  s;

    //create json object
    json  j = {
            {"date",date},
            {"sDate",sDate},
            {"comments",comments},
            {"pID",pID},
            {"mID",mID},
            {"sID",sID}
    };
    s = j.dump(2); // the 2 is number of spaces for indent

    return s;
}

string Service_Record::to_string_provider() {
    string out;
    out += "Current Date: " + date + "\n";
    out += "Date Service was provided: " + sDate + "\n";
    out += "Provider ID: " + pID + "\n";
    out += "Member ID: " + mID + "\n";
    out += "Service Code: " + sID + "\n";
    return out;
}

Service_Record & Service_Record::operator = (const Service_Record &source) {
    // copy data
    this->date = source.date;
    this->sDate = source.sDate;
    this->pID = source.pID;
    this->mID = source.mID;
    this->sID = source.sID;
    return *this;
}

void Service_Record::create_Service_Record() {
    bool created = false;
    set_date(current_date_time());
    set_sDate(input_sDate());
    set_pID(input_ID(9));       
    set_mID(input_ID(9));       
    set_sID(input_ID(6));       
    input_comments();
}


string Service_Record::input_sDate() {
    string sDate;
    sDate += get_part_date(2);
    sDate += "-";
    sDate += get_part_date(2);
    sDate += "-";
    sDate += get_part_date(4);
    return sDate;
}

void Service_Record::input_comments() {
    string s;
    cout << "Enter any additional comments!" << endl;
    getline(cin, s);
    set_comments(s);
}


string current_date_time() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
 
    char buffer[128];
    strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", now);
    return buffer;
}

static string get_part_date(int size) {
    bool valid = false;
    string s;
    while (!valid) {
        getline(cin, s);
        if (s.length() != size) {
            cout << "Invalid size, please re-enter!" << endl;
            s = "";
        } 
        else 
            valid = true;
    } 
    return s;
}

static string input_ID(int size) {
    string ID;
    while (!valid_id(size, ID)) {
        getline(cin, ID);
    }
    return ID;
}

static bool valid_id(int intended_size, string s) { 
    if (s.length() != intended_size || !all_of(s.begin(), s.end(), [](unsigned char c){ return std::isdigit(c); })) { //make sure s represents a number
        cout<< "Invalid ID!" << endl;
        return false;
    }
    return true;
}
