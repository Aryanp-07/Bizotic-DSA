#include <iostream>
using namespace std;

class Printer
{
    string name;
    int availablePaper;

public:
    Printer(string name, int availablePaper) : name(name),
                                               availablePaper(availablePaper) {}
    void print(string document)
    {
        int reqPaper = document.length() / 10;
        if (reqPaper > availablePaper)
        {
            throw 404;                     //* number exception
            throw "Please add more paper"; //* string exception
        }

        cout << "Printing..." << document << endl;
        availablePaper -= reqPaper;
    }
};

int main()
{
    Printer myPrinter("HP", 10);
    try
    {
        myPrinter.print("Hello my name is Aryan. I am studying in 6th Semester CSE.");
        myPrinter.print("Hello my name is Aryan. I am studying in 6th Semester CSE.");
        myPrinter.print("Hello my name is Aryan. I am studying in 6th Semester CSE.");
    }
    catch (const char *textException)
    {
        cout << "Exception:" << textException << endl;
    }
    catch (int errorCode)
    {
        cout << errorCode << ": Paper not found" << endl;
    }
    catch (...)
    {
        cout << "Something unexpected happened!" << endl;
    }
    return 0;
}