#include <bits\stdc++.h>


using namespace std;
void make_big(int &a){
    a += a;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    string s;
    int x;
    cin >> x;
    int cnt = 0;
    cout << "initial";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    while (x--){
    cin >> s;
    if (s == "sort"){
        sort(v.begin(), v.end());
        cnt++;
        cout << cnt << ") ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    if (s == "reverse"){
        cnt++;
        reverse(v.begin(), v.end());
        cout << cnt << ") ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    if (s == "find_max"){
        cnt++;
        cout << cnt << ") ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        cout << "max - " << *max_element(v.begin(), v.end()) << endl;
    }
    if (s == "find_min"){
        cnt++;
        cout << cnt << ") ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        cout << "min - " << *min_element(v.begin(), v.end());
    }
    if (s == "sum"){
        cnt++;
        cout << cnt << ") ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        cout << "sum - " << accumulate(v.begin(), v.end(), 0);
    }
    if (s == "kick_one")
    {
        int k;
        cin >> k;
        v.erase(v.begin() + k);
        cnt++;
        cout << cnt << ") ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    if (s == "kick_part")
    {
        int p, u;
        cin >> p >> u;
        v.erase(v.begin() + p, v.begin() + u);
        cnt++;
        cout << cnt << ") ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    if (s == "how_many")
    {
        int y;
        cin >> y;
        cnt++;
        cout << cnt << ") ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        cout << count(v.begin(), v.end(), y) << " times" << endl;
    }
    if (s == "invite_one")
    {
        int t, r;
        cin >> t >> r;
        v.insert(v.begin() + t, r);
        cnt++;
        cout << cnt << ") ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    if (s == "kick_all")
    {
        v.clear();
        cnt++;
        cout << cnt << ") ";
        cout << "ok" << endl;
    }
    if (s == "make_bigger")
    {
        for_each(v.begin(), v.end(), make_big);
        cnt++;
        cout << cnt << ") ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    }
return 0;
}