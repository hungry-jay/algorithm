/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

// 스택문제인데 스택을 안써도 되는 문제

using namespace std;

int main()
{
    string lazer;
    cin >> lazer;
    bool flag = false;
    int count = 0, answer = 0;
    
    for(int i = 0; i < lazer.length(); i++){
        if(lazer[i] == '('){
            count++;
            flag = true;
        } else if(lazer[i] == ')'){
            count--;
            answer += flag ? count : 1;
            flag = false;
        }
    }
    
    cout << answer << endl;
    return 0;
}
