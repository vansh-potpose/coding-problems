#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
    vector<int> vals; // stores values
    unordered_map<int, unordered_set<int>> locs; // val -> indices in vals[]
    mt19937 rng{random_device{}()};

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool isNew = locs[val].empty();
        vals.push_back(val);
        locs[val].insert(vals.size() - 1);
        return isNew;
    }

    bool remove(int val) {
        if (locs[val].empty()) return false;

        int idxToRemove = *locs[val].begin();
        locs[val].erase(idxToRemove);

        int lastVal = vals.back();
        vals[idxToRemove] = lastVal;

        locs[lastVal].erase(vals.size() - 1);
        if (idxToRemove < vals.size() - 1)
            locs[lastVal].insert(idxToRemove);

        vals.pop_back();
        return true;
    }

    int getRandom() {
        uniform_int_distribution<> dist(0, vals.size() - 1);
        return vals[dist(rng)];
    }
};
