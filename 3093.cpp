struct Node
{
    Node *links[26];
    bool flag=false;
    vector<int>points;
    bool containKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie 
{
public:
    Node *root;
    Trie() 
    {
        root=new Node();
    }
    
    void insert(string &word,int index) 
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->points.push_back(index);
        }
        node->setEnd();
    }
    
    bool search(string word) 
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containKey(word[i]))
            {
               return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) 
    {
        Node *node=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containKey(prefix[i]))
            {
               return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }

    int dfs(string &s,vector<string>&g)
    {
        Node *node=root;
        int sz=s.size();
        for(int i=0;i<s.size();i++)
        {
            if(!node->containKey(s[i]) || i==sz-1)
            {
                if(node->containKey(s[i]))
                {
                    node=node->get(s[i]);
                }
                
                if(node->points.size()==0)
                {
                    return -1;
                }
                int ans=node->points[0];
                int p=node->points.size();
                for(int i=1;i<p;i++)
                {
                    int y=node->points[i];
                    if((int)g[y].size()<g[ans].size())
                    {
                        ans=y;
                    }
                }
                if(ans==1e6)
                {
                    return -1;
                }
                return ans;
            }
            node=node->get(s[i]);
        
        }
        return -2;
    }
};
class Solution 
{
public:
    vector<int> stringIndices(vector<string>& wc, 
    vector<string>& wq) 
    {
        for(int i=0;i<wc.size();i++)
        {
            reverse(wc[i].begin(),wc[i].end());
        }
        for(int i=0;i<wq.size();i++)
        {
            reverse(wq[i].begin(),wq[i].end());
        }

        Trie trie;
        for(int i=0;i<wc.size();i++)
        {
            trie.insert(wc[i],i);
        }
        vector<int>sol;
        int a=0;
        for(int i=0;i<wc.size();i++)
        {
            if(wc[i].size()<wc[a].size())
            {
                a=i;
            }
        }
        for(int i=0;i<wq.size();i++)
        {
            string x=wq[i];
            int ans=trie.dfs(x,wc);
            cout<<ans<<endl;
            assert(ans!=-2);

            if(ans!=-1)
            {
                sol.push_back(ans);
            }
            else
            {
                sol.push_back(a);
            }
        }
        return sol;
    }
};
