#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map <int, int> m;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }

    map <int, int> :: iterator it;
    vector <int> v1;
    vector <int> v2;
    for(it = m.begin(); it != m.end(); it++)
    {
        if((*it).second > 1) {
            v2.push_back((*it).first);
        } else {
            v1.push_back((*it).first);
        }
    }
    
    vector <int> :: iterator it1;
    if(v1.size() == 0) {
        cout << "Zvonite mamam, u vas retake";
    } else {
        cout << "}{orishie : ";
        for(it1 = v1.begin(); it1 != v1.end(); it1++) {
            cout << *it1 << " ";
        }
    }

    cout << endl;

    vector <int> :: iterator it2;
    if(v2.size() == 0) {
        cout << "Molodcy";
    } else {
        cout << "Plo}{ie : ";
        for(it2 = v2.begin(); it2 != v2.end(); it2++) {
            cout << *it2 << " ";
        }
    }
    cout << endl;

    return 0;
}