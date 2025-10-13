class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int area=0;
        int left=0,right=n-1;
        while(left<right){
            int tallness = min(height[left],height[right]);
            int breadth = right-left;
            area=max(area,tallness*breadth);
            if(height[left]<=height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};
