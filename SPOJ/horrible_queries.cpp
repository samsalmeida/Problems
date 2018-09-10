// Horrible Queries - SPOJ
// Seg with Lazy
// Complexity: O(t*c*log n)

#include <bits/stdc++.h>
     
using namespace std;
     
const int MAXN=100100;
     
typedef long long ll;
     
int t, n, c, ir[4*MAXN], il[4*MAXN];
ll tree[4*MAXN], lazy[4*MAXN];
     
void refresh(int u){
     
    if(lazy[u]==0LL) return;
     
    if(ir[u]!=il[u]){
    	lazy[2*u]+=lazy[u];
    	lazy[2*u+1]+=lazy[u];
    }
     
	tree[u]+=lazy[u]*(ir[u]-il[u]+1);
    lazy[u]=0LL;
}
     
void build(int u, int l, int r){
     
    ir[u]=r, il[u]=l;
     
	if(l==r) tree[u]=0LL;
    	
    else{
 
    	int mid=(l+r)/2;
    	build(u*2,l, mid); build(u*2+1, mid+1, r);
        tree[u]=tree[2*u] + tree[2*u+1];
    }
}
     
void up(int u, int l, int r, ll val){
    refresh(u);
    
    if(il[u]>r || ir[u]<l) return;
    
    if(il[u]>=l && ir[u]<=r){
    	
    	lazy[u]+=val;
    	refresh(u);
    	return;
    }
 
    up(2*u, l, r, val); up(2*u+1, l, r, val);
     
    tree[u]=tree[2*u] + tree[2*u+1];
}
     
ll get(int u, int l, int r){
    	
    if(il[u]>r || ir[u]<l) return 0LL;
     
	refresh(u);
    	
    if(il[u]>=l && ir[u]<=r){
		return tree[u];
    }
     
	return get(2*u, l, r) + get(2*u+1, l, r);
}
     
int main(){
    	
    scanf("%d", &t);
     
    while(t--){
    	memset(il, 0, sizeof il);
    	memset(ir, 0, sizeof ir);
		memset(lazy, 0, sizeof lazy);
    	memset(tree, 0, sizeof tree);
    		
    	scanf("%d%d", &n, &c);
    		
    	build(1, 1, n);
    		
    	for(int i=0;i<c;++i){
			int id;
    		int a, b;
    		scanf("%d%d%d", &id, &a, &b);
    
			if(!id){
    	
    			ll val;
    			scanf("%lld", &val);
    				
    			up(1, a, b, val);
    		}else{
    	
    			printf("%lld\n", get(1, a, b));
    		}
    	}
    }
     
	return 0;
} 
