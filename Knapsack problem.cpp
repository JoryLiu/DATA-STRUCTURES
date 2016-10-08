#include <iostream>
#include <deque>
using namespace std;

void packing(int t, std::deque<int> w, std::deque<int> inBag) {
    if (t == 0) {
        for (int i = 0; i < inBag.size(); i++) {
            if (i == 0) cout << inBag[0];
            else cout << " " << inBag[i];
        }
        cout << endl;
    }
    else if (t > 0 && w.size() > 0) {
        inBag.push_back(w.front());
        w.pop_front();
        packing(t - inBag.back(), w, inBag);
        inBag.pop_back();
        packing(t, w, inBag);
    }
}

int main() {
    int t, n, temp;
    deque<int> w, inBag;
    cout << "Please enter the total volume and number of items" << endl;
    cin >> t >> n;
    cout << "Please enter the weight of each item" << endl;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        w.push_back(temp);
    }
    packing(t, w, inBag);
    return 0;
}
