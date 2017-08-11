#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void getRansomNoteWords(vector<string> ransom, unordered_map<string, int> &wordRepetitions)
{
    for (auto it : ransom)
    {
        
        if (wordRepetitions.find(it) == wordRepetitions.end())
        {
            wordRepetitions.emplace(it, 1);
        }
        else
        {
            wordRepetitions.at(it) += 1; 
        }
    }
}

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    unordered_map<string, int> wordRepetitions;
    getRansomNoteWords(ransom, wordRepetitions);
    /*for (auto it : wordRepetitions)
    {
        
        
        cout << "First: " << it.first << " second: " << it.second <<"\n";
    }*/
    for (auto it : wordRepetitions)
    {
        auto pos = find(magazine.begin(), magazine.end(), it.first);
        if (pos == magazine.end())
        {
            return false;
        }
        else if (it.second > 1)
        {
            while (it.second > 1)
            {
                it.second -= 1;
                pos = find(pos +1, magazine.end(), it.first);
                if (pos == magazine.end())
                {
                    return false;
                }
            }
        }
     }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
