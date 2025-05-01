#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    int n;
    while (cin >> n)
    {
        int action = 0, value = -1, index = 0;

        list<int> values(n);
        queue<int> queue;
        stack<int> stack;
        priority_queue<int> priorityQueue;

        bool isQueue = true, isStack = true, isPriorityQueue = true;

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &action, &value);

            if (action == 1)
            {
                values.push_back(value);
                queue.push(value);
                stack.push(value);
                priorityQueue.push(value);

                index++;
                continue;
            }
            else if (action == 2)
            {
                auto element_finder = find(values.begin(), values.end(), value);

                if (element_finder == values.end())
                {
                    isQueue = false;
                    isStack = false;
                    isPriorityQueue = false;
                    continue;
                }

                values.erase(element_finder);

                if (isQueue && !queue.empty() && queue.front() == value)
                {
                    queue.pop();
                }
                else
                {
                    isQueue = false;
                }

                if (isStack && !stack.empty() && stack.top() == value)
                {
                    stack.pop();
                }
                else
                {
                    isStack = false;
                }

                if (isPriorityQueue && !priorityQueue.empty() && priorityQueue.top() == value)
                {
                    priorityQueue.pop();
                }
                else
                {
                    isPriorityQueue = false;
                }
            }
            else
            {
                action = -1;
                break;
            }
        }

        if (action == -1)
            continue;

        int result = 0;
        string type = "";

        if (isQueue)
        {
            result++;
            type = "queue";
        }

        if (isStack)
        {
            result++;
            type = "stack";
        }

        if (isPriorityQueue)
        {
            result++;
            type = "priority queue";
        }

        if (result > 1)
        {
            printf("not sure\n");
        }
        else if (result == 0)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%s\n", type.c_str());
        }
    }

    return 0;
}