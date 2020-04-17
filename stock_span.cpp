#include<bits/stdc++.h>
using  namespace std;

vector<int> nearest_greatest_element(int arr[],int n){

    vector<int> v;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.size() == 0){
            v.push_back(-1);
           
        }
        else if (s.size() >0 && arr[i]< arr[s.top()])
        {
             v.push_back(s.top());
        }else if(s.size() >0 && arr[s.top()]<= arr[i]){
            while(s.size() >0 &&  arr[s.top()]<=arr[i]){
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
    for(int i = 0;i<n;i++){
        v[i] = i - v[i];
    }
  
    return v;
}

int main(){
     int arr[] = {100, 80, 60, 70, 60, 75, 85}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  vector<int> vec = nearest_greatest_element(arr,n);
  for(int v: vec){
      cout<<v<<" ";
  }
    return 0;
}