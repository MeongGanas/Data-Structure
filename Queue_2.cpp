#include <iostream>
#include <queue>
using namespace std;

void balik(queue<int>& q) {
    if (q.empty()) return;
    
    int data = q.front();
    q.pop();
    balik(q); 
    q.push(data);
}

queue<int> rev(queue<int> q) {
    balik(q);
    return q;
}

int main() {
    queue<int> q;
    
    q.push(4);
    q.push(3);
    q.push(1);

    q = rev(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}