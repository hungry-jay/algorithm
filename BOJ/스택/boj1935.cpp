 
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<double> S;
    int n, value[26] = { 0, };
    string cal;
    
    cin >> n;
    cin >> cal;
    for(int i = 0; i < n; i++) {
        cin >> value[i];
    }
    
    for(int i = 0; i < cal.length(); i++) {
        char cur = cal[i];
        if(isupper(cur)){
            S.push((double)value[cur - 'A']);
            continue;
        }
        
        double second = S.top();
        S.pop();
        double first = S.top();
        S.pop();
        switch(cur) {
            case '+':
                S.push(first + second);
                break;
            case '-':
                S.push(first - second);
                break;
            case '*':
                S.push(first * second);
                break;
            case '/':
                S.push(first / second);
                break;
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << S.top() << endl;
    return 0;
}
