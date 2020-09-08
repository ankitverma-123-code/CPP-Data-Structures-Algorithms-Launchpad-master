#include<iostream>
#include<unordered_set>
using namespace std;
bool check(int a[],int n){
    unordered_set<int> s;
    int pre=0;
    for(int i=0;i<n;i++){
       pre+=a[i];
       s.insert(pre);
       if(pre=0 or s.find(pre)!=s.end())
       return 1;
    }
   return 0;
}

int main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(check(a,n))
      cout<<"Yes"<<endl;
    else
    cout<<"no"<<endl;
    
    return 0;
}