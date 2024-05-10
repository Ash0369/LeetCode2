class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        vector<vector<double>>vec;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double v=(1.00*arr[i])/arr[j];
                vec.push_back({v,(arr[i])*1.00,(arr[j])*1.00});
            }
        }
        sort(vec.begin(),vec.end());
        k--;
        return {(int)vec[k][1],(int)vec[k][2]};
    }
};
