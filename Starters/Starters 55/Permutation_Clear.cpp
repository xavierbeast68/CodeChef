/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t;cin>>t;
    while(t--)
    {
        int k,n;cin>>n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        cin>>k;
        int b[k];
        for (int i = 0; i < k; i++)
        {
            cin>>b[i];
        }
        int c=0;
        for (int j = c; j < k; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if(a[i]==b[j])
                {
                    a[i]=0;
                    c++;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(a[i]!=0)
            {
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t;cin>>t;
    while(t--)
    {
        int k,n;cin>>n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        cin>>k;
        int b[k];
        for (int i = 0; i < k; i++)
        {
            cin>>b[i];
        }
        int c=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; c<k,j < k; j++)
            {
                if(a[i]==b[j])
                {
                    c++;
                    goto loopstart;
                }
            }
            cout<<a[i]<<" ";
            loopstart:
            cout<<"";
        }
        cout<<endl;
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> n;
        vector<int> a(n + 1);
        int arr[n + 1];
        for (int i = 1; i < n + 1; i++)
        {
            int x;
            cin >> x;
            a[x] = x;
            arr[i] = x;
        }

        cin >> k;
        vector <int> b(n+1);
        for (int i = 1; i < k + 1; i++)
        {
            int x;
            cin >> x;
            b[x] = x;
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (b[i] == a[i])
            {
                a[i] = 0;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (a[arr[i]] != 0)
            {
                cout << arr[i] << " ";
            }
        }

        cout << endl;
    }
}