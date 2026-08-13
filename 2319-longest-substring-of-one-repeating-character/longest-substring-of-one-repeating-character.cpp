class SegmentTree{
public:
    vector<int> tree,left,right;
    vector<char> leftch, rightch;
    int n;
    
    SegmentTree(string &s){
        n=s.size();
        tree.resize(4*n,0);
        left.resize(4*n,-1), right.resize(4*n,-1);
        leftch.resize(4*n), rightch.resize(4*n);
        
        build(s,0,n-1,0);
    }
    
    void build(string& s, int low, int high, int ind){
        if(low==high){
            tree[ind]=1;
            left[ind]=right[ind]=low;
            leftch[ind]=rightch[ind]=s[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(s,low,mid,2*ind+1); build(s,mid+1,high,2*ind+2);
        merge(ind,low,high,mid);
    }
    void merge(int ind, int low, int high, int mid){
        int leftchild=2*ind+1, rightchild=2*ind+2;
        int maxsub=max(tree[leftchild],tree[rightchild]);
        left[ind]=left[leftchild]; right[ind]=right[rightchild];
        leftch[ind]=leftch[leftchild]; rightch[ind]=rightch[rightchild];
        if(leftch[rightchild]==rightch[leftchild]){
            // left = aabbcdee, right = eeeebdfeaba
            if(left[leftchild]==mid) // left=aaaa
                left[ind]=left[rightchild];
            if(right[rightchild]==mid+1)// right=aaaa
                right[ind]=right[leftchild];
            maxsub=max(maxsub, left[rightchild]-right[leftchild]+1);
        } 
        maxsub=max(maxsub,left[ind]-low+1);
        maxsub=max(maxsub,high-right[ind]+1);
        tree[ind]=maxsub;
    }
    
    void update(int ind, int low, int high, int index, char ch){
        if(low==high){
            if(low==index)
                leftch[ind]=rightch[ind]=ch;
            return;
        }
        int mid=low+(high-low)/2;
        if(index<=mid)
            update(2*ind+1,low,mid,index,ch);
        if(index>mid)
            update(2*ind+2,mid+1,high,index,ch);
        merge(ind, low, high, mid);
    }
    
    int query(){
        return tree[0];
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s,string query, vector<int>& indices){
        SegmentTree segment(s);
        int n=s.size();
        vector<int> ans(query.size(),0);
        for(int i=0; i<query.size(); i++){
            segment.update(0,0,n-1,indices[i],query[i]);
            ans[i]=segment.query();
        }
        return ans;
    }
};