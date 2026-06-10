class SegmentTree{
    public:
    vector<int>segmentTree;
    bool isMinTree;
    int n;
     
     SegmentTree(vector<int>& nums,bool flag){
         n=nums.size();
        this->isMinTree=flag;
        segmentTree.resize(4*n);

        buildsegmentTree(0,0,n-1,nums);
     }

     void buildsegmentTree(int i,int l,int r,vector<int>& nums){
        if(l==r){
            segmentTree[i]=nums[l];
            return;
        }

        int mid=l+(r-l)/2;

        buildsegmentTree(2*i+1,l,mid,nums);
        
        buildsegmentTree(2*i+2,mid+1,r,nums);


        if(isMinTree){
            segmentTree[i]=min(segmentTree[2*i+1],segmentTree[2*i+2]);
        }else{
            segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);
        }

     }

     int querySegmentTree(int st,int ed,int i,int l,int r){
        // no overlap

        if(l>ed || r<st){
            return isMinTree ? INT_MAX :INT_MIN;
        }

        // complete overlap

        if(l>=st && r<=ed){
            return segmentTree[i];
        }

        int mid=l+(r-l)/2;

        int a=querySegmentTree(st,ed,2*i+1,l,mid);
        int b=querySegmentTree(st,ed,2*i+2,mid+1,r);

        if(isMinTree){
            return min(a,b);
        }
        return max(a,b);
     }

     int query(int l,int r){
        return querySegmentTree(l,r,0,0,n-1);
     }
};



class Solution {
public:
    typedef long long ll;
    ll getvalue(int l,int r,SegmentTree& minSt,SegmentTree& maxSt){
        int minele=minSt.query(l,r);
        int maxele=maxSt.query(l,r);

        return (ll)maxele-minele;
    }
    long long maxTotalValue(vector<int>& nums, int k) {

        int  n=nums.size();

        // create object 
        SegmentTree maxSt(nums,false); // false for maximum

        SegmentTree minSt(nums,true); // true for minimum

        // {value,l,r} max-heap
        priority_queue<tuple<ll,int,int>>pq;

        // step-1
        for(int l=0;l<n;l++){
            ll value=getvalue(l,n-1,minSt,maxSt);
            pq.push({value,l,n-1});
        }

        // step-2 top k element
        ll result=0;

        while(k--){
            auto[val,l,r]=pq.top();
            pq.pop();

            result+=val;

            // uska baad nextvalue push bhi karna h
            ll nextvalue=getvalue(l,r-1,minSt,maxSt);
            pq.push({nextvalue,l,r-1});
            
        }

        return result;
        
    }
};