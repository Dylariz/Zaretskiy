#include <iostream>
#include <string>

using namespace std;
string act(string line)
{
    while (line[line.size() - 1] == ')' && line[0] == '(')
    {
        int k = 1;
        for (int i = 1; i < line.size() - 1; i++)
        {
            char sign = line[i];
            if (sign == '(')  k++;
            else if (sign == ')') { k--; if (k == 0) return line; }
        }
        line = line.substr(1, line.size() - 2);
    }
    return line;
}

int action(char sign)
{
    if (sign == '*' || sign == '/')
        return 1;
    else if (sign == '+' || sign == '-')
        return 0;
    else
        return -1;
}

int math(string source)
{
    source = act(source);
    int x = 0;
    int n = -1;
    for (int i = 0; i < source.size(); i++)
    {
        char ch = source[i];
        int p = action(ch);
        if (p != -1 && x == 0 && (n == -1 || p <= action(source[n]))) n = i;
        else if (ch == '(') x++;
        else if (ch == ')') x--;
    }

    if (n != -1)
    {
        int a = math(source.substr(0, n));
        int b = math(source.substr(n + 1, source.size()));
        if (source[n] == '*') return a * b;
        else if (source[n] == '/') return a / b;
        else if (source[n] == '+') return a + b;
        else if (source[n] == '-') return a - b;
    }
    return stoi(source);
}

int main()
{
    string s;
    getline(cin, s);
    cout << math(s);
    return 0;
}