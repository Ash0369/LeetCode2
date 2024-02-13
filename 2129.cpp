class Solution 
{
public:
    string capitalizeTitle(string title) 
    {
        bool r=true;
        if(title.size()==1 || title[1]==' ')
        {
            r=false;
        }
        if(title.size()==2 || title[2]==' ')
        {
            r=false;
        }
        for(int i=0;i<title.size();i++)
        {
            if(title[i]==' ')
            {
                if(i+2==title.size() || title[i+2]==' ')
                {
                    continue;
                }
                if(i+3==title.size() || title[i+3]==' ')
                {
                    continue;
                }
                r=true;
                continue;
            }
            if(r)
            {
                title[i]=toupper(title[i]);
                r=false;
            }
            else
            {
                title[i]=tolower(title[i]);
            }
            
        }
        return title;
    }
};
