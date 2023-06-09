#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<ll, ll>;

ll increaseWorkCount(ll workCount, ll sellIndex, ll buyIndex, ll quantity) {
    return (
        abs(sellIndex) > buyIndex 
        ? workCount + (abs(sellIndex - buyIndex) * quantity) 
        : workCount + (abs(buyIndex - sellIndex) * quantity)
    );
}

int main(void) {
    ll n, entry, workCount;
    ii swap;
    priority_queue<ii, vector<ii>, greater<ii>> sell;
    vector<ii> buy;

    cin >> n;
    while (n != 0) {
        buy.clear();
        workCount = 0;
        sell = priority_queue<ii, vector<ii>, greater<ii>>();
        
        for (ll i = 0; i < n; ++i) {
            cin >> entry;
            entry >= 0 ? buy.push_back(make_pair(i, entry)) : sell.push(make_pair(i, entry));
        }

        for (auto b : buy) {
            while (b.second > 0) {
                if (abs(b.second) >= abs(sell.top().second)) {
                    b.second += sell.top().second;
                    workCount = increaseWorkCount(workCount, sell.top().first, b.first, abs(sell.top().second));
                    sell.pop();
                } else {
                    workCount = increaseWorkCount(workCount, sell.top().first, b.first, b.second);
                    swap = sell.top();
                    sell.pop();
                    swap.second += b.second;
                    sell.push(swap);
                    b.second = 0;
                }
            }
        }

        cout << workCount << endl;

        cin >> n;
    }

    return 0;
}