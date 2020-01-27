#include <string>
using namespace std;

string last (string s, int n)
{
    string result=""s;
    for(int i=0; i < n; i++) result = s[s.length() - i] + result;
    return result;
}

string pad0 (string s, int n)
{
    string zeros = ""s;
    for (int i=0; i < n; i++) zeros += "0";
    return last(zeros + s, n);
}