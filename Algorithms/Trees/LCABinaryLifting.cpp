vector<int> gr[N];
vector<int> in(N,0), out(N,0), lvl(N, -1);
vector<vector<int>> up(N, vector<int> (19));
int t;

void dfs(int node, int par, int lv){
	lvl[node] = lv;
	in[node] = t++;
	up[node][0] = par;
	for(int i=1;i<=18;i++){
		up[node][i] = up[up[node][i-1]][i-1];
	}
	for(auto& i: gr[node]){
		if(i!=par){
			dfs(i, node, lv+1);
		}
	}
	out[node] = t++;
}

bool isAnc(int u, int v){
	return in[u]<=in[v] && out[u]>=out[v];
}

int lca(int u, int v){
	if(isAnc(u, v)) return u;
	if(isAnc(v, u)) return v;
	for(int i=18;i>=0;i--){
		if(!isAnc(up[u][i], v)){
			u = up[u][i];
		}
	}
	return up[u][0];
}

int dis(int u, int v){
	int Anc = lca(u, v);
	return abs(lvl[u] - lvl[Anc]) + abs(lvl[v] - lvl[Anc]);
}
