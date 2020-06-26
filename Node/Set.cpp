// NAME : Gawun Kim
// UID  : 305-186-572
// CS32 2019 Winter

#include "Set.h"
#include <iostream>
using namespace std;

Set::Set() : m_head(nullptr) {}

// Copy constructor
Set::Set(const Set& other)
{

	if (other.m_head == nullptr)	// checking other does not have data
		m_head = nullptr;
	else
	{
		// other.m_head is not nullptr anyway so that copy each node directly
		// copy the first head first
		m_head = new Node;
		m_head->data = other.m_head->data;
		m_head->next = nullptr;
		m_head->prev = nullptr;

		Node* this_x = m_head;
		Node* other_x = other.m_head;
		other_x = other_x->next;

		// copy from second node, make this exactly same with other
		while (other_x != nullptr)
		{
			Node* New_Node = new Node;
			New_Node->data = other_x->data;
			this_x->next = New_Node;
			New_Node->prev = this_x;
			New_Node->next = nullptr;
			other_x = other_x->next;
			this_x = this_x->next;
		}
	}
}

// assignment operator
Set& Set::operator=(const Set& other)
{
	if (this == &other)
		return *this;

	while (m_head != nullptr)	//deleting remained memory in 'this'
	{
		Node* tmp = m_head->next;
		delete m_head;
		m_head = tmp;
	}



	if (other.m_head == nullptr)	// checking for no data
		m_head = nullptr;	// since deletie is not necessary for that case
	else
	{

		// below is exataly same with copy constructor
		// other.m_head is not nullptr anyway so that copy a node directly
		m_head = new Node;
		m_head->data = other.m_head->data;
		m_head->next = nullptr;
		m_head->prev = nullptr;

		Node* this_x = m_head;
		Node* other_x = other.m_head;
		other_x = other_x->next;

		while (other_x != nullptr)
		{
			Node* New_Node = new Node;
			New_Node->data = other_x->data;
			this_x->next = New_Node;
			New_Node->prev = this_x;
			New_Node->next = nullptr;
			other_x = other_x->next;
			this_x = this_x->next;

		}
	}
	return *this;
}

// destructor
Set::~Set()
{
	Node* x = m_head;
	while (x != nullptr)
	{
		Node* temp = x->next;
		delete x;
		x = temp;
	}
}

bool Set::empty() const
{
	if (m_head == nullptr)	// if there no data
		return true;
	return false;
}

// counting the value when going to the next node in while loop
// and the counted value would be the number of node size 
// In my code, I did not use size(member) in private.
int Set::size() const
{
	int count = 0;
	Node* temp = m_head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}


bool Set::insert(const ItemType& value)	// should finish later not yet
{

	if (m_head == nullptr) 		// when there is no data in the node
	{				// just make a node first
		m_head = new Node;
		m_head->data = value;
		m_head->next = nullptr;
		m_head->prev = nullptr;
		return true;
	}
	else if (m_head->data > value)	// when inserting a new data before the first node
	{
		Node* New_Node1 = new Node;
		New_Node1->data = value;
		New_Node1->next = m_head;
		New_Node1->prev = nullptr;
		m_head->prev = New_Node1;
		m_head = New_Node1;
		return true;
	}
	else if (m_head->data == value)
		return false;
	else				//if there is some data already
	{				// guarantee that first node value is smaller than value

		Node* Temp_Node = m_head;
		while (Temp_Node->next != nullptr)
		{
			Temp_Node = Temp_Node->next;

			if (Temp_Node->data == value)	// the same value cannot be added in the node list
				return false;
			else if (Temp_Node->data > value)
			{
				Node* NewNode_Mid = new Node;
				NewNode_Mid->data = value;
				NewNode_Mid->next = Temp_Node;
				NewNode_Mid->prev = Temp_Node->prev;
				NewNode_Mid->prev->next = NewNode_Mid;
				Temp_Node->prev = NewNode_Mid;
				return true;
			}
		}
		// in case of inserting data into the last node
		if (Temp_Node->data == value)
			return false;
		Node* New_Node2 = new Node;
		New_Node2->data = value;
		New_Node2->prev = Temp_Node;
		New_Node2->next = nullptr;
		Temp_Node->next = New_Node2;
		return true;
	}

	return false;	// if not going into any above case, return false.
}

// this is for deleting node with comparing data
bool Set::erase(const ItemType& value)
{
	if (m_head == nullptr)		// since there is nothing to erase, so that return false
		return false;
	else if (m_head->data == value)		// when deleting the first node 
	{
		Node* temp = m_head->next;
		delete(m_head);
		m_head = temp;
		return true;
	}
	else					// when deleting data from second node
	{
		Node* temp = m_head;
		while (temp != nullptr)
		{
			if (temp->data == value)
			{
				temp->prev->next = temp->next;
				if (temp->next != nullptr)	// this is checking for the last node
					temp->next->prev = temp->prev;

				delete temp;
				return true;
			}

			temp = temp->next;
		}
	}
	return false;
}


bool Set::contains(const ItemType& value) const
{
	Node* temp = m_head;
	while (temp != nullptr)
	{
		if (temp->data == value)
			return true;
		temp = temp->next;
	}
	return false;
}


bool Set::get(int pos, ItemType& value) const
{
	if (pos < 0) return false;	// pos cannot be negative 

	Node* temp = m_head;
	int x = 0;			// this is for counting nodes which were passed through already
	while (temp != nullptr)
	{
		if (x == pos)
		{
			value = temp->data;
			return true;
		}
		temp = temp->next;
		x++;
	}
	return false;			// if pos is too big and it is out of scope in the node
}

void Set::swap(Set& other)
{
	Node* temp = other.m_head;
	other.m_head = this->m_head;
	this->m_head = temp;
}

///////////////////////////////////////////////////////////////////
// from this line, below two codes are not belonged in Set class.//
// ////////////////////////////////////////////////////////////////

void unite(const Set& s1, const Set& s2, Set& result)
{

	Set temp = s1;		// get a temperary Set called temp to save s1 data
	ItemType value;

	for (int i = 0; i < s2.size(); i++)
	{
		s2.get(i, value);
		temp.insert(value);	// insert all data in s2 node  into temp.(s1)
	}			// if same data already in the temp, it would not inserted.
	result = temp;		// temp = s1 + s2 (unite between s1 and s2) and it would end up being result
}

void subtract(const Set& s1, const Set& s2, Set& result)
{

	ItemType temp;
	Set temp_set = s1;

	for (int q = 0; q < s2.size(); q++)
	{
		s2.get(q, temp);
		temp_set.erase(temp);	// only existed data would be deleted
	}				// and it affects the size
	result = temp_set;
}

