#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedin()
{
    string userName, password, un, pw;
    cout << "Enter your username: ";
    cin >> userName;
    cout << "Enter your password : ";
    cin >> password;
    ifstream read("/Users/raqueebabdul/Documents/tests/" + userName + ".txt", ios::in);
    getline(read, un);
    getline(read, pw);

    if (un == userName && pw == password)
        return true;
    return false;
}

int main()
{
    int choice;

    cout << "1: Register\n2: LogIn\nYour Choice :";
    cin >> choice;
    if (choice == 1)
    {
        string userName, password;
        cout << "Select a username : ";
        cin >> userName;
        cout << "Select a password : ";
        cin >> password;
        ofstream file;
        file.open("/Users/raqueebabdul/Documents/tests/" + userName + ".txt", ios::out);
        file << userName << endl
             << password;
        file.close();
        main();
    }
    else if (choice == 2)
    {
        bool status = isLoggedin();
        if (!status)
        {
            cout << "False Login" << endl;
        }
        else
        {
            cout << "Successfully Logged in!" << endl;
        }
    }
    return 0;
}