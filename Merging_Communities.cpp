#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, i, j;
    cin >> n >> q;
    char c;
    int merge_arr[n + 1]; // which array each element belongs to
    int size_count_arr[n + 1]; // the size of each array
    
    for(i = 0; i <= n; i++)
    {
        merge_arr[i] = i;
        size_count_arr[i] = 1;
    }
    
    int x, y, parent_y, input_q, temp_par;
    for(i = 0; i < q; i++)
    {
        cin >> c;
        if(c == 'M')
        {
            cin >> x >> y;
            parent_y = merge_arr[x];
            size_count_arr[parent_y] += size_count_arr[merge_arr[y]];
            temp_par = merge_arr[y];
            merge_arr[y] = parent_y;
            for(j = 0; j <= n; j++)
            {
                if(merge_arr[j] == temp_par)
                    merge_arr[j] = parent_y;
            }
        }
        else if(c == 'Q')
        {
            cin >> input_q;
            int temp = merge_arr[input_q];
            cout << size_count_arr[temp] << endl;
        }
    }
    return 0;
}
