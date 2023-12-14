#define ll long long
bool check(int index,string &curr,ll int last1,ll int last2,string &num)
{
    if(index==num.size())
    {
        if(curr=="")
        {
            return true;
        }
        return false;
    }
    //cut here
    bool res1=false;
    curr.push_back(num[index]);
    if(curr.size()<=18)
    {
        if(curr[0]=='0' && curr.size()>1)
        {
            return false;
        }
        if(last1+last2==(stoll(curr)))
        {
            string c="";
            ll int c1=stoll(curr);
            res1=check(index+1,c,c1,last1,num);
        }
    }
    bool res2=check(index+1,curr,last1,last2,num);
    curr.pop_back();
    return res1|res2;
}
class Solution 
{
public:
    bool isAdditiveNumber(string num) 
    {
        int n=num.size();
        string a="";
        for(int i=0;i<n-2;i++)
        {
            string b="";
            a.push_back(num[i]);
           
            for(int j=i+1;j<n-1;j++)
            {
                
                b.push_back(num[j]);
                ll int r=stoll(b);
                ll int t=stoll(a);
                string c="";
                if(check(j+1,c,r,t,num))
                {
                    cout<<a<<" "<<b<<endl;
                    return true;
                }
                if(num[i+1]=='0')
                {
                    break;
                }
            }
            if(a=="0")
            {
                return false;
            }
        }
        return false;
    }
};
