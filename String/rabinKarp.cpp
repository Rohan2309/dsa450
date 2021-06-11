/*
Rabin Karp {string/pattern matching}
Rolling Hash

TEXT -> A A A A A B (N=6)  [A A A -> 3 (FIRST 3)]
PAT -> A A B  -> 2+1+1 -> 4 -> HASH CODE
M=3
HASH FUNCTION  H(P): ADDING CHAR VALUES IN WINDOW (A = 1, B =2,.....Z =26)

PAT[I]-'A'+ 1  = CALCULATION
WINDOW SIZE = L OF PATTERN (3)

WHENEVER HASH CODE MATCHES WE WILL CHECK ALL THE CHARACTERS(IDX 4->6)


ROLLING HASH
IF DOEST MATCH THEN SUBSTRACT LEFT MOST VALUE FROM HASH
SHIFT ENTIRE HASH BY 1 UNIT
ADD NEW CHARACTER ADDED TO WINDOW


DRAWBACK-> SPURIOUS HITS
MATCHING IS THERE BUT NOT PATTERN  -> MAX O(MN) -> EXPECTED -> O(N-M+1)

TO AVOID SPURIOUS HITS WE NEED ADV HASH FUNC ->

D B A
D -> 4*10^2
B -> 2*10^1
A -> 1*10^0

TO AVOID OVERFLOW WE USE MOD -> CAN GET SPURIOUS HITS
FOR 32 BIT DATA TYPE MOD BY 2^31


TO SLIDE
3X10^2 + 3X10^1 + 1X10^0
[[3X10^2 + 3X10^1 + 1X10^0] - 3X10^2] X 10 + 3X10^0 //X10 TO SHIDT THE VALUE OF 10'S POWER
*/

/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
	txt -> text
	q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if (p == t)
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

/* Driver code */
int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";

    // A prime number
    int q = 101;

    // Function Call
    search(pat, txt, q);
    return 0;
}
