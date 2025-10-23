#include<iostream>
using namespace std;
int main(){
    int N;
    cout<<"Enter the size of array: ";
    cin>>N;
    cout<<"Enter the elements of array: ";

    int arr[N];
    for(int i = 0 ; i<N; i++)
        cin>>arr[i];
     int count_zero = 0;
        int steps = 0;
        int mul=1;
        for(int i = 0 ; i<N; i++)
        {
            if(arr[i]>0)
            {
                steps=steps+(arr[i]-1);
                mul=mul*1;
            }
            else if (arr[i]<0)
            {
                steps = steps+ (-1-arr[i]);
                mul= mul*-1;
            }
            else
            {
                steps++;
                count_zero++;
            }
            
            
        }
        if(mul==1 || count_zero>0)
                cout<<"Total no of steps= "<<steps+count_zero<<endl;
        else
            {
                steps = steps+2;
                cout<<"Total number of steps= "<<steps+count_zero-1<<endl;
            }
}