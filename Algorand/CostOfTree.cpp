#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int calculateCost(vector<int> arr);
void displayInputOutput(vector<int> inputArr, int output);

int main()
{
    vector<int> arr;
    int output;

    arr.push_back(2);
    arr.push_back(1);
    output = calculateCost(arr);
    displayInputOutput(arr, output); 
    
    arr.clear();
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(1);
    output = calculateCost(arr);
    displayInputOutput(arr, output);

    arr.clear();
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(3);
    output = calculateCost(arr);
    displayInputOutput(arr, output);
   	
    return 0;
}

void displayInputOutput(vector<int> arr, int output)
{
    cout<<"Input: ";
    for (int i = 0; i < arr.size(); i++)
    {
	cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Output: "<<output<<endl;
}

int calculateCost(vector<int> arr)
{
    if (arr.size() < 2 || arr.size() > 50)
        return 0;

    int output = 0;

    while(arr.size() > 1)
    {
        int minVal = *min_element(arr.begin(), arr.end() - arr.begin());
        int minIdx = find(arr.begin(), arr.end(), minVal);
	if ((minIdx > 0) &(minIdx < (arr.size() - 1)))
	    output += arr[minIdx] * min(arr[minIdx - 1], arr[minIdx + 1]);
	else if (minIdx == 0)
	    output += arr[minIdx] * arr[minIdx + 1];
	else
	    output += arr[minIdx] * arr[minIdx - 1];
	arr.erase(arr.begin() + minIdx);	
    }

    return output;
}
