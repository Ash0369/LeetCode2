class Solution 
{
public:
    bool isSameAfterReversals(int num) 
    {
        string s=to_string(num);
        reverse(s.begin(),s.end());
        
        int num1=stoi(s);
        
        s=to_string(num1);
        
        reverse(s.begin(),s.end());
        
        num1=stoi(s);
        
        return num==num1;
    }
};
