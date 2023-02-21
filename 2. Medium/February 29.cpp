#include<bits/stdc++.h>
using namespace std;

struct date {
    string month;
    int day, year;
};

int main() {
    int t, cs = 1;
    cin >> t;
    while(t--) {
        date first, second;
        char comma;
        cin >> first.month >> first.day >> comma >> first.year;
        cin >> second.month >> second.day >> comma >> second.year;
        if(first.month != "January" && first.month != "February") first.year++;
        if(second.month == "January" or (second.month == "February" && second.day < 29)) second.year--;
        int cnt4 = second.year/4 - (first.year-1)/4;
        int cnt100 = second.year/100 - (first.year-1)/100;
        int cnt400 = second.year/400 - (first.year-1)/400;
        int ans = cnt4 - cnt100 + cnt400;
        cout << "Case " << cs++ << ": " << ans << endl;
    }
}
