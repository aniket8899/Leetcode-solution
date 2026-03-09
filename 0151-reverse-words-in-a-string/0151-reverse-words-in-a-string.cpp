class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
    //     reverse(s.begin(),s.end());
    //   int st=0,end=0;

    //   for(int i=0;i<n;i++){
    //     while(i<n && s[i]==' '){
    //         i++;
    //     }
    //     if(i==n) break;
      
    //   while(i<n && s[i]!=' '){
    //     s[end]=s[i];
    //     end++,i++;
    //   }
    //     reverse(s.begin()+st,s.begin()+end);
    //     // add extra space
    //     s[end]=' ';
    //     end++;
    //     st=end;
      
    //   }

    //   s.resize(end-1);
    //   return s;

    int i=s.size()-1;
    string ans="";
    while(i>=0){
        //reomove extra space
        while(i>=0 && s[i]==' '){
            i--;
        }
        if(i<0) break;
        int end=i;
        // agar space na ho

        while(i>=0 && s[i]!=' '){
            i--;
        }

    string word=s.substr(i+1,end-i);

    if(!ans.empty()){
        ans+=" ";
    }

    ans+=word;

    }






return ans;




        
    }
};