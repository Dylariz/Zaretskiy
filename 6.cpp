#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ifstream inStr("input.txt");
    string source, s = "+-*/";
    stack <int> res;
    int temp = 0;
    while (inStr >> source)
    {
        if (s.find(source) != -1 && res.size() < 2)
        {
            cout << "ERROR";
            return 0;
        }

        if (source == "+"){
            temp = res.top();
            res.pop();
            temp += res.top();
            res.pop();
            res.push(temp);
        } 

        else if (source == "-"){
            int l = res.top();
            res.pop();
            temp = res.top();
            res.pop();
            res.push(temp - l);
        } 

        else if (source == "*"){
            temp = res.top();
            res.pop();
            temp *= res.top();
            res.pop();
            res.push(temp);
        } 

        else if (source == "/"){
            int l = res.top();
            res.pop();
            temp = res.top();
            res.pop();
            if (l > 0 && temp < 0) { res.push(temp / l - 1); } 
            else { res.push(temp / l); }
        } 

        else { res.push(atoi(source.c_str())); }
    }

    int k = res.size();
    if (k > 1)
    {
        cout << "ERROR";
        return 0;
    }
    for (int i = 0; i < k; i ++)
    {
        cout << res.top() << " ";
        res.pop();
    }
    inStr.close();
    return 0;
}