#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> req = {98,183,37,122,14,124,65,67};
    int head = 53, disk_size = 200;
    string dir = "left";

    vector<int> left, right;
    int movement = 0;

    // split requests
    for (int r : req) {
        if (r < head) left.push_back(r);
        else if (r > head) right.push_back(r);
    }

    // sort
    sort(left.begin(), left.end(), greater<int>());
    sort(right.begin(), right.end());

    cout << "Order: ";

    if (dir == "left") {
        // move left
        for (int r : left) {
            cout << r << " ";
            movement += abs(head - r);
            head = r;
        }

        // go to 0
        movement += head;
        head = 0;

        // then right
        for (int r : right) {
            cout << r << " ";
            movement += abs(head - r);
            head = r;
        }
    } else {
        // move right
        for (int r : right) {
            cout << r << " ";
            movement += abs(head - r);
            head = r;
        }

        // go to end
        movement += (disk_size - 1 - head);
        head = disk_size - 1;

        // then left
        for (int r : left) {
            cout << r << " ";
            movement += abs(head - r);
            head = r;
        }
    }

    cout << "\nTotal movement: " << movement;
}
