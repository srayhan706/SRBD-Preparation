#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]) cout << "X";
        else cout << "_";

        if (i < v.size() - 1) cout << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n,0);

    for(int person=0; person<n; person++)
    {
        int bestLen = -1, bestL = 0, bestR = 0;

        int i = 0;
        while(i<n)
        {
            if(v[i]==1)
            {
                i++;
                continue;
            }

            int j=i;
            while(j<n && v[j]==0) j++;

            int len = j-i;

            if(len > bestLen)
            {
                bestLen = len;
                bestL = i;
                bestR = j-1;
            }

            i=j;
        }

        int mid = (bestL + bestR)/2;
        v[mid] = 1;

        print(v);
    }
}