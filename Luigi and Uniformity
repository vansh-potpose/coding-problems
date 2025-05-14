#include <iostream>
#include <vector>
#include <algorithm> // For std::gcd in C++17 or later
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Size of the array
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int g = a[0]; // Initialize gcd with the first element
        for (int i = 0; i < n; ++i) {
            g = __gcd(g, a[i]); // Calculate gcd of all elements
        }

        // Count occurrences of the gcd in the array
        int gcd_count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == g) {
                ++gcd_count;
            }
        }

        // Output the result
        cout << (n - gcd_count) << endl;
    }
    return 0;
}
