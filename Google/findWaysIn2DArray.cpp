#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> Node;

bool isValid(int x, int y, int M, int N){
	return !(x < 0 || y < 0 || x >= M || y >= N);
}
void countPath(int x, int y, Node &dest, vector<vector<bool> > &visited, int &count, int &M, int &N){
	if (x == dest.first && y == dest.second){
		count ++;
		return;
	}
	visited[x][y] = true;
	if (isValid(x, y, M, N)){
		if (x - 1 >= 0 && !visited[x-1][y])
			countPath(x-1, y, dest, visited, count, M, N);
		if (x + 1 < M && !visited[x+1][y])
			countPath(x+1, y, dest, visited, count, M, N);
		if (y - 1 >= 0 && !visited[x][y-1])
			countPath(x, y-1, dest, visited, count, M, N);
		if (y + 1 < N && !visited[x][y+1])
			countPath(x, y+1, dest, visited, count, M, N);
	}
	visited[x][y] = false;
}

int findWays(Node &src, Node &dest, int &M, int &N){
	if (M == 0 && N == 0)
		return 0;
	int count = 0;
	vector<vector<bool> > visited;
	countPath(src.first, src.second, dest, visited, count, M, N);
	return count;
}

int main(){
	int M, N;
	cout<<"Enter the size of 2D Array: ";
	cin>>M>>N;
	Node src = make_pair(0,0);
	Node dest = make_pair(M-1, 0);
	int ways = findWays(src, dest, M, N);
	cout<<"Number of ways to go from (0,0) to ("<<M-1<<",0): "<<ways<<"\n";
	return 0;
}
