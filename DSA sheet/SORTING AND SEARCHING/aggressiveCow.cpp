#include<bits/stdc++.h>
using namespace std;

//Linear Approach

bool canWePlace(vector<int> &stalls, int dist, int cows){
    int n = stalls.size();
    int cowCount = 1;   //initially 1
    int last = stalls[0];   //position of last placed cow, initiallythe first cow will placed at 0th index

    for(int i = 1; i < n; i++){
        if(stalls[i] - last >= dist){   //i.e we can place the next cow
            cowCount++;   //place next cow
            last = stalls[i];    //update the lst location of the cow
        }

        if(cowCount >= cows)    return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
   int n = stalls.size();

   //sort the stalls
   sort(stalls.begin(), stalls.end());

   int limit = stalls[n-1] -stalls[0];
   for(int i = 1; i <= limit; i++){
       if(canWePlace(stalls, i, k) == false){
           return(i-1);   //return last last index where cow is placed
       }
   }
   return limit;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

// Output:The maximum possible minimum distance is: 3.