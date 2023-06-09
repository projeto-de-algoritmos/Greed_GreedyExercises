#include <bits/stdc++.h>
using namespace std;


int compare(const void* a, const void* b) {
    pair<int, int>* pa = (pair<int, int>*)a;
    pair<int, int>* pb = (pair<int, int>*)b;
    return pa->first - pb->first;
}

int main() {
    int n, k, count;
    cin >> n >> k;

    vector<pair<int, int>> v(n);

    
    for (int i = 0; i < n; i++) 
    {
        cin >> v[i].second >> v[i].first;
    }

    qsort(&v[0], n, sizeof(pair<int, int>), compare);

    count = 0;
    multiset<int> end_times;

    for (int i = 0; i < k; ++i) 
    {
        end_times.insert(0);
    }

    
    for (int i = 0; i < n; i++) 
    {    
        auto it = end_times.upper_bound(v[i].second);

        if (it == begin(end_times)) 
        {
            continue;
        }

        end_times.erase(--it);
        end_times.insert(v[i].first);

        count++;
    }
    
    cout << count << endl;

    return 0;
}
