#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010
#define INF 0x3f3f3f3f

int n, comp[MAXN], posnum[MAXN], num;
vector<int> cid[MAXN];

void dfs(int x){

    for(int i=0;i<cid[x].size();++i){

        int w= cid[x][i];

        if(!comp[w]){
            comp[w]=1;
            dfs(w);
        }
    }

    num++;
    posnum[x]=num;
}

int comp_[MAXN];
vector<int> cid_[MAXN];

void dfs_(int x){

    for(int i=0;i<cid_[x].size(); ++i){

        int w=cid_[x][i];

        if(!comp_[w]){
            comp_[w]=1;
            dfs_(w);
        }
    }
}

int main(){
    scanf("%d", &n);

    for(int i=0; i<n;++i){

        int u, v;
        scanf("%d %d", &u, &v);

        cid[u].push_back(v);
        cid_[v].push_back(u);
    }
    bool ok=true;
    comp[1]=1;
    dfs(1);
    for(int i=2;i<=n;++i){
        if(!comp[i]){
            ok=false;
            break;
        }
    }
    int m=-INF, i_=0;
    for(int i=1;i<=n;++i){
        if(posnum[i]>m){
            m=posnum[i];
            i_=i;
        }
    }

    dfs_(i_);
    for(int i=1;i<=n;++i){
        if(!comp_[i]){
            ok=false;
            break;
        }
    }
    if(ok){
        printf("S\n");
    }else{
        printf("N\n");
    }
    return 0;
}
