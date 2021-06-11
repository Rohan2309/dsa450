/*
pattern matching
*BASIC ALGO*
    idx    i
text    -> a b c d a b c a b  c  d  f
           1 2 3 4 5 6 7 8 9 10 11 12

    idx    j
pattern -> a b c d f
           1 2 3 4 5


if i and j matches move j as well as i
if mismatch
j will start from beginning
i will start from i+1

problem -> i have to come again at front if a mismatch ->o(mn) time


*KMP - Knuth Morris Pratt *


pattern    -> a b c d a b c 
              1 2 3 4 5 6 7 

prefix: a, ab, abc, abcd  {start from left hand side}

suffix: c, bc, abc, dabc {start from rhs}

is there any prefix same as suffix? abc


pi table -> longest prefix which is same as a suffix

           1 2 
p1:     -> a b c d a b e a b  f     (ab)
           0 0 0 0 1 2 0 1 2 0
           

           1 2 3 
p2:     -> a b c d e a b f a  b c   (abc)
           0 0 0 0 0 1 2 0 1 2 3

           1 
p2:     -> a a b c a d a a b e      (a)
           0 1 0 0 1 0 1 2 0 0

           1 2 3 4 5 6 7 8 9  
p2:     -> a a a a b a a c d        (a)   
           0 1 2 3 0 1 2 0 0 

       i
Str -> a b a b c a b c a  b  a  b  a  b  d
       1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

 j=0   1 2 3 4 5   (idx)
Pat -> a b a b d  (pi table)
       0 0 1 2 0

str is at i and pat is at j=0
compare i with j+1 
if match move j as well as i

when mismatch
 j=4   1 2 3 4 5   (idx)
Pat -> a b a b d  (pi table)
       0 0 1 2 0
move j to idx = 2 as at 4 there is b and it gave pi value 2

 j=2   1 2 3 4 5   (idx)
Pat -> a b a b d  (pi table)
       0 0 1 2 0
when j is at 0 we can't move j so i+1
*/
#include <bits/stdc++.h>

void computeLPSArray(char *pat, int M, int *lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver program to test above function
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}