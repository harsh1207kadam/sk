#include<bits/stdc++.h>
using namespace std;

void reverseStack(stack<int>&st){
    queue<int>q;
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
}

void printStack(stack<int>st)
{
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){

    stack<int>st;
    int n;
    cout<<"\nEnter the no.of elements in stack: ";
    cin>>n;
    cout<<"\nEnter the elements : \n";
    for(int i=0;i<n;i++){
        int d;cin>>d;
        st.push(d);
    }
    cout<<"\n\nInput :\t";
    printStack(st);
    cout<<endl;
    reverseStack(st);
    cout<<"\n\nOutput :\t";
    printStack(st);
    cout<<endl;

    return 0;
}