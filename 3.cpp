#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    string source;
    ifstream instr("input.txt");
    if (instr.is_open())
    {
        while (getline(instr, source))
        {
            int max = 1, size = 1;
            char ch = source[0];
            for (int i = 1; i < source.size(); i++) {

                if (source[i - 1] == source[i]) {
                    size++;
                    if (size > max) { max = size; ch = source[i]; }
                }

                else { size = 1; }
            }
            cout << ch << " " << max;
        }
    }
    instr.close();
}
