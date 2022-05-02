/*
MIN MAX RIDDLE (Find the maximum of minimums of every window size)
Given an integer array of size , find the maximum of the minimum(s) of every window size in the array. The window size varies from  to .

For example, given , consider window sizes of  through . Windows of size  are . The maximum value of the minimum values of these windows is . Windows of size  are  and their minima are . The maximum of these values is . Continue this process through window size  to finally consider the entire array. All of the answers are .

Function Description

Complete the riddle function in the editor below. It must return an array of integers representing the maximum minimum value for each window size from  to .

riddle has the following parameter(s):

arr: an array of integers
Input Format

The first line contains a single integer, , the size of .
The second line contains  space-separated integers, each an .

Constraints



Output Format

Single line containing  space-separated integers denoting the output for each window size from  to .

Sample Input 0

4
2 6 1 12
Sample Output 0

12 2 1 1
Explanation 0

Here  and 

window size	window1	window2	window3	window4	maximum of all windows
1	2	6	1	12	12
2	2	1	1		2
3	1	1			1
4	1				1
Sample Input 1

7
1 2 3 5 1 13 3
Sample Output 1

13 3 2 1 1 1 1
Explanation 1

Here  and 

win size	w_1	w_2	w_3	w_4	w_5	w_6	w_7	maximum of all windows
1	1	2	3	5	1	13	3	13
2	1	2	3	1	1	3		3
3	1	2	1	1	1			2
4	1	1	1	1				1
5	1	1	1					1
6	1	1						1
7	1							1
Sample Input 2

6
3 5 4 7 6 2
Sample Output 2

7 6 4 4 3 2
Explanation 2

Here  and 

win size	w_1	w_2	w_3	w_4	w_5	w_6	maximum of all windows
1	3	5	4	7	6	2	7
2	3	4	4	6	2		6
3	3	4	4	2			4
4	3	4	2				4
5	3	2					3
6	2						2
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    // complete this function
    int n =arr.size();
    vector<long>ans(n+1);
    vector<long>rNSE(n+1);//will have right smaller element
    vector<long>lPSE(n+1);//will have left smaller element
    stack<long>s;
    for(int i=0;i<n;++i){//base cases
        rNSE[i]=n;//if no smaller ele present in right it will be n
        lPSE[i]=-1;//if no smaller ele present in left it will be 0
    }
    for(int i=0;i<=n;++i){
        ans[i]=0;//ans vector
    }
    //filing eles of left
    for(int i=0; i<n; ++i){
        //we store in stack, in increasing order
        while(!s.empty() and arr[s.top()]>=arr[i])s.pop();//elements greater than current ele , //remove them
        if(!s.empty())lPSE[i]=s.top();//otherwise the ele present in stack is prev smaller
        s.push(i);//pushing current index in stack
    }
    while(!s.empty())s.pop();//reuse stk
    //filing eles of right
    for(int i=n-1; i>=0; --i){
        //we store in stack, in increasing order
        while(!s.empty() and arr[s.top()]>=arr[i])s.pop();//elements greater than current ele , //remove them
        if(!s.empty())rNSE[i]=s.top();//otherwise the ele present in stack is prev smaller
        s.push(i);//pushing current index in stack
    }
    //filling answer array
    //arr[i] is a minimum of a window of length “right[i] – left[i] – 1”.
    // the arr[i] element is minimum in the window of size ans[i]
    for(int i=0; i<n;++i){
        int len = rNSE[i]-lPSE[i]-1;
        ans[len]= max(ans[len],arr[i]);//maximum value replaces
    }
    //entries which are 0
    //Result for length i, i.e. ans[i] would always be greater or same as result for length i+1, i.e., ans[i+1]. 
    for(int i=n-1; i>=1;i--){
        ans[i]= max(ans[i],ans[i+1]);
    }
    ans.erase(ans.begin());//as first will be 0
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
