class Solution {
public:
    int reverse(int n)
    {
        int sum=0;
        while(n!=0)
        {
            int rem=n%10;
            sum=sum*10+rem;
            n/=10;
        }
        return sum;
    }
    int mirrorDistance(int n) {
        int temp=n;
         int ans=reverse(n);
        int diff=abs(ans-temp);

        return diff;
    }
};