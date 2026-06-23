#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool IsPhone(const string& s) {
    for (char c : s)
        if (!isdigit(c) && c != '+')
            return false;
    return true;
}

bool IsEmail(const string& s){
    return s.find('@') != string::npos;
}

int main() {
    string s1, s2, s3;
    
    cout <<"Введите строку 1" << endl;
    getline(cin, s1);
    cout <<"Введите строку 2" << endl;
    getline(cin, s2);
    cout <<"Введите строку 3" << endl;
    getline(cin, s3);
    string fio, phone, email;

    if (IsEmail(s1)) email = s1; else if (IsPhone(s1)) phone = s1; else fio = s1;
    if (IsEmail(s2)) email = s2; else if (IsPhone(s2)) phone = s2; else fio = s2;
    if (IsEmail(s3)) email = s3; else if (IsPhone(s3)) phone = s3; else fio = s3;

    cout << "ФИО" << "-" << fio << " почта" << "-" << email << " номер" << "-" << phone <<endl;
}