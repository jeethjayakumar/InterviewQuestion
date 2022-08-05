#include <iostream>
#include <stdio.h>

using namespace std;

class ListNode
{
	string data;
	string orgData;
	ListNode* next_p;
public:
	ListNode(string data){
		this->data = data;
		this->orgData = data;
		this->next_p = nullptr;
	}

	~ListNode(){ }

	string getData(){
		return data;
	}

	void setData(string data){
		this->data = data;
	}

	string getOrgData(){
		return orgData;
	}

	ListNode* getNextNode(){
		return next_p;
	}
	
	void setNextNode(ListNode* node){
		next_p = node;
	}

	bool checkData(){
		return (data == orgData);
	}
};	

class LinkedList
{
	ListNode *dataHead;
	bool tampered;
	void updateTamperedFlag(){
		ListNode *tmp = dataHead;
		while(tmp != nullptr){
			if (!tmp->checkData()){
				tampered = true;
				break;
			}
			tmp = tmp->getNextNode();
		}
		if (tmp == nullptr)
			tampered = false;
	}
public:
	LinkedList(){
		dataHead = nullptr;
		tampered = false;
	}	
	~LinkedList(){ }
	
	void push(string x){
		if (dataHead == nullptr)
		{
			dataHead = new ListNode(x);
		}
		else
		{
			ListNode* tmp = new ListNode(x);
			tmp->setNextNode(dataHead);
			dataHead = tmp;
		}
	}

	string pop(){
		if (dataHead == nullptr){
			return "No data to remove";
		}
		else {
			string dataRemoved = dataHead->getData();
			ListNode *tmp = dataHead;
			dataHead = dataHead->getNextNode();
			tmp->setNextNode(nullptr);
			delete tmp;

			return dataRemoved;	
		}
	}

	bool empty(){
		return (dataHead == nullptr);
	}

	bool valid(){
		return !tampered;
	}

	void tamper(int pos, string newVal){
		if (dataHead == nullptr){
			cout<<"No data to tamper with!!!\n";
			return;
		}

		int count = 0;
		ListNode* tmp = dataHead;
		while((count != pos-1) && tmp->getNextNode()!= nullptr){
			count++;
			tmp = tmp->getNextNode();
		}

		if (tmp == nullptr){
			cout<<"List reached at the end!!! No index found!!!\n";
			return;
		}
		if (count == (pos - 1)){
			if (tmp->getData() != newVal)
				tmp->setData(newVal);
		}
		updateTamperedFlag();
	}
	
	void displayList(){
		ListNode *tmp = dataHead;
		while(tmp != nullptr){
			if(tmp->getNextNode() != nullptr)
				cout<<tmp->getData()<<"->";
			else
				cout<<tmp->getData()<<"\n";
			tmp = tmp->getNextNode();
		}
	}
};

int main()
{
	LinkedList list;
	cout<<"Is list empty now: "<<list.empty()<<endl;
	list.push("100");
	list.push("200");
	list.push("300");
	list.displayList();
	string topData = list.pop();
	cout<<"Removed Data: "<<topData<<" Current List: ";
	list.displayList();
	cout<<"Is List Valid: "<<list.valid()<<endl;
	cout<<"Is list empty now: "<<list.empty()<<endl;
	list.tamper(2, "100");
	cout<<"Is List Valid: "<<list.valid()<<endl;
	cout<<"Current list: "; list.displayList();
	list.tamper(2, "300");
	cout<<"Is List Valid: "<<list.valid()<<endl;
	cout<<"Current list: "; list.displayList();
	list.tamper(1, "300");
	cout<<"Is List Valid: "<<list.valid()<<endl;
	cout<<"Current list: "; list.displayList();
	list.tamper(2, "100");
	cout<<"Is List Valid: "<<list.valid()<<endl;
	cout<<"Current list: "; list.displayList();
	list.tamper(1, "200");
	cout<<"Is List Valid: "<<list.valid()<<endl;
	cout<<"Current list: "; list.displayList();
	return 0;
}
