/**
 * TODO: fix me! I was really in a hurry this morning...
 */
#include <iostream>
#include <vector>

using namespace std;
/**
 * Prints a vector of integers to cout
 */
void printVec(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << "v[" << i << "] = "  << v[i] << endl;
    }
}

/**
 * Returns the sorted version of the provided vector of integers.
 * Sorting is done by means of the almighty bubble sort algorithm.
 */
vector<int> bubbleSort(vector<int> v) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] > v[i+1]) {
                swap(v[i], v[i+1]);
                sorted = false;
            }
        }
    }
    return v;
}

int main(int argc, char* argv[]) {
    // Define the vector to be sorted
    vector<int> w;
    w.push_back(2);
    w.push_back(4);
    w.push_back(1);
    w.push_back(7);
    w.push_back(5);

    // Check how it looks like
    cout << "unsorted:" << endl;
    printVec(w);

    // Get a sorted version of w
    vector<int> sorted_w = bubbleSort(w);

    // Check if it's really sorted
    cout << "sorted:" << endl;
    printVec(sorted_w);

    return 0;
}
