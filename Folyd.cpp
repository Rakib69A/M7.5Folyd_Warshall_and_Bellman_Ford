#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin >> n;
    ll adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j] == -1)
                adj[i][j] = INT_MAX;
            // else cout<<adj[i][j]<<" ";
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(adj[i][k] + adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    // vector<vector<ll>> v;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(adj[i][j] == INT_MAX) continue;
            if(mx < adj[i][j])
                mx = adj[i][j] ;
        }
    }
    if(mx == INT_MAX)
        cout<<0<<endl;
    else
        cout<<mx<<endl;
    return 0;
}