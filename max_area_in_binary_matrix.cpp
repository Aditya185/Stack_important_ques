#include<bits/stdc++.h>
using  namespace std;

vector<int> nearest_smaller_right(vector<int> arr,int n){

    vector<int> v;
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(s.size() == 0){
            v.push_back(n);
           
        }
        else if (s.size() >0 && arr[i]> arr[s.top()])
        {
             v.push_back(s.top());
        }else if(s.size() >0 &&  arr[s.top()]>= arr[i]){
            while(s.size() >0 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(n);
            }else{
                v.push_back(s.top());
            }

        }
        s.push(i);
        
    }
    reverse(v.begin(),v.end());
    return v;
}

vector<int> nearest_smaller_left(vector<int> arr,int n){

    vector<int> v;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.size() == 0){
            v.push_back(-1);
           
        }
        else if (s.size() >0 && arr[i]> arr[s.top()])
        {
             v.push_back(s.top());
        }else if(s.size() >0 &&  arr[s.top()]>= arr[i]){
            while(s.size() >0 &&  arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }

        }
        s.push(i);
        
    }
  
    return v;
}

int cal_area(vector<int> left,vector<int> right,vector<int> arr){
    int n = left.size();
    vector<int> width;
    for(int i=0;i<n;i++){
         width.push_back(right[i]-left[i]-1);
    }

   

    vector<int> area;
    for(int i=0;i<n;i++){
        area.push_back(arr[i]*width[i]);
    }
    
    int maxm = INT_MIN;
    for(auto v: area){
        if(v>maxm){
            maxm = v;
        }
    }
    return maxm;
}

int MAH(vector<int> arr){
    int n  = arr.size();
    vector<int> left = nearest_smaller_left(arr,n);
    vector<int> right = nearest_smaller_right(arr,n);
     int ans = cal_area(left,right,arr);
     return ans;
}

int max_binary_matrix(vector<vector<int>> arr){
    vector<int> v;
    int m = arr[0].size();
    int n = arr.size();
    for(int j=0;j<m;j++){
        v.push_back(arr[0][j]);
    }
    int mx = MAH(v);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                v[j] = 0;
            }else{
                v[j] = arr[i][j]+v[j];
            }
           
        }
         mx = max(mx,MAH(v));
    }
    return mx;
}


int main(){
        vector<vector<int>> arr = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}}; 
       
        cout<<max_binary_matrix(arr)<<endl;
       
    return 0;
}