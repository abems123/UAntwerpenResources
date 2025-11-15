#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long int> getFibonacci(int n) {
    if (n == 0)
        return {1};
    if (n == 1)
        return {1, 1};

    vector<unsigned long int> result = {1, 1};

    for (int i = 2; i < n; i++) {
        result.push_back(result[result.size() - 2] + result.back());
    }

    return result;
}
int main() {
    int n;
    do {
        cout << "Enter a number: ";
        cin >> n;
    } while (n < 0);

    for (auto f : getFibonacci(n))
        cout << f << endl;
}
