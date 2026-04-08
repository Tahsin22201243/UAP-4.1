#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> req = {98,183,37,122,14,124,65,67};
    int head = 53;
    string dir = "right";

    vector<int> left, right;
    int movement = 0;

    // split requests
    for (int r : req) {
        if (r < head) left.push_back(r);
        else if (r > head) right.push_back(r);
    }

    // sort ascending
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    cout << "Order: ";

    if (dir == "right") {
        // move right
        for (int r : right) {
            cout << r << " ";
            movement += abs(head - r);
            head = r;
        }

        // jump to smallest (left side)
        if (!left.empty()) {
            movement += abs(head - left[0]);
            head = left[0];
        }

        // continue right
        for (int r : left) {
            cout << r << " ";
            movement += abs(head - r);
            head = r;
        }

    } else {
        // move left
        for (int i = left.size() - 1; i >= 0; i--) {
            cout << left[i] << " ";
            movement += abs(head - left[i]);
            head = left[i];
        }

        // jump to largest (right side)
        if (!right.empty()) {
            movement += abs(head - right.back());
            head = right.back();
        }

        // continue left
        for (int i = right.size() - 1; i >= 0; i--) {
            cout << right[i] << " ";
            movement += abs(head - right[i]);
            head = right[i];
        }
    }

    cout << "\nTotal movement: " << movement;
}
