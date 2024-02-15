class Solution 
{
public:
    string categorizeBox(int length, int width, int height, int mass) 
    {
        #define ll long long
        
        ll int v=1LL*length*width*height;
        
        bool c1=false;
        if(v>=1000000000 || length>=10000 || width>=10000 || height>=10000)
        {
            c1=true;
        }
        bool c2=false;
        if(mass>=100)
        {
            c2=true;
        }
        
        if(c1==true && c2==true)
        {
            return "Both";
        }
        else if(c1)
        {
            return "Bulky";
        }
        else if(c2)
        {
            return "Heavy";
        }
        return "Neither";
        
    }
};
