class Solution 
{
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) 
    {
        sort(suits.begin(),suits.end());
        sort(ranks.begin(),ranks.end());
        
        if(suits[0]==suits.back())
        {
            return "Flush";
        }
        else if(ranks[0]==ranks[1] && ranks[1]==ranks[2])
        {
            return "Three of a Kind";
        }
        else if(ranks[1]==ranks[2] && ranks[2]==ranks[3])
        {
            return "Three of a Kind";
        }
        else if(ranks[2]==ranks[3] && ranks[3]==ranks[4])
        {
            return "Three of a Kind";
        }
        else if(ranks[0]==ranks[1])
        {
            return "Pair";
        }
        else if(ranks[2]==ranks[1])
        {
            return "Pair";
        }
        else if(ranks[2]==ranks[3])
        {
            return "Pair";
        }
        else if(ranks[3]==ranks[4])
        {
            return "Pair";
        }
        return "High Card";
    }
};
