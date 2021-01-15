#include <iostream>
#include<cstring>
using namespace std;
int main() {
    int t=1;
    cin>>t;
    while(t--){
     string a,b;
     cin>>a>>b;
     int f=0;
        for(int i=0;i<20;i++){
            if(a<b)
               a=a+a;
            else if(a>b){
               b=b+b;
            }
            else{
                f=1;
                cout<<a<<endl;
                break;
            }
        }
     if(!f){
         cout<<"-1"<<endl;
     }
    // strcpy(a,a+a);
    // strcpy(b,b+b);
    //deb2(a,b);
    // a=a+a;
    // cout<<a<<" "<<b;
    }
}
