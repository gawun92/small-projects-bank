#ifndef _SET_H_
#define _SET_H_
#include <string>
using ItemType = std::string;

class Set
{
public:
	Set();
	Set(const Set& other);
	Set& operator=(const Set& other);
	~Set();
	// empty() is checking whether there is data or not.
	// In other word, if there is no data and no node, 
	// it would be true. If not, it would be false
	bool empty() const;
	// size() is showing the number of nodes. 					
	int  size() const;
	// insert() is inserting function. After comparing value with each data in nodes,
	// put the value in proper location(between two sepuencial nodes). 
	// It allows all nodes' data orderly.		
	// when this function checks all data in each of nodes and if there is same data with value.
	// this function returns false and nothing happened. If not, inserting new node
	// and the function returns true.
	bool insert(const ItemType& value);
	// erase() is deleting a node which has value as its data. 
	// If value is not found in each node data, the function returns false and nothing happened.
	// If value is found in each node data, the function returns true and the target node would be deleted
	bool erase(const ItemType& value);
	// it is checking each of nodes for whether they have same data with value. If found a node, return true.
	// it not found a node, return false
	bool contains(const ItemType& value) const;
	// This function receives pos and value as parameter. The value will be assigned with data from 
	// some location and pos is indexing the location in node sequences.
	// this function will be used to check data and its location in node sequence.
	// if pos has big or small number rather than the size of node, it would return false and does nothing.
	// if it is between 0 to the max size, return true.
	bool get(int pos, ItemType& value) const;
	// swap function receives some set object and swaping its data with this data.
	// there is no return type.
	void swap(Set& other);


private:

	struct Node
	{
		ItemType data;
		Node* next;
		Node* prev;
	} *m_head;
};
// this function receives three sets objects. The function is combining data from s1 and s2.
// and assigning the combined nodes into result object.
// In result, it allows multiple same data as only one data.  
void unite(const Set& s1, const Set& s2, Set& result);
// this function recieves three sets objects. This function subtract s1 to s2.
// result will be assigned with the subtracted value.
// only commonly existed data in s1 and s2 will be deleted.
void subtract(const Set& s1, const Set& s2, Set& result);

#endif
