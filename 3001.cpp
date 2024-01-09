class Solution 
{
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) 
    {
        int p=(c+d)%2;
        int p1=(e+f)%2;
        int ans=2;
       
          
            int x=c;
            int y=d;
            while(x>=1 && y>=1)
            {
                x--;
                y--;
                if(x==a && y==b)
                {
                    break;
                }
                if(x==e && y==f)
                {
                    ans=1;
                }
            }
            x=c;
            y=d;
            while(x>=1 && y<=8)
            {
                x--;
                y++;
                if(x==a && y==b)
                {
                    break;
                }
                if(x==e && y==f)
                {
                    ans=1;
                }
            }
            x=c;
            y=d;
            while(x<=8 && y<=8)
            {
                x++;
                y++;
                if(x==a && y==b)
                {
                    break;
                }
                if(x==e && y==f)
                {
                    ans=1;
                }
            }
            x=c;
            y=d;
            while(x<=8 && y>=1)
            {
                x++;
                y--;
                if(x==a && y==b)
                {
                    break;
                }
                if(x==e && y==f)
                {
                    ans=1;
                }
            }
        cout<<ans<<endl;
        x=a;
        y=b;
        
        while(x>=1 && y<=8)
        {
            y++;
            if(x==e && y==f)
            {
                ans=1;
            }
            if(x==c && y==d)
            {
                break;
            }
        }
        cout<<ans<<endl;
        
         x=a;
        y=b;
        
        while(x<=8 && y>=1)
        {
            y--;
            if(x==e && y==f)
            {
                ans=1;
            }
            if(x==c && y==d)
            {
                break;
            }
        }
        cout<<ans<<endl;
        
          x=a;
        y=b;
        
        while(x<=8 && y<=8)
        {
            x++;
            if(x==e && y==f)
            {
                ans=1;
            }
            if(x==c && y==d)
            {
                break;
            }
        }
        cout<<ans<<endl;
          x=a;
        y=b;
        
        while(x>=1 && y<=8)
        {
            x--;
            if(x==e && y==f)
            {
                ans=1;
            }
            if(x==c && y==d)
            {
                break;
            }
        }
        cout<<ans<<endl;
        return ans;
    }
};
