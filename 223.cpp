class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int lx=max(ax1,bx1);
        int rx=min(ax2,bx2);
                
        int ty=min(ay2,by2);
        int dy=max(ay1,by1);
        
        int ans=0;
        if(lx>rx || dy>ty)
        {
            
        }
        else
        {
            ans=abs(lx-rx)*abs(ty-dy);
        }
        
        int tot=0;
        tot+=(ax2-ax1)*(ay2-ay1);
        tot+=(bx2-bx1)*(by2-by1);
        
        return tot-ans;
    }
};
