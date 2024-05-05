bool isvowel(char c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}
class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3){
            return false;
        }
        bool a=true;
        bool b=true;
        bool c=true;
        bool d=false;
        bool e=false;
        
        for(auto x:word)
        {
            if(int(x)>=48 && int(x)<=57)
            {
                continue;
            }
            else if(int(x)>=65 && int(x)<=90)
            {
                
            }
            else if(int(x)>=97 && int(x)<=122)
            {
                
            }
            else{
                a=false;
            }
            if(isvowel(x))
            {
                d=true;
            }
            else
            {
                e=true;
            }
        }
        return (a&b)&c&d&e;
    }
};
