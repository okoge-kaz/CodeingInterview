#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const int inf = (1 << 30);
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
using lll = __int128_t;

pair<int, string> get_number(string s) {
    string number, str;
    for(int i=0; i<s.size(); i++) {
        if(isdigit(s[i])) {
            number += s[i];
        }else if(s[i] == ':') {
            continue;
        }
        else {
            str += s[i];
        }
    }
    return make_pair(stoi(number), str);
}

vector<string> split(string s) {
    vector<string> res;
    string str;
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == ' ') {
            res.push_back(str);
            str = "";
        } else {
            str += s[i];
        }
    }
    res.push_back(str);
    return res;
}
int main() {
    map<int, string> mapping;
    int m;

    string line;
    getline(cin, line);
    vector<string> splited = split(line);
    for (auto s : splited) {
        pair<int, string> p = get_number(s);
        if (p.second == "") {
            m = p.first;
            continue;
        }
        mapping[p.first] = p.second;
    }

    string ans;
    for (auto [k, v] : mapping) {
        if (m % k == 0) {
            ans += v;
        }
    }
    if(ans == ""){ cout << m << endl; }
    cout << ans << endl;
    return 0;
}