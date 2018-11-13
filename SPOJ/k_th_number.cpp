// Persistant Segment Tree 
// Problem: Find the lowest k-th number in a range
// Build: O(n)
// K-th: O(log n)
// Update: O(log n)
// Memory: O(n + n log n )
// By Samyra Vitória

#include <bits/stdc++.h>
     
using namespace std;
     
const int maxn=1e5+10;
    
struct Node
{
    Node *l, *r;
    int v;
   	Node(){
   		l = r = NULL;
   		v=0;
   	}
};
Node *version[maxn];
     
int n, q;
vector<int> a, b;
map<int, int> m;
     
void build(Node *node, int l, int r){
     
  	if(l == r) return;
  
   	int mid=(l+r)/2;
    
   	node->l = new Node(); node->r = new Node();
    
   	build(node->l, l, mid); build(node->r, mid+1, r);
    
   	node->v=node->l->v + node->r->v;
}
    
void upd(Node *prev, Node *node, int l, int r, int pos, int v){
    
   	if( l == r ){
    
   		node->v = v;
   		return;
   	}
   	int mid=(l+r)/2;
    
   	if(pos<=mid){
    
   		node->r = prev->r;
    
   		if(node->l == NULL) node->l = new Node();
    
   		upd(prev->l, node->l, l, mid, pos, v);
   	}else{
    
  		node->l = prev->l;
    
   		if(node->r == NULL) node->r = new Node();
   
   		upd(prev->r, node->r, mid+1, r, pos, v);
   	}
     
  	node->v=node->l->v + node->r->v;
}
     
int kth(Node *prev, Node *node, int l, int r, int k){
    	
   	if(l == r) return l;

   	int mid=(l+r)/2, x = (node->l->v - prev->l->v);
   	
   	if( x >= k) return 	kth(prev->l, node->l, l, mid, k);
  	else return kth(prev->r, node->r, mid+1, r, k-x);
}
     
int main(){
    	
   	scanf("%d %d", &n, &q);
   	version[0]= new Node();
    	
   	for(int i=0;i<n;++i){
   		int t; scanf("%d", &t);
     
   		a.push_back(t);
   		b.push_back(t);
   	}
     
   	sort(a.begin(), a.end());
     
   	for(int i=0;i<n;++i){
   		m[a[i]]=i+1;
   	}

   	build(version[0], 1, n);
    	
   	for(int i=1;i<=n;++i){
    		
   		version[i]= new Node();		
   		upd(version[i-1], version[i], 1, n, m[b[i-1]], 1);
   	}
    
   	for(int i=0;i < q;++i){
    
   		int l, r, k;
   		scanf("%d%d%d", &l, &r, &k);
        
        printf("%d\n", a[kth(version[l-1], version[r], 1, n, k)-1]);
   	}
   	return 0;
}
