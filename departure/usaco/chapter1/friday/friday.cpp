/*
 ID: rohitpa4
 PROG: friday
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> getMonthsForYear(int year) {
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 100 == 0) {
        if (year % 400 == 0) {
            months[1] = 29;
        }
    } else if (year % 4 == 0) {
        months[1] = 29;
    }
    return months;
}

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");
        //in 1900, first weak start as Mon, Tue, Wed, Thu, Fri, Sat, Sun
    vector<int> weakDayWithFrequency = {0, 0, 0, 0, 0, 0, 0};
        // Jan 13th of 1900 was on saturday
    int dayOn13thOfMonth = 5;  // saturday, 5th index in week day
    int n;
    fin >> n;
    for (int year = 1900; year < 1900 + n; year++) {
        auto months = getMonthsForYear(year);
        for (auto daysInMonth: months) {
            weakDayWithFrequency[dayOn13thOfMonth]++;
            dayOn13thOfMonth = (dayOn13thOfMonth + daysInMonth) % 7;
        }
    }
        // output order Sat, Sun, Mon, Tue, Wed, Thu, Fri
    fout << weakDayWithFrequency[5] << " "
            << weakDayWithFrequency[6] << " "
            << weakDayWithFrequency[0] << " "
            << weakDayWithFrequency[1] << " "
            << weakDayWithFrequency[2] << " "
            << weakDayWithFrequency[3] << " "
            << weakDayWithFrequency[4] << endl;
    return 0;
}
