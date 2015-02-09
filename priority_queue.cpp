// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.
#include <iostream>
#include <queue>          // std::priority_queue

using namespace std;

int main(){
    std::priority_queue<float> queue;
    queue.push(10);
    queue.push(2);
    queue.push(5);
    cout << queue.top() << endl;
    queue.pop();
    queue.push(6);
    cout << queue.top() << endl;
    queue.pop();
    cout << queue.top() << endl;
    queue.pop();
    cout << queue.top() << endl;
    queue.pop();
    
}