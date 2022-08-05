#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

/*
class ClientRequestInfo
{
	int clientID;
	int timeID;
public:
	ClientRequestInfo(int clientID, int timeID)
	{
		this->clientID = clientID;
		this->timeID = timeID;
	}

	~ClientRequestInfo()
	{

	}
	
	int getTimeID()
	{
		return timeID;
	}

	int getClientID()
	{
		return clientID;
	}
};
*/

// ASSUMPTION: Currently this solution is implemented for single client.
//             Will modify the code to support multiple client. 
//	       Basic logic remains the same.
bool rateLimiter(int &reqTime, queue<int> &timeQueue)
{
	if (timeQueue.empty())
	{
		timeQueue.push(reqTime);
		return true;
	}
	
	if (timeQueue.size() == 3)
	{
		int timeDiff = reqTime - timeQueue.front();
		if (timeDiff < 1000)
			return false;
		else
		{
			timeQueue.pop();
			timeQueue.push(reqTime);
		}
	}
	else
		timeQueue.push(reqTime);
	return true;
}

int main()
{
	//int clientCount;
	//cout<<"Enter number of Clients: ";
	//cin>>clientCount;

	//ClientRequestInfo clients[clientCount];
	//map<int, queue<int>> clientRequestCount;

	queue<int> reqTimeInfo;
	int count = 0;
	int reqTime = 100;
	while (count < 20)
	{
		cout<<"RequestTime = "<<reqTime<<" Request Status = "<<rateLimiter(reqTime, reqTimeInfo)<<endl;
		reqTime += 100;
		count ++;
	}
	return 0;
}
