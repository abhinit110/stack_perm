#include<bits/stdc++.h>
using namespace std;
bool validStackPermutation(vector<int> &ip, vector<int> &op){
	int n=ip.size();
	queue<int> input;
    for (int i=0;i<n;i++)
        input.push(ip[i]);
 
    // output queue
    queue<int> output;
    for (int i=0;i<n;i++)
        output.push(op[i]);
 
    // stack to be used for permutation
    stack <int> tempStack;
    while (!input.empty())
    {
        int ele = input.front();
        input.pop();
        if (ele == output.front())
        {
            output.pop();
            while (!tempStack.empty())
            {
                if (tempStack.top() == output.front())
                {
                    tempStack.pop();
                    output.pop();
                }
                else
                    break;
            }
        }
        else
            tempStack.push(ele);
    }
 
    // If after processing, both input queue and
    // stack are empty then the input queue is
    // permutable otherwise not.
    return (input.empty()&&tempStack.empty());
}
