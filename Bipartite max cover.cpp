#include <iostream>
#define M 6
#define N 6
using namespace std;

bool bipartiteMatch(bool bipartiteGraph[][N],int u, bool visited[], int assign[],int m,int n) {
   for (int v = 0; v < n; v++) {
      if (bipartiteGraph[u][v] && !visited[v]) {
         visited[v] = true;
         if (assign[v] < 0 || bipartiteMatch(bipartiteGraph,assign[v], visited, assign,m,n)) {
            assign[v] = u;
            return true;
         }
      }
   }
   return false;
}

int maxMatch(bool bipartiteGraph[][N],int m,int n) {
   int assign[N];
   for(int i = 0; i<n; i++)
      assign[i] = -1;
   int jobCount = 0;

   for (int u = 0; u < m; u++) {
      bool visited[N];
      for(int i = 0; i<n; i++)
         visited[i] = false;
      if (bipartiteMatch(bipartiteGraph,u, visited, assign,m,n))
         jobCount++;
   }
   return jobCount;
}

int main() {
     int m,n;
    cout<<"Enter the no of elements in set A:\n";
    cin>>m;
    cout<<"Enter the no of elements in set B:\n";
    cin>>n;
    bool bipartiteGraph[M][N];
    cout<<"Enter which element of set A has been matched to which elements in set B:\n";
    for(int i=0;i<m;i++)
     for(int j=0;j<n;j++)
        cin>>bipartiteGraph[i][j];
    int z=maxMatch(bipartiteGraph,m,n);
   cout << "\nMaximum number of matchings: " << z<<endl;
}
