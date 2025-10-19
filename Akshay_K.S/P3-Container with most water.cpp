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
int main() {
    Solution sol;

    // Input example: number of elements + array of heights
    int n;
    cout << "Enter number of lines: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = sol.maxArea(height);
    cout << "Maximum area: " << result << endl;

    return 0;
}
