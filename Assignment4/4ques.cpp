#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    int freq[256] = {0};   // frequency of characters

    for (char ch : s) {
        // update frequency
        freq[ch]++;

        // add current char to queue
        q.push(ch);

        // remove repeated characters from front
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // decide output
        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "First non-repeating characters: ";
    firstNonRepeating(s);

    cin.ignore();
    cin.get();

    return 0;
}
