#include <iostream>
#include <vector>
#include <set>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 226;

int n, ans = INF;
string s;
vector<string> t;
set<string> st;

vector<int> match(string a, string b)
{ 
    string st = b + "$" + a;
    vector<int> fail(b.length() + a.length() + 1), matches;
    fail[0] = -1;
    int q;
    for (int i = 1; i < st.length(); i++)
    {
        q = fail[i - 1];
        while (q >= 0 && st[q + 1] != st[i])
            q = fail[q];
        if (st[q + 1] == st[i])
            q++;
        fail[i] = q;

    }

    for (int i = b.length() * 2; i < st.length(); i++)
    {
        if (fail[i] == b.length() - 1)
            matches.push_back(i - b.length() * 2);
    }
    return matches;
}

void dfs(string s)
{
    if (s.length() < ans)
        ans = s.length();
    string ns;
    for (int i = 0; i < t.size(); i++)
    {
        string str = t[i];
        if (s.length() < str.length())
            continue;
        vector<int> matches = match(s, str);
        if (!matches.size())
            continue;
        int pos = matches[0];
        ns = s.substr(0, pos) + s.substr(pos + str.length(), s.length());
        if (!st.count(ns))
        {
            st.insert(ns);
            dfs(ns);
        }
    }
}

int main()
{
    ericxiao;
    while (cin >> n)
    {
        if (!n)
            return 0;
        ans = INF;
        cin >> s;
        t.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> t[i];
        }
        st = set<string>();
        dfs(s);
        st.insert(s);
        cout << ans << '\n';
    }
}
