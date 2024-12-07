// C++ program for implementation of KMP pattern searching
// algorithm

#include <bits/stdc++.h>

void computeLPSArray(char *pat, int M, int *lps);

// Prints occurrences of pat[] in txt[]
void KMPSearch(char *pat, char *txt)
{
	int M = strlen(txt);
	int N = strlen(pat);
	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[N];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, N, lps);

	for (int i = 0; i < sizeof(lps) / sizeof(lps[0]); i++)
		std::cout << lps[i] << ' ';
	std::cout << std::endl;

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]

	while (i < M)
	{
		if (pat[j] == txt[i])
		{
			i++;
			j++;
		}

		else
		{
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}

		if (j == N)
		{
			printf("Found pattern at index %d.\n", i - j);
			j = lps[j - 1];
		}

		// mismatch after j matches
	}
}

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char *pat, int N, int *lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int j = 1;
	while (j < N)
	{

		if (pat[j] == pat[len])
		{
			len++;
			lps[j] = len;
			j++;
		}

		else //if (pat[i] != pat[len])
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
				lps[j] = 0;
				j++;
			}
		}
	}
}

// Driver code

int main()
{
	char txt[] = "ABABCABABDABABCABAB";
	char pat[] = "AABBAA";
	KMPSearch(pat, txt);
	return 0;
}
/*
AAACBECAAA
AAABECAAA#AAACEBAAA
*/
