#include <iostream>
#include<cstring>
using namespace std;
int main() {
    int t=1;
    cin>>t;
    while(t--){
     string a,b;
     cin>>a>>b;
     string A=a,B=b;
     int f=0;
        for(int i=0;i<20;i++){
            if(A<B)
               A=A+a;
            else if(A>B){
               B=B+b;
            }
            else{
                f=1;
                cout<<A<<endl;
                break;
            }
        }
     if(!f){
         cout<<"-1"<<endl;
     }
    
    }
}
