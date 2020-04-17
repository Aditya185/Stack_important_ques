#include<bits/stdc++.h>
using  namespace std;

vector<int> nearest_greatest_element(int arr[],int n){

    vector<int> v;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.size() == 0){
            v.push_back(-1);
           
        }
        else if (s.size() >0 && arr[i]> s.top())
        {
             v.push_back(s.top());
        }else if(s.size() >0 &&  s.top()>= arr[i]){
            while(s.size() >0 &&  s.top()>=arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }

        }
        s.push(arr[i]);
        
    }
  
    return v;
}

int main(){
     int arr[] = {-1,1,2,7,10}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  vector<int> vec = nearest_greatest_element(arr,n);
  for(int v: vec){
      cout<<v<<" ";
  }
    return 0;
}