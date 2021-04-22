#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++) {
        string prev = phone_book[i];
        string cur = phone_book[i + 1];
        if(prev == cur.substr(0, prev.length()))
            return false;
    }
    return true;
}
