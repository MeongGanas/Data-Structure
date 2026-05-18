#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int>& q) {

    if (q.empty()) return;

    // remove front element
    int front = q.front();
    q.pop();

    // reverse remaining queue
    reverseQueue(q);

    // insert removed element at the rear
    q.push(front);
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);

    reverseQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}