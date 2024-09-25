#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class job
{
    public:
    int id;
    int deadline;
    int profit;
};
class compare
{
    public:
    bool operator()(job a, job b)
    {
        return a.profit > b.profit;
    }
};
class solution
{
    public:
    vector<int> Jobscheduling(job arr[],int n)
    {
        sort(arr, arr + n,compare());
        int maxdeadline = 0;
        for(int i = 0; i<n; i++)
        {
            maxdeadline = max(maxdeadline,arr[i].deadline);
        }

        int countjobs = 0;
        int totalprofit = 0;
        vector<int> slots(maxdeadline + 1, -1);

        for(int i = 0;i<n;i++)
        {
            for(int j = arr[i].deadline; j>0; j--)
            {
                if(slots[j] == -1)
                {
                    slots[j] = arr[i].id;
                    countjobs++;
                    totalprofit += arr[i].profit;
                    break;
                }
            }
        }
        return {countjobs,totalprofit};
    }
};
int main()
{
    job arr[] = {{1,4,20},{2,1,1},{3,1,40},{4,1,30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    solution sol;
    vector<int> res = sol.Jobscheduling(arr,n);
    for(auto val : res)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
