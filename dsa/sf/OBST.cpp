/*Given sequence k = k1<; k2<..... kn of n sorted keys, with a search probability pi for each key ki . Build the Binary search tree that has the least search cost given the access probability for each key. test your program for following example
p1 = 10, p2 = 3, p3 = 9, p4 = 2, p5 = 0, p6 = 10;
q0 = 5, q1 = 6, q2 = 4, q3= 4, q4 = 3, q5 = 8, q6 = 0 */

#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int calc(int arr[], int i, int j)
{
    int sum = 0;
    for (int k = i; k <= j; k++)
        sum += arr[k];
    return sum;
}

int obst(int key_arr[], int arr[], int n)
{
    int cost[n][n];
    for (int i = 0; i < n; i++)
        cost[i][i] = arr[i];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n - i + 1; j++)
        {
            int k = j + i - 1;
            cost[j][k] = INT_MAX;

            for (int r = j; r <= k; r++)
            {
                int c = ((r > j) ? cost[j][r - 1] : 0) + ((r < k) ? cost[r + 1][k] : 0) + calc(arr, j, k);
                if (c < cost[j][k])
                    cost[j][k] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int main()
{
    int n;
    cout << "Number of keys : ";
    cin >> n;
    
    int keys[n], prob[n];
    cout << "Value of the keys : " << endl;
    for (int i = 0; i < n; i++)
        cin >> keys[i];
    cout << " Input Search Probabilities of the keys : " << endl;
    for (int i = 0; i < n; i++)
        cin >> prob[i];
    cout << "Cost of Optimal Binary Search Tree is :: " << obst(keys, prob, n) << endl;
    return 0;
}
