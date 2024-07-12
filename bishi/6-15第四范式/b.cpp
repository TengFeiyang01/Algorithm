#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    int res = arr[0][0];
    for(int i=0; i<n; i++){ 
        vector<int> temp(n,0);
        for(int j=i; j<n; j++){ 
            int temp_max = -128, sum = temp_max; 
            for(int k=0; k<n; k++){ 
                temp[k] += arr[j][k];
                sum = max(sum+temp[k], temp[k]);
                temp_max = max(temp_max, sum);
            }
            res = max(res, temp_max);
        }
    }
    cout<<res;
    return 0;
}


