#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int me;//minimum element

void push(int a){
    if(s.size() == 0 ){
        s.push(a);
        me = a;

    }else{
        if(a>= me){
            s.push(a);
        }else if(a<me){
            s.push(2*a-me);//key point  storing curropt value
            me = a;
        }
    }
    return;
}

void pop(){
    if(s.size() == 0){
        return ;
    }else{
        if(s.top()>=me){
            s.pop();
        }else if(s.top()<me){
            me = 2*me - s.top();
            s.pop();
        }
    }
   
}

int top(){
    if(s.size() == 0){
        return -1;
    }else{
        if(s.top() >= me){
            return s.top();
        }else if(s.top()<me){
            return me;
        }
    }
}
int getMin(){
    if(s.size() == 0){
        return -1;
    }
    return me;
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