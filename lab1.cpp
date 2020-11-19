#include <iostream>
#include <string>
#include <map>
#include <memory>
using namespace std;

struct transaction
{

    string  sender;
    string  recepient;
    int summ;
    int currency_code;
    int transaction_code;
    string transaction_date;

};

int main()
{
    setlocale(LC_ALL, "Russian");

    map<string, unique_ptr<transaction>> bank;
    bank.insert(make_pair( "transaction_1"s,make_unique<transaction>(transaction{ "Четвериков", "Лыгин", 140,1,0,"11.05.2020" })));
    bank.insert(make_pair("transaction_2"s, make_unique<transaction>(transaction{ "Иванов", "Петров", 10000,1,1,"12.05.2020" })));
    bank.insert(make_pair("transaction_3"s, make_unique<transaction>(transaction{ "Васечкин", "Крылов", 30000,1,2,"12.06.2020" })));
    bank.insert(make_pair("transaction_4"s, make_unique<transaction>(transaction{ "Козлов", "Баранов", 30,1,3,"12.06.2020" })));
    bank.insert(make_pair("transaction_5"s, make_unique<transaction>(transaction{ "Ложкин", "Вилкин", 440,1,4,"14.06.2020" })));
    bank.insert(make_pair("transaction_6"s, make_unique<transaction>(transaction{ "Лыгин", "Четвериков", 140,1,5,"15.06.2020" })));
    for (auto it = bank.begin(); it != bank.end(); ++it)
    {
        cout << it->first << " : " << it->second->sender <<" "<< it->second->recepient << " " << it->second->summ << " " << it->second->currency_code << " " << it->second->transaction_code << " " << it->second->transaction_date<<endl;
    }
    return 0;
}
