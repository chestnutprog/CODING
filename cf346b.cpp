#include<iostream>
#include<algorithm>
#include<vector>
int n,m;
using namespace std;
struct person{
	string name;
	int score;	
	bool operator<(person x)const{return score>x.score;} 
};
vector<person> p[10010];
int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	cin>>n>>m;
	string t;int a,b;
	for(int i=1;i<=n;i++){
		cin>>t>>a>>b;
		p[a].push_back((person){t,b});
	}
	for(int i=1;i<=m;i++){
		stable_sort(p[i].begin(),p[i].end());
		if(p[i][0].score!=p[i][1].score||(p[i][1].score!=p[i][2].score))
			cout<<p[i][0].name<<' '<<p[i][1].name<<endl;else cout<<"?"<<endl;
	}
}
