#include <iostream>
#include <stdio.h>
#include <cmath>
#include <set>

using namespace std;

set<long int> getPowerBoundData(long int &N){
	set<long int> result;
	if (N == 0) return result;
	int i = 0, j =0;
	long int tmpVal = 0;
	for (i = 0; ; i++){
		long int powIVal = pow(2,i);
		if (powIVal > N) break;
		for (j = 0; ; j++){
			tmpVal = powIVal * pow(5,j);
			if (tmpVal > N) break;
			result.insert(tmpVal);
		}
	}

	return result;
}

void displayOutput(set<long int> data){
	if (data.size() == 0)
		cout<<"Its empty set!!!\n";
	else {
		for (set<long int>::iterator it = data.begin(); it != data.end(); it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}

int main(){
	long int N;
	cout<<"Enter the high bound value: ";
	cin>>N;
	set<long int> results = getPowerBoundData(N);
	displayOutput(results);
	return 0;
}
