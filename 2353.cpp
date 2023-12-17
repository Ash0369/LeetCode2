class FoodRatings 
{
public:
    map<string,multiset<int>>mp;
    map<string,int>table;
    map<pair<int,string>,set<string>>hash;
    map<string,string>cus;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        int n=foods.size();
        for(int i=0;i<n;i++)
        {
            string f=foods[i];
            string c=cuisines[i];
            int r=ratings[i];
            
            mp[c].insert(r);
            table[f]=r;
            hash[{r,c}].insert(f);
            cus[f]=c;
        }
    }
    
    void changeRating(string food, int nr) 
    {
        int o=table[food];
        string c=cus[food];
        
        mp[c].erase(mp[c].find(o));
        hash[{o,c}].erase(food);
        
        mp[c].insert(nr);
        table[food]=nr;
        hash[{nr,c}].insert(food);
    }
    
    string highestRated(string cuisine) 
    {
        int val=*mp[cuisine].rbegin();
        return *hash[{val,cuisine}].begin();
    }
};
