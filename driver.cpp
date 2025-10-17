#include <iostream>
#include <string>
#include "LinkedListStack.hpp"
using namespace std;

int main() {
    LinkedListStack<int> s;

    cout << boolalpha;
    cout << "empty=" << s.isEmpty() << " len=" << s.getLength() << "\n";

    try { s.peek(); } catch (const string& e) { cout << e << "\n"; }
    try { s.pop(); } catch (const string& e) { cout << e << "\n"; }

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "top=" << s.peek() << " len=" << s.getLength() << "\n";

    s.rotate(Stack<int>::RIGHT);
    cout << "after RIGHT top=" << s.peek() << " len=" << s.getLength() << "\n";

    s.rotate(Stack<int>::LEFT);
    cout << "after LEFT top=" << s.peek() << " len=" << s.getLength() << "\n";

    cout << "peek before pop=" << s.peek() << "\n";
    s.pop();
    cout << "top after pop=" << s.peek() << " len=" << s.getLength() << "\n";

    LinkedListStack<int> t(s);
    cout << "copy ctor top=" << t.peek() << " len=" << t.getLength() << "\n";
    t.push(99);
    cout << "t top after push=" << t.peek() << " len=" << t.getLength() << "\n";
    cout << "s top unchanged=" << s.peek() << " len=" << s.getLength() << "\n";

    LinkedListStack<int> u;
    u = s;
    cout << "assign u top=" << u.peek() << " len=" << u.getLength() << "\n";

    u.clear();
    cout << "u empty=" << u.isEmpty() << " len=" << u.getLength() << "\n";
    try { u.peek(); } catch (const string& e) { cout << e << "\n"; }

    return 0;
}