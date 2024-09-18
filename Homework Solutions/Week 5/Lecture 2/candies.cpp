// Author: Ali Emre Kaya
// Question link: https://www.hackerrank.com/challenges/candies/problem

// Time complexity: O(n)
// Space complexity = O(n)

/*
Approach:
1. Start by assigning 1 candy to each student.
2. Traverse the ratings from left to right. 
   If a student has a higher rating than the previous one, 
   give them one more candy than the previous student.
3. Traverse the ratings from right to left. 
   If a student has a higher rating than the next one, 
   ensure they have more candies than the next student by updating the count if necessary.
4. Sum up all the candies to get the total number of candies required.
*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int> arr) {
    // everyone take at least 1 candy
    vector<int> candies_counter(n, 1);

    // left to right
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i - 1]){
            candies_counter[i] = candies_counter[i - 1] + 1;
        }
    }

    // right to left
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] > arr[i + 1]){
            candies_counter[i] = max(candies_counter[i], candies_counter[i + 1] + 1);
        }
    }

    long total_candies = 0;
    for(int i = 0; i < n; i++){
        total_candies += candies_counter[i];
    }
    return total_candies;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}