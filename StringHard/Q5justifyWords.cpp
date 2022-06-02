/*Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.


Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified becase it contains only one word.*/

#include <bits/stdc++.h>
using namespace std;
/*Set currentIndex to 0
Iterate through words starting from currentIndex : Calculate the length of the line as follows;
Line length will be sum of length of words iterated + number of words iterated - 1(lets say there are 3 words,
in that case minimum spaces needed is 2)Stop iteration if the line length > maxLength
At this point we need to remove the last word since it resulted in condition(line length > maxLength).
Update the LineLength after removal of the last word in the iteration,
also the spaces will be 1 less than previous
Calculate the spaces to be inserted between each word as follows : (maxLenth - line length) /(num words - 1)
If there is any carry after above division, then we need to add one extra space after those many words.
For example Line lenth = 11, Number of words = 4, Max Length = 16
Number of spaces between words = (16 - 11) / 3 = 5 / 3 = 1 here carry is 2;
hence we need to add 1 extra space after first 2 words.If this is the last line then instead of
adding extra spaces between the left justified words, those will be added as trailing spaces after the last word
Set currentIndex = currentIndex + #words iterated;
perform step 2.*/

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int curWidth = 0;
    int curIndex = 0;    //starting index of every row's first word
    int index = 0;       //to keep a count of no of words in a row
    vector<string> justifiedText;
    // Iterate till all the words are processed
    while (words.size() - 1 >= (curIndex + index))
    {
        curWidth = 0;   //har line ki cw 0 se initialise krte hain
        // Iterate through words until all the words are processed or till max limit is exceeded
        // index holds the count of number of words
        while ((curWidth + (index - 1) <= maxWidth) && ((curIndex + index) <= words.size() - 1))
        {
            curWidth += words[curIndex + index].size();
            index++;
        }

        int spaces = 0;
        int spacePerWords = 0;
        int deltaSpaces = 0;
        int trailingSpaces = 0;
        // If max limit exceeded, then remove last word
        if (curWidth + (index - 1) > maxWidth)
        {
            curWidth -= words[curIndex + index - 1].size();
            index--;
        }
        // If there are more than 1 word to add, and we haven't exhausted all the words
        // Then space between  words  = (remaining length)/(no# of words -1)
        // delta space will be the remainder
        if (((curIndex + index - 1) < words.size() - 1) && (index > 1))
        {
            spaces = maxWidth - curWidth;
            spacePerWords = spaces / (index - 1);
            deltaSpaces = spaces % (index - 1);
        }
        // If there is only one word or its last ieration, then:
        // Space between words = 1, and remaining space will be trailing space
        else
        {
            spacePerWords = 1;
            deltaSpaces = 0;
            trailingSpaces = maxWidth - curWidth - index + 1;
        }

        // Add each word, after each word
        // Add spaces, no# of spaces -> spacePerWords
        // If there are any delta space add one space from that
        string line;
        for (int i = 0; i < index; i++)
        {
            line += words[curIndex + i];
            if (i != (index - 1))
            {
                // Some dirty logic as concatenation of strings with only spaces doesnt work
                for (int j = 0; j < spacePerWords; j++)
                    line += "~";
                if (deltaSpaces > 0)
                {
                    line += "~";
                    deltaSpaces--;
                }
            }
        }
        // Finally fill all trailing spaces
        for (int k = 0; k < trailingSpaces; k++)
            line += "~";
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '~')
            {
                line[i] = ' ';
            }
        }
        // cout<<line.size()<<endl;
        justifiedText.push_back(line);
        curIndex += index;
        index = 0;
    }
    return justifiedText;
}
int main()
{
    vector<string> s{{"What"}, {"must"}, {"be"}, {"acknowledgment"}, {"shall"}, {"be"}};
    int maxWidth = 16;
    vector<string> ans = fullJustify(s, maxWidth);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}