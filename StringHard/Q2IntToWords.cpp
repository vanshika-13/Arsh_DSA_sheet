/*Convert a non-negative integer num to its English words representation.



Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"*/
#include <bits/stdc++.h>
using namespace std;
string ones[21] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};

string tens[10] = {"##", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string pref[4] = {"##", "Thousand", "Million", "Billion"};

const int billion = 1000000000;
const int million = 1000000;
const int thousand = 1000;

string oneDigit(int num)
{
    return (num ? ones[num] + " " : "");
}

string twoDigit(int num)
{
    if (num == 0)
        return "";
    if (num <= 20)
        return ones[num] + " ";
    else
        return tens[num / 10] + " " + (num % 10 ? ones[num % 10] + " " : "");
}

string threeDigit(int num)
{
    if (num == 0)
        return "";
    if (num / 10 == 0)
        return oneDigit(num);
    if (num / 100 == 0)
        return twoDigit(num);

    return ones[num / 100] + " Hundred " + twoDigit(num % 100);
}

string convert(int num)
{
    if (num == 0)
        return "";
    if (num / billion)
        return threeDigit(num / billion) + "Billion " + convert(num % billion);
    if (num / million)
        return threeDigit(num / million) + "Million " + convert(num % million);
    if (num / thousand)
        return threeDigit(num / thousand) + "Thousand " + convert(num % thousand);
    return threeDigit(num);
}
string numberToWords(int num)
{
    if (num == 0)
        return "Zero";
    string ans = convert(num);
    ans.pop_back();
    return ans;
}

int main()
{
    int n = 123454;
    cout << numberToWords(n);
    return 0;
}