class MedianFinder {
public:

 /*
 
 add num=6,10,2,6,5 --->totalsum=29/5=5.8
       0,2,5,6,6,10

 priority queue=0,0,0,1,2,3,5,6,6,6,10
 

 2 hi condition ho sakta h
  leftside == rightside

  leftside>rightside+1  toh ham leftside se element nikal kar rightside me bhej denga

  // 1,2,3,4,5
  leftside=1,2,3 ==size=3
  rightside=4,5 == size=2+1=3

  // 1,2,3,4,5,6
  leftside=1,2,3==size=3
  rightside=4,5,6==size=3
 
 
 */
//    stack<int>st;
    //   vector<int>arr;
    priority_queue<int>leftside; // max heap
    priority_queue<int,vector<int>,greater<int>>rightside;// min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // pq.push(num);

        if(leftside.empty() || num<=leftside.top()){
            leftside.push(num);
        }else{
            rightside.push(num);
        }

        if(leftside.size()>rightside.size()+1){
            rightside.push(leftside.top());
            leftside.pop();
        }

        if(rightside.size()>leftside.size()){
            leftside.push(rightside.top());
            rightside.pop();
        }
    }
    
    double findMedian() {


        if(leftside.size()==rightside.size()){
            return (leftside.top()+rightside.top())/2.0; // even 
        }

        return leftside.top(); // odd
       

//         double sum=0;

//         vector<int>v;

//    priority_queue<int,vector<int>,greater<int>>temp=pq;

//        while(!temp.empty()){
//         v.push_back(temp.top());
//         temp.pop();
//        }


//        int n=v.size();

//         int mid=n/2;
//         double avg=0;

//        if(n%2!=0){ // odd 

//         return v[mid];
//        }else{ // even
//         double prevmid=v[mid-1];
//         double nextmid=v[mid];
        
//         double sum=prevmid+nextmid;

//          avg=sum/2;

       

//        }

//         return avg;





    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */