#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x, n, a, b, sum;

    cin >> x >> n;

    vector<int> heap;

    for (int i = 0; i < n; i++) {
        cin >> a;
        heap.push_back(a);
    }

    long long result = 0;

    make_heap(heap.begin(), heap.end(), greater<int>());

    while (heap.size() > 1) {
        a = heap.front();
        pop_heap(heap.begin(), heap.end(), greater<int>());
        heap.pop_back(); 

        b = heap.front();
        pop_heap(heap.begin(), heap.end(), greater<int>());
        heap.pop_back(); 

        sum = a + b; 
        result = result + sum; 

        heap.push_back(sum); 
        push_heap(heap.begin(), heap.end(), greater<int>());
    }

    cout << result << endl; 

    return 0;

}
