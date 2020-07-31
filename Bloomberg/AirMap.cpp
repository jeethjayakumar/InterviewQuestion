/*
   Implement a class called AirMap that has two methods:
   -> add_route(start, dest) : adds a ONE-WAY connecting flight from start to destination
   -> print_all_routes(start, dest) : prints all possible routes from start to destination irrespective
   Given the following flight routes, print all possible routes between airports C and D
 
   Implementation of Approach 1:
	Add the source and destinations into multimap datastructure. 
	Before adding any route to multimap, first find if the route is already present or not.
	If it is not present in multimap, then add.
	
	find_path() function will be a recursive function.
	First it will check if the tmp_start = dest, if yes then display the complete path. 
	If tmp_start key_value is not found in multi map, then its better to return 
	because there is no more routes starting with tmp_start.
	If tmp_start is present in path data structure, which mean we already visited this place so return.
	Once these conditions are completed, then we loop up the multimap going through all possible route destination 
	starting from tmp_start and keep calling find_path() till we reach destination. 
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class AirMap
{
	multimap<string, string> route_map;
public:
	AirMap() {}
	~AirMap() {}
	
	void add_route(string start, string dest)
	{
		multimap<string, string>::iterator it;
		bool found = false;
		if (route_map.find(start) == route_map.end())
			route_map.insert(make_pair(start, dest));
		else
		{
			for (it = route_map.begin(); it != route_map.end(); it++)
			{
				if(it->first == start)
				{
					if (it->second == dest)
					{
						found = true;
						break;
					}

				}
			}

			if (found != true)
				route_map.insert(make_pair(start,dest));
		}
	}

	void display_path(vector<string> path)
	{
		if (path.empty())
			cout<<"Path is empty"<<endl;
		else
		{
			for (int i = 0; i< path.size(); i++)
			{	
				if (i == path.size() - 1)
					cout<<path[i]<<endl;
				else
					cout<<path[i]<<"->";
			}
		}
	}

	void find_path(string start, string tmp_start, string dest, vector<vector<string> >&final_list, vector<string> &path)
	{
		if (tmp_start == dest) // Reached Destination, Path complete
		{
			path.push_back(tmp_start);
			display_path(path);
			path.clear();
			return;
		}

		if (route_map.find(tmp_start)==route_map.end()) return; // If start key is not present in route_map
		if (find(path.begin(), path.end(), tmp_start) != path.end()) return; // If start value is already present in path; To avoid a loop

		multimap<string,string>::iterator it;

		for(it = route_map.begin(); it != route_map.end(); it++)
		{
			if (it->first == tmp_start)
			{
				if (path.empty()) path.push_back(start); // Starting new path from start
				if (find(path.begin(), path.end(), tmp_start) == path.end()) path.push_back(tmp_start);
				find_path(start, it->second, dest, final_list, path);
				if (path.empty() && (tmp_start != start)) return; // One path already found
			}
		}
		if (it == route_map.end() && (tmp_start != dest) && !path.empty()) path.erase(path.end()-1); //Remove the last element
		
	}

	void print_all_routes(string start, string dest)
	{
		vector<vector<string> > final_list;
		vector<string> path;
		multimap<string,string>::iterator it;

		find_path(start, start, dest, final_list, path);
/*
		if (!final_list.empty())
		{
			for (int i =0; i < final_list.size(); i++)
				display_path(final_list[i]);
		}
		else
			cout<<"No routes found between "<<start<<" and "<<dest<<endl;
*/
	}
};

int main()
{
	AirMap obj;
	obj.add_route("A","B");
	obj.add_route("B","A");
	obj.add_route("A","C");
	obj.add_route("C","A");
	obj.add_route("A","D");
	obj.add_route("D","A");
	obj.add_route("B","C");
	obj.add_route("C","B");
	obj.add_route("B","D");
	obj.add_route("D","B");
	obj.add_route("A","E");

	obj.print_all_routes("E","A");

	return 0;
}

