#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int,int> > v)
{
    //WRITE YOUR CODE HERE
    //DON"T FORGET TO RETURN THE RESULT
    int ans,lhs,rhs;
    stack<int> st;
    for(auto &x : v)
    {
        if(x.first == 1) st.push(x.second);
        else
        {
            if(!st.empty()){
                rhs = st.top();
                st.pop();
            }
            if(!st.empty()){
               lhs = st.top();
                st.pop();
            }
            switch (x.second)
            {
            case 0:
                ans = lhs + rhs;
                break;
            case 1:
                ans = lhs - rhs;
                break;
            case 2:
                ans = lhs * rhs;
                break;
            case 3:
                ans = lhs / rhs;
                break;
            }
            st.push(ans);
        }
    }
    return st.top();
}


#endif
