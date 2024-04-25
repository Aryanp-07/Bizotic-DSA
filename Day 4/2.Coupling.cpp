#include <iostream>
using namespace std;

class Patient
{
    string patientName, patientAge, doa, disease;
    Information *info;
    Payment *pay;

public:
    Patient(string name, string age, string arrival, string dis, Information *info, Payment *pay)
    {
        this->patientName = name;
        this->patientAge = age;
        this->doa = arrival;
        this->disease = dis;
        this->info = info;
        this->pay = pay;
    }
};

class Information
{
};

class Payment
{
};

int main()
{

    return 0;
}