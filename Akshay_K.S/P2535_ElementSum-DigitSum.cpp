// LeetCode 2535 – Difference between element sum and digit sum

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int element_sum=0;
        int digit_sum=0;
        for(int number : nums){
            element_sum+=number;
            int individualDigitSum=0;
            while(number>0){
                int digit=number%10;
                individualDigitSum+=digit;
                number/=10;
            }
            digit_sum+=individualDigitSum;
        }
        return abs(element_sum-digit_sum);
    }
};

int main(){
    Solution s;
    int n;
    cout<<"Enter number of Elements : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter vector Elements : "<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"The difference is : "<<s.differenceOfSum(nums);
    return 0;
}