#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int convertTime(string time)
{
    int result;

    result = atoi(time.substr(0, time.find(":")).c_str()) * 60;
    result += atoi(time.substr(time.find(":")+1).c_str());

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    vector <string> bestRunners;
    int n, bestTime;
    string firstName, lastName, time;

    cin >> n;
    while(n--)
    {
        cin >> firstName >> lastName >> time;

        if(bestRunners.size() == 0 || convertTime(time) < bestTime)
        {
            bestTime = convertTime(time);
            bestRunners.clear();
            bestRunners.push_back(firstName + " " + lastName);
        }
        else if(convertTime(time) == bestTime)
            bestRunners.push_back(firstName + " " + lastName);
    }

    for(int i = 0; i < bestRunners.size(); i++)
        cout << bestRunners[i] << endl;
}
