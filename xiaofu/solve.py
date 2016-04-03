import networkx as nx
G = nx.Graph()
ass = open('input.txt','r')
t = ass.readline().split()
n=int(t[0])
m=int(t[1])
G.add_nodes_from(range(1,n+m+1))
for k in range(1,n+1):
	t = ass.readline().split()
	G.add_weighted_edges_from([(k,j+n+1,int(t[j])) for j in range(0,m)])
matched = nx.algorithms.matching.max_weight_matching(G)
ans = 0
for k in range(1,n+1):
	ans += G.edge[k][matched[k]]['weight']
pss = open('output.txt','w')
pss.write(str(ans))
pss.close()
ass.close()