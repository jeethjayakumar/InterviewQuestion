#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class AirMap
{
	map<string,vector<string> > route_map;
	void printAllPathUtils(string src, string dest, vector<bool> &visited, vector<string> path, int &idx); 
	int find_index(string src);
	void display_path(vector<string> path);
public:
	AirMap(){}
	void addEdge(string src, string dest);
	void printAllPath(string src, string dest);
};

void AirMap::display_path(vector<string> path)
{
	for (int i = 0; i < path.size(); i++)
	{
		if (i == path.size()-1)
			cout<<path[i]<<endl;
		else
			cout<<path[i]<<"->";
	}
}

int AirMap::find_index(string src)
{
	int i = 0;
	map<string, vector<string> >::iterator it;
	for (it = route_map.begin(); it != route_map.end(); it++, i++)
	{
		if (it->first == src) break;
	}

	return (it == route_map.end())?-1:i;
}

void AirMap::printAllPathUtils(string src, string dest, vector<bool> &visited, vector<string> path, int &idx)
{
//	cout<<"Start: "<<src<<", End: "<<dest<<", CurrentPath: "; display_path(path);
	path.push_back(src);
	map<string,vector<string> >::iterator it = route_map.find(src);
	int index = find_index(src);
	int idx2;
	map<string,vector<string> >::iterator it2;
	vector<string>::iterator vit;
	visited[index] = true;
	
	if (src == dest)
	{
		for(int i = 0; i < path.size(); i++)
			cout<<path[i]<<" ";
		cout<<endl;
	}
	else
	{
		
		for (int i = 0; i != (it->second).size(); i++)
		{
			idx2 = find_index((it->second)[i]);
			if (!visited[idx2])
				printAllPathUtils(src, dest, visited, path, idx);
		}
		
		visited[index] = false;
	}
}

void AirMap::addEdge(string src, string dest)
{
	//cout<<"Adding route: "<<src<<"->"<<dest<<endl;
	if (route_map.find(src) == route_map.end())
	{
		vector<string> tmp;
		tmp.push_back(dest);
		route_map.insert(make_pair(src, tmp));
	}
	else
	{
		map<string, vector<string> >::iterator it = route_map.find(src);
		(it->second).push_back(dest);
	}	
}

void AirMap::printAllPath(string src, string dest)
{
	vector<bool> visited;
	vector<string> path;
	int idx = 0;
	
	for (int i = 0; i < route_map.size(); i++)
		visited.push_back(false);
	cout<<"Resetted visited vector\n";
	printAllPathUtils(src, dest, visited, path, idx);
}

int main()
{
	AirMap obj;
	obj.addEdge("A","B");
	obj.addEdge("B","A");
	obj.addEdge("A","C");
	obj.addEdge("C","A");
	obj.addEdge("A","D");
	obj.addEdge("D","A");
	obj.addEdge("A","E");
	obj.addEdge("B","C");
	obj.addEdge("C","B");
	obj.addEdge("B","D");
	obj.addEdge("D","B");

	obj.printAllPath("C","D");

	return 0;
}
