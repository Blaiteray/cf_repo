#include <bits/stdc++.h>
using namespace std;
int i_max=1000000000;

#define edge(a,b) edge[(a-1)*N+(b-1)]
#define cr(a,b) cr[(a-1)*N+(b-1)]

bool bfs(int edge[], int  N, int s, int t, int parent[]) { //for finding path, returns true if if path exists
	bool visited[N+1];
	for(int i=1;i<=N;i++) visited[i]=false;
	queue<int> q;
	q.push(s);
	visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 1; v <= N; v++) {
            if (visited[v] == false && edge(u,v) > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

void getS(int edge[], int  N, int s, int t, bool setS[]) { //for finding the cut set S
	bool visited[N+1];
	for(int i=1;i<=N;i++) visited[i]=false;
	queue<int> q;
	q.push(s);
	setS[s]=true;
	visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 1; v <= N; v++) {
            if (visited[v] == false && edge(u,v) > 0) {
                setS[v]=true;
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int fordFulkerson(int edge[],int N, int s, int t,int n) {
    int u, v;
    int cr[N*N]; //  residual capacity of edge (i,j) is r[i,j]
    for (u = 1; u <= N; u++)
        for (v = 1; v <= N; v++) cr(u,v)=edge(u,v);
 
    int parent[N+1]; 
 
    int max_flow = 0; // stores max flow, initially no flow

    while (bfs(cr,N, s, t, parent)) { //finds minimum res. capacity of path
        int path_flow = i_max;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, cr(u,v));
        }

        for (v = t; v != s; v = parent[v]) { //update res. cap. of edges
            u = parent[v];
            cr(u,v) -= path_flow;
            cr(v,u) += path_flow;
        }
        max_flow += path_flow; //augmenting flow
    }
    bool setS[N+1];
    for(int i=1;i<=N;i++) setS[i]=false;
    getS(cr,N,s,t,setS);
	cout<< "Vertices in set S: ";
	for(int i=1;i<=n;i++) if(setS[i]) cout<< i<<" ";
	cout<< "\nVertices in set T: ";
	for(int i=1;i<=n;i++) if(!setS[i]) cout<< i<<" ";
	cout<<"\n";
	//problem 4 done
    return max_flow;
}

int main() {
	int n; //number of vertex
	cout<< "Enter the number of vertices: ";
	cin>>n;
	int N=n; //current number of vertex
	int m=2*n+n*(n-1)/2+1;// (maximum number of possible vertex)+1 in the end
	int e[m][m]; //edge set;
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) e[i][j]=0;
	int S,T;//number of source and sink resp.
	cout<< "Enter the number of source: ";
	cin>> S;
	cout << "Enter the number of sink: ";
	cin >> T;
	int so[S], si[T]; //sourse and sink vertex;
	cout<< "enter all the source one after another: ";
	for(int i=0;i<S;i++) cin>> so[i];
		cout<< "enter all the sink one after another: ";
	for(int i=0;i<T;i++) cin>> si[i];
	int s,t;// the supersource and supersink vertex
	if(S>1) {
		s=N+1;
		N++;
		for(int i=0;i<S;i++) e[s][so[i]]=i_max;
	}
	else s=so[0];
	if(T>1) {
		t=N+1;
		N++;
		for(int i=0;i<T;i++) e[si[i]][t]=i_max;
	}
	else t=si[0];
	//problem 1 done

	int E;//number of edges
	cout<< "Enter the number of edges: ";
	cin>> E;
	for(int i=0;i<E;i++) {
		int a,b,c;
		cout << "Enter information of edge in format \"a b c\", where (a,b)=c: ";
		cin>>a>>b>>c; //(a,b) vertex, weight c
		if(e[b][a]>0) { //checking for anti parallel case
			N++;
			e[a][N]=c;
			e[N][b]=c;
		}
		else e[a][b]=c;
	}

	//problem 2 done. we got s=source, t=sink, N=number of vertex, e[vertex number][vertex number]=weight
	int edge[N*N]; // 1d array of edges;
	for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
		edge(i,j)=e[i][j];
	}
	int f=fordFulkerson(edge,N,s,t,n);
	cout<< "Max flow is: "<<f<<"\n";
	//Problem 3 done
	cout<< "Minimum cut: "<< f<<"\n"; //max-flow=min-cut 
	
	return 0;
}