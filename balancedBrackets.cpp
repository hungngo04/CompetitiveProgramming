//
//  main.cpp
//  leetcode
//
//  Created by Tien Hung on 22/02/2022.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int height[100];
stack<int> S;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> height[i];
    
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        while(!S.empty() && height[S.top()] < height[i]){
            int pop_height = height[S.top()];
            S.pop();
            
            if(S.empty())
                break;
            
            int distance = i - S.top() - 1;
            int min_height = min(height[S.top()], height[i]) - pop_height;
            
            ans += distance * min_height;
        }
        S.push(i);
    }
    
    cout << ans << endl;
}
