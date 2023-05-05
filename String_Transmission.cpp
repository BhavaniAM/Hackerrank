#include <bits/stdc++.h>
using namespace std;

const long long int modu = 1000000007;

int is_periodic(long long int n, string check_s)
{
    int i, j;
    long long int num_parts, num_eq = 0;
    vector<long long int> fac;
    if(n == 1)
        return 0;
    if(n == 2)
    {
        if(check_s[0] == check_s[1])
            return 1;
        else
            return 0;
    }
    for(i = 1; i < n; i++)
    {
        if((n % i) == 0)
            fac.push_back(i);
    }
    if(fac.size() == 2)
    {
        if(fac[0] == 1 && fac[1] == n)
            return 0;
    }
    for(i = 0; i < (int)fac.size(); i++)
    {
        num_parts = n / fac[i];
        j = fac[i];
        while(j < n)
        {
            if(check_s.substr(0, fac[i]) == check_s.substr(j, fac[i]))
                num_eq++;
            else
                break;
            j = j + fac[i];
        }
        if((num_eq + 1) == num_parts)
            return 1;
        num_eq = 0;
    }
    return 0;
}

void pos_flip(string arr, long long int n, long long int r, long long int index, long long int i, long long int pos[], vector<string>& v)
{
    string temp_s = arr;
    if (index == r) 
    {
        for (int j = 0; j < r; j++)
            temp_s[pos[j]] = (temp_s[pos[j]] == '1') ? '0' : '1';
        if(std::count(v.begin(), v.end(), temp_s) == 0)
        {
            if(!is_periodic(n, temp_s))
                v.push_back(temp_s);
        }
        return;
    }
    if (i >= n)
        return;
        
    pos[index] = i;
    pos_flip(arr, n, r, index + 1, i + 1, pos, v);
    pos_flip(arr, n, r, index, i + 1, pos, v);
}

void stringTransmission(long long int n, long long int k, string s, vector<vector<long long int>>& store_vals) 
{
    int i, j, iter;
    long long int val = 1000, result;
    vector<string> v;
    
    for(i = 0; i < val; i++)
    {
        vector <long long int> store_vals_row;
        for(j = 0; j < val; j++)
            store_vals_row.push_back(-1);
        store_vals.push_back(store_vals_row);
    }
           
    if(k == 0)
    {
        if(!is_periodic(n, s))
        {
            v.push_back(s);
            result = 1;
        }
        else
            result = 0;
    }
    else
    {
        for(iter = 0; iter <= k; iter++)
        {
            long long int pos[iter];
            pos_flip(s, n, iter, 0, 0, pos, v);
        }
        result = v.size() % modu;
        store_vals[n][k] = v.size();
    }
    cout << result << endl;
}

int main()
{
    int n, k, t;
    string s;
    vector<vector <long long int>> store_vals;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> k;
        cin >> s;
        stringTransmission(n, k, s, store_vals);
    }
    return 0;
}
