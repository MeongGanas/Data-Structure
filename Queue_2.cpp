#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Function to reverse the given queue
queue<int> rev(queue<int> q) {
    stack<int> s;
    
    // Step 1: Dequeue all elements from the queue and push them into the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    
    // Step 2: Pop all elements from the stack and enqueue them back into the queue
    // This process naturally reverses the order due to the stack's LIFO property
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    return q;
}

// Function to print the queue (for demonstration purposes)
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    
    // Adding elements based on Example 1
    // Constraints: 1 <= q.size() <= 10^3, 0 <= q[i] <= 10^5
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);
    
    cout << "Original Queue (front to back): ";
    printQueue(q);
    
    // Call the reversal function
    queue<int> reversed_q = rev(q);
    
    cout << "Reversed Queue (front to back): ";
    printQueue(reversed_q);
    
    return 0;
}