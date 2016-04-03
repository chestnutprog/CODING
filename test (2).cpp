void dfs(int v){
	if(v--)dfs(v);
}
int main(){
dfs(70000);
}
