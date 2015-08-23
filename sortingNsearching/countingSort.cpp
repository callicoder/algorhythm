/*
	Time Complexity : O(n + k)

*/
#include<cstdio>
#include<cstring>
#define RANGE 255

void countingSort(char *str)
{

	// The output character array that will have sorted str
	char output[strlen(str)];

	// Create a count array to store count of inidividul characters and
	// initialize count array as 0
	int count[RANGE+1];
	memset(count, 0, sizeof(count));

	// Store count of each character
	for(int i = 0; str[i]; i++)
		++count[str[i]];
	
	// Change count[i] so that count[i] now contains actual position of
    // this character in output array.
	// i.e. Modify the count array such that each element at each index 
    // stores the sum of previous counts.
	for(int i = 1; i <= RANGE; i++)
		count[i] += count[i-1];

	
	// Build the output character array
	for(int i = 0; str[i]; i++)
	{
		output[count[str[i]]-1] = str[i];
		--count[str[i]];
	}

	// Copy the output array to str, so that str now
	// contains sorted characters
	for (int i = 0; str[i]; ++i)
		str[i] = output[i];
}

int main()
{
	char str[] = "ababababab";
	countingSort(str);
	printf("Sorted string is : \n%s\n",str);
	return 0;
}
	
