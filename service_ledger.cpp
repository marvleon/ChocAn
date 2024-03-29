#include "Service_Ledger.hpp"
using namespace std;

Service_Ledger::Service_Ledger() {
    //load();
}

void Service_Ledger::load() {
    using json = nlohmann::json;
    string file_name = "assets/service_ledger.json";
    json j;
    ifstream in(file_name);
    if (!in.is_open()) cout << "Error opening file"<<endl;
    // parse the file and store the ledger with the json object
    j = json::parse(in);
    this->ledger = j.get<unordered_map<string, vector<Service_Record>>>();

    in.close();
}

Service_Ledger::~Service_Ledger() {
    save();
}

void Service_Ledger::save() {
using json = nlohmann::json;
    string file_name = "assets/service_ledger.json";
    ofstream o(file_name);
    json j_ledger;

    //o.open(file_name);
    
    if (!o.is_open()) {
        cerr << "Could not open the file!!" << endl;
        return;
    }


    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        //json j_vec = it->second;
        j_ledger[it->first] = it->second;
    }

    // output json ledger to output
    j_ledger >> o;
    o.close();

    return;
}

std::string Service_Ledger::vec_to_string(const string& pID) {
    string out;
    out += "{";
    for (auto it = this->ledger[pID].begin(); it != this->ledger[pID].end(); it++) {
        out += it->to_string_exp();
    }
    out += "}";
    return out;
}

void Service_Ledger::new_transaction(Service_Record &record) {
    auto new_record = Service_Record(record); // copy passed in record
    string id = new_record.get_pID();
    auto check = this->ledger.find(id);

    // append record to list at the service code when collision happens
    if (in_ledger(id)) {
        ledger[id].push_back(new_record); 
        return;
    }
    
    // create a new vector and append record, then add it to the ledger
    vector<Service_Record> provider;
    provider.push_back(new_record);
    ledger.emplace(id, provider);
}

void Service_Ledger::generate_APR(Provider_Directory &provider_directory) {
    map<string, int> providers;
    string sid;
    string file_name = "docs/AccountsPayableReport.txt";
    int total_providers = 0, total_services = 0, num_consultations = 0;
    double total_fee = 0.0;
    ofstream out(file_name);

    if (!out.good()) {
        cerr << "Unable to open file!!" << endl;
        out.close();
        return;
    }

    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        sid = it->first;
        if (providers.find(sid) == providers.end()) continue;
        providers.emplace(sid, 0);
        total_providers++;
        num_consultations = 0;
        for (auto pit = ledger[sid].begin(); pit != ledger[sid].end(); pit++) {
            total_fee += provider_directory.get_fee_d(sid);
            total_services++;
            num_consultations++;
        }
        // output to file
        out << provider_directory.get_name(sid) << " (" << sid << ")\t" << "total consultations: " << to_string(num_consultations) << "," << "total fee: " << fee_output(total_fee) << endl;
    }

    out << "Total number of Providers who provided services: " << to_string(total_providers) << endl;
    out << "Total number of Services provided: " << to_string(total_services);
    out.close();
}

void Service_Ledger::generate_EFT(Provider_Directory &provider_directory) {
    map<string, int> providers;
    string file_name = "docs/EFTdata.txt";
    string sid;
    double pay_check = 0;
    ofstream out(file_name);
    
    if (!out.good()) {
        cerr << "Unable to open file!!" << endl;
        out.close();
        return;
    }

    for (auto it = ledger.begin(); it != ledger.end(); it++) {

        sid = it->first;
        if (providers.find(sid) == providers.end()) continue;
        providers.emplace(sid, 0);
        pay_check = 0;

        for (auto provider_transactions = ledger[sid].begin(); provider_transactions != ledger[sid].end(); provider_transactions++) {
            pay_check += provider_directory.get_fee_d(sid);
        }

        // output the data to the file
        out << provider_directory.get_name(sid) << " (" << sid << ")\t" << "Paycheck: " << to_string(pay_check) << endl;
    }
    out.close();
}

bool Service_Ledger::in_ledger(string id) {
    auto val = ledger.find(id);
    if (val->first == id && val != ledger.end())
        return true;
    return false;
}
