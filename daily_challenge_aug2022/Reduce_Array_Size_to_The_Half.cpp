class Solution {
public:
    
    static bool sortbysec(pair<int,int> &a,pair<int,int> &b){
        return a.second > b.second;    
    } 
    
    int minSetSize(vector<int>& arr){
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=0;
        int j=1;
        int count=0;
        vector<pair<int,int>> p;
        while(i<n){
            if(j<n && arr[i]!=arr[j]){
                count++;
                p.push_back({arr[i],count});
                count=-1;
            }
            if(i==n-1){
                count++;
                p.push_back({arr[i],count});
            }
            count++;
            i++;
            j++;
        }
        sort(p.begin(),p.end(),sortbysec);
        int ans=0;
        int rm=0;
        for(auto i: p){
            ans++;
            rm+=i.second;
            if(rm>=n/2)
                break;
        }
        return ans;
    }
};
