#include<iostream>
#include<string>
using namespace std;
string s;
int ans;
int human;
int main(){
    while(getline(cin,s)){
        if(s[0]=='+'){
            human++;
        }else{
            if(s[0]=='-'){
                human--;
            }else{
                ans+=human*(s.length()-s.find(':')-1);
            }
        }
    }
    cout<<ans;
}
