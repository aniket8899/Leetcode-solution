class Solution {
public:
void findfirstoccurrence(vector<int>arr,int n,int target,int &ans){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            //ans found-> may or may not be first occurrence
            //store and compute
         ans=mid;
         //kyuki first occurrence ki baat hori hai
         //toh batao left me jau first occ ka liya ya right me
         //left me jao
         e=mid-1;

        }
        if(target> arr[mid]){
            s=mid+1;
        }
        if(target<arr[mid]){
            e=mid-1;
        }
         mid=s+(e-s)/2;
    }
}

void findlastoccurrence(vector<int>arr,int n,int target,int &ans){
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            ans=mid;
            s=mid+1;
        }
        if(target>arr[mid]){
            //right me jao
            s=mid+1;
        }
        if(target<arr[mid]){
            //left me jao
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
}
    vector<int> searchRange(vector<int>& arr, int target) {
        int n=arr.size();
        int firstoccurrence=-1;
        findfirstoccurrence(arr,n,target,firstoccurrence);

        int lastoccurrence=-1;
        findlastoccurrence(arr,n,target,lastoccurrence);
        vector<int>temp(2);
        temp[0]=firstoccurrence;
        temp[1]=lastoccurrence;
        return temp;
        
    }
};