#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file;
    string command;
    const string dep = "DEPOSIT";
    const string wdr = "WITHDRAW";
    const string bal = "BALANCE";
    const string trans = "TRANSFER";
    const string inc = "INCOME";
    const string err = "ERROR";
    string name, name2;
    int p, sum;
    map<string, int> clients;
    file.open("input.txt");

    while (file >> command) {
        if (command == dep) {
            file >> name >> sum;
            if (clients.find(name) == clients.end()) {
                clients[name] = sum;
            } else {
                clients[name] += sum;
            }
        } else if (command == wdr) {
            file >> name >> sum;
            if (clients.find(name) == clients.end()) {
                clients[name] = -sum;
            } else {
                clients[name] -= sum;
            }
        } else if (command == bal) {
            file >> name;
            if (clients.find(name) == clients.end()) {
                cout << err << '\n';
            } else {
                cout << clients[name] << '\n';
            }
        } else if (command == trans) {
            file >> name >> name2 >> sum;
            if (clients.find(name) == clients.end()) {
                clients[name] = -sum;
            } else {
                clients[name] -= sum;
            }
            if (clients.find(name2) == clients.end()) {
                clients[name2] = sum;
            } else {
                clients[name2] += sum;
            }
        } else if (command == inc) {
            file >> p;
            for (auto &cl : clients) {
                if (cl.second > 0) {
                    cl.second += cl.second * p / 100;
                }
            }
        }
    }
    file.close();
    return 0;
}