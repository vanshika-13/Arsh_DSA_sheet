/*There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.*/

// Approach 1 : Recursion (TLE)
// TC: O(2^n)
int helper(vector<int> &cardPoints, int l, int h, int k)
{
    if (k == 0)
        return 0;
    return max(cardPoints[l] + helper(cardPoints, l + 1, h, k - 1), cardPoints[h] + helper(cardPoints, l, h - 1, k - 1));
}

int maxScore(vector<int> &cardPoints, int k)
{
    if (k >= cardPoints.size())
    {
        int sum = 0;
        for (auto e : cardPoints)
            sum += e;
        return sum;
    }
    else
    {
        return helper(cardPoints, 0, cardPoints.size() - 1, k);
    }
}

// Approach: 2: DP.
// Key here is realizing that only 1st K and last K elements are relevant so calculating the sums from them.
// TC: O(n), SC: O(n)
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int maxScore = 0;
    vector<int> front(k + 1), rear(k + 1);
    front[0] = rear[0] = 0;

    // calculate prefix sum of the 1st k elements in front and last k elements in rear
    // arr: [1,2,3,4,5,6,1], k=3
    // front: [0,1,3,6], rear: [0,1,7,12]
    for (int i = 0; i < k; i++)
    {
        front[i + 1] = front[i] + cardPoints[i];
        rear[i + 1] = rear[i] + cardPoints[n - 1 - i];
    }

    // just add relevant prefix sums from front and rear to get the currentScore
    for (int i = 0; i <= k; i++)
    {
        int currentScore = front[i] + rear[k - i];
        maxScore = max(maxScore, currentScore);
    }
    return maxScore;
}

// Approach: 3 (Space Optimized DP)
// TC: O(k), SC: O(1)
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int front = 0, rear = 0;

    // frontScore is initialized to the sum of the first k cards in the array, and rearScore is initialized to 0.
    for (int i = 0; i < k; i++)
        front += cardPoints[i];

    int maxScore = front, currentScore;

    // Iterate backwards from i = k - 1 -> 0. At each iteration, we calculate the score by selecting i cards from the beginning
    // of the array and k - i cards from the end (currentScore). If this score is greater than maxScore, we update it.
    for (int i = k - 1; i >= 0; i--)
    {
        front -= cardPoints[i];
        rear += cardPoints[n - (k - i)];
        currentScore = front + rear;
        maxScore = max(currentScore, maxScore);
    }
    return maxScore;
}

// Approach 4: Sliding Window Approach
// 1. We must draw exactly k cards from the array in such a way that the score (sum of the cards) is maximized.
//      After drawing k cards from the array cardPoints.length - k cards will remain in the array.
// 2. Another way that we could view the problem is that our objective is to choose cards from the beginning or end of
//      array in such a way that the sum of the remaining cards is minimized.
// 3. We can use a sliding window to find the subarray of size cardPoints.length - k that has the minimal sum.
//      Subtracting this value from the total sum of all the cards will give us our answer.
// TC: O(n), SC: O(1)

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int totalScore = 0;
        int startingIndex = 0;
        int presentSubarrayScore = 0;

        for (auto e : cardPoints)
            totalScore += e;

        if (k == n)
            return totalScore;

        int minSubArrayScore = totalScore;

        for (int i = 0; i < n; i++)
        {
            presentSubarrayScore += cardPoints[i];
            int presentSubarrayLength = i - startingIndex + 1;
            // If a valid subarray (having size cardsPoints.size() - k) is possible.
            if (presentSubarrayLength == n - k)
            {
                minSubArrayScore = min(minSubArrayScore, presentSubarrayScore);
                presentSubarrayScore -= cardPoints[startingIndex++];
            }
        }
        return totalScore - minSubArrayScore;
    }
};