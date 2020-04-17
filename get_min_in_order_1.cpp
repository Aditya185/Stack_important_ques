#include<bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> ss;//spporting stack contains only minm element till now

void push(int a){
    s.push(a);
    if(ss.size() == 0 || ss.top()>= a){
        ss.push(a);

    }
    return;
}

int pop(){
    if(s.size() == 0){
        return -1;
    }
    int ans = s.top();
    s.pop();
    if(ss.top() == ans){
        ss.pop();
    }
    return ans;
}
int getMin(){
    if(ss.size() == 0){
        return -1;
    }
    return ss.top();
}


int main(){
    push(5);
    push(10);
    cout<<getMin()<<endl;
    pop();
    push(3);
     cout<<getMin()<<endl;
    return 0;
}