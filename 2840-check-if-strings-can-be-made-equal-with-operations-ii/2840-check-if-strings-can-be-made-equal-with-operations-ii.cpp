class Solution {
public:
    bool checkStrings(string s1, string s2) {
       
       vector<char>evenindex1;
       vector<char>oddindex1;

       for(int i=0;i<s1.size();i++){
        if(i%2==0){
            evenindex1.push_back(s1[i]);
        }else{
            oddindex1.push_back(s1[i]);
        }

       }
       sort(evenindex1.begin(),evenindex1.end());
       sort(oddindex1.begin(),oddindex1.end());


        vector<char>evenindex2;
       vector<char>oddindex2;

       for(int i=0;i<s2.size();i++){
        if(i%2==0){
            evenindex2.push_back(s2[i]);
        }else{
            oddindex2.push_back(s2[i]);
        }

       }
       sort(evenindex2.begin(),evenindex2.end());
       sort(oddindex2.begin(),oddindex2.end());
       

       return (evenindex1==evenindex2 && oddindex1==oddindex2);

      

      
     


      


       
    }
};