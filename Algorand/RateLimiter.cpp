#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;


class ClientRequestInfo
{
	int clientID;
	int timeID;
public:
	ClientRequestInfo(int clientID, int timeID){
		this->clientID = clientID;
		this->timeID = timeID;
	}

	~ClientRequestInfo(){ }
	
	int getTimeID(){
		return timeID;
	}

	int getClientID(){
		return clientID;
	}
};


// ASSUMPTION: Currently this solution is implemented for single client.
//             Will modify the code to support multiple client. 
//	       Basic logic remains the same.
bool rateLimiter(int &reqTime, queue<int> &timeQueue){
	if (timeQueue.empty()){
		timeQueue.push(reqTime);
		return true;
	}
	
	if (timeQueue.size() == 3){
		int timeDiff = reqTime - timeQueue.front();
		if (timeDiff < 1000)
			return false;
		else{
			timeQueue.pop();
			timeQueue.push(reqTime);
		}
	}
	else
		timeQueue.push(reqTime);
	return true;
}

void initializeClientReqCounter(int &clientCount, map<int, queue<int> > &clientRequestCount, queue<int> reqTimeInfo[]){
	int tmpClientID;
	for (int i = 0; i < clientCount; i++){
		cout<<"Enter client ID: ";
		cin>>tmpClientID;
		clientRequestCount.insert(make_pair(tmpClientID, reqTimeInfo[i]));
	}
}

// This method will help us handle multiple clients!!!
bool checkRequestStatus(ClientRequestInfo reqInfo, map<int, queue<int> > &clientRequestCount){
	int cID = reqInfo.getClientID();
	if (clientRequestCount.find(cID) == clientRequestCount.end()){
		cout<<"Client ID: "<<cID<<" not registered!!! Request failed!!!\n";
		return false;
	}

	queue<int> &tmp = clientRequestCount[cID];
	return rateLimiter(reqInfo.getTimeID(), tmp);
}

int main()
{
	int clientCount;
	cout<<"Enter number of Clients: ";
	cin>>clientCount;

	map<int, queue<int> > clientRequestCount;
	queue<int> reqTimeInfo[clientCount];
	
	initializeClientReqCounter(clientCount, clientRequestCount, reqTimeInfo);
/*	
	int count = 0;
	int reqTime = 100;
	while (count < 20)
	{
		cout<<"RequestTime = "<<reqTime<<" Request Status = "<<rateLimiter(reqTime, reqTimeInfo)<<endl;
		reqTime += 100;
		count ++;
	}
*/
	ClientRequestInfo *tmpClient = new ClientRequestInfo(100, 100);
	cout<<"ClientID: "<<tmpClient->getClientID()<<" Request Status: "<<checkRequestStatus(*tmpClient, clientRequestCount)<<endl;
	return 0;
}
