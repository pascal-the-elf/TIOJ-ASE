#include <iostream>
using namespace std;
int main()
{
    int n, s = 2;
    cin >> n;
    for (int i = 1; i < n; i++)
        s += i + 1;
    cout << s << "\n";
    return 0;
}