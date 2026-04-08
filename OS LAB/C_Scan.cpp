#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<int> req = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    int disk_size = 200;
    string dir = "right";

    vector<int> left, right;
    int movement = 0;

    // split requests
    for (int r : req) {
        if (r < head) left.push_back(r);
        else if (r > head) right.push_back(r);
    }

    //  boundaries
    left.push_back(0);
    right.push_back(disk_size - 1);

    // sort
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    cout << "Order: ";

    if (dir == "right") {

        // service right side
        for (int r : right) {
            cout << r << " ";
            movement += abs(head - r);
            head = r;
        }

        // jump to beginning (0)
        movement += (disk_size - 1);
        head = 0;

        // service left side
        for (int r : left) {
            cout << r << " ";
            movement += abs(head - r);
            head = r;
        }

    } else {

        // service left side (reverse)
        for (int i = (int)left.size() - 1; i >= 0; i--) {
            cout << left[i] << " ";
            movement += abs(head - left[i]);
            head = left[i];
        }

        // jump to end
        movement += (disk_size - 1);
        head = disk_size - 1;

        // service right side (reverse)
        for (int i = (int)right.size() - 1; i >= 0; i--) {
            cout << right[i] << " ";
            movement += abs(head - right[i]);
            head = right[i];
        }
    }

    cout << "\nTotal movement: " << movement << endl;

    return 0;
}
