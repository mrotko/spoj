#include <iostream>
#include <sstream>
using namespace std;

bool validDate(string date)
{
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(2,2));
    int year = stoi(date.substr(4, 4));

    if(month < 1 || month > 12)
        return false;
    if(year < 1000 || year > 2200)
        return false;

    int dayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        dayInMonth[1] = 29;

    if(dayInMonth[month-1] < day || day < 1)
        return false;

    return true;
}

string decodeDate(string date)
{
    ostringstream ss;
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(2,2));
    int year = stoi(date.substr(4, 4));

    ss << day << " ";

    string monthName[12] = {"stycznia", "lutego", "marca", "kwietnia", "maja", "czerwca",
                            "lipca", "sierpnia", "wrzesnia", "pazdziernika", "listopada", "grudnia"};

    ss << monthName[month-1] << " " << year;

    return ss.str();
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    string date;
    string error_message = "niepoprawny format daty";

    cin >> n;

    while(n--)
    {
        cin >> date;

        if(date.length() != 8 || !validDate(date))
            cout << error_message;
        else
            cout << decodeDate(date);

        cout << endl;
    }
}