#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s)
{

    unordered_map<char, int> umap;
    umap['I'] = 1;
    umap['V'] = 5;
    umap['X'] = 10;
    umap['L'] = 50;
    umap['C'] = 100;
    umap['D'] = 500;
    umap['M'] = 1000;

    int numeral = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (i + 1 < s.length())
        {
            if (umap[s[i]] < umap[s[i + 1]])
            {
                numeral += umap[s[i + 1]] - umap[s[i]];
                i++;
            }
            else
                numeral += umap[s[i]];
        }
        else
            numeral += umap[s[i]];
    }
    return numeral;
}
