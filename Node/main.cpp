#include <iostream>
#include "Set.h"
#include <assert.h>

int main()
{
	//****************** testing => insert + empty + size ******************
	Set x;
	ItemType temp;
	assert(x.size() == 0 && x.empty());       // test size and empty
	assert(x.insert("C") && x.size() == 1);
	assert(!x.insert("C") && x.size() == 1);  // nothing to insert. Same data cannot be inserted
	assert(x.insert("D") && x.size() == 2);
	assert(x.insert("B") && x.size() == 3);
	assert(x.insert("F") && x.size() == 4);
	assert(x.insert("E") && x.size() == 5);
	assert(!x.insert("E") && x.size() == 5);
	assert(x.insert("H") && x.size() == 6);
	assert(x.insert("G") && x.size() == 7);
	// B C D E F G H
	//********************* testing => Erase + size **********************
	assert(x.erase("C") && x.size() == 6);
	assert(x.erase("G") && x.size() == 5);
	assert(x.erase("B") && x.size() == 4);
	assert(!x.erase("B") && x.size() == 4);  // nothing to delete. There is no 'B' in node data
	// D E F H
	//********************* testing => Contain ***************************
	assert(x.contains("D") &&
		x.contains("E") &&
		x.contains("F") &&
		x.contains("H") &&
		!x.contains("X"));        // X is not contained.
	//********************* testing => get *******************************
	ItemType test;
	assert(x.get(0, test) && test == "D");
	assert(x.get(3, test) && test == "H");
	assert(x.get(2, test) && test == "F");
	assert(x.get(1, test) && test == "E");
	test = "Sexy Gawun";
	assert(!x.get(4, test) && test == "Sexy Gawun");
	assert(!x.get(-1, test) && test == "Sexy Gawun");     // invalid the value of number
												 // it should be from 0 to size of node

	//********************** testing => copy const **********************
	Set y(x);                                       // copy constructor
	assert(y.size() == 4);
	assert(y.get(0, test) && test == "D");
	assert(y.get(1, test) && test == "E");
	assert(y.get(2, test) && test == "F");
	assert(y.get(3, test) && test == "H");
	// y -> D E F H    successfully copied from node x


	assert(y.insert("Kim") && y.size() == 5);
	assert(!y.insert("Kim") && y.size() == 5);    // not inserted since multiple same data is not allowed
	assert(y.insert("Lim") && y.size() == 6);
	assert(y.insert("Lee") && y.size() == 7);
	// Inserting 'Lee', 'Kim' and 'Lin' in Set y
	 // D E F H Kim Lee Lim    <- y
	assert(y.get(4, test) && test == "Kim");
	assert(y.get(5, test) && test == "Lee");
	assert(y.get(6, test) && test == "Lim");
	assert(y.size() == 7);
	// delete 'D' 'E' 'F' in Set y
	assert(y.erase("D") && y.size() == 6);
	assert(y.erase("E") && y.size() == 5);
	assert(y.erase("F") && y.size() == 4);
	// y -> H Kim Lee Lim
	assert(!y.erase("D") && y.size() == 4);  // cannot be deletable  since there is no D in nodes
	assert(y.get(0, test) && test == "H");
	assert(y.get(1, test) && test == "Kim");

	// assignment operator will be in bottom side
	//********************  testing => swap ***************************
	// x = {D E F H }               before swap
	// y = {H Kim Lee Lim}
	x.swap(y);
	// x = {H Kim Lee Lim }         after the first swap
	// y = {D E F H}
	//
	assert(!x.contains("D") &&    // check x elements
		!x.contains("E") &&
		!x.contains("F") &&
		x.contains("H") &&
		x.contains("Kim") &&
		x.contains("Lee") &&
		x.contains("Lim") &&
		y.contains("D") &&     // check y elements
		y.contains("E") &&
		y.contains("F") &&
		y.contains("H") &&
		!y.contains("Kim") &&
		!y.contains("Lee") &&
		!y.contains("Lim"));


	x.swap(y);
	// x = {D E F H }               after the second swap
	// y = {H Kim Lee Lim}
	//
	assert(x.contains("D") &&     // check x elements
		x.contains("E") &&
		x.contains("F") &&
		x.contains("H") &&
		!x.contains("Kim") &&
		!x.contains("Lee") &&
		!x.contains("Lim") &&
		!y.contains("D") &&   // check y elements
		!y.contains("E") &&
		!y.contains("F") &&
		y.contains("H") &&
		y.contains("Kim") &&
		y.contains("Lee") &&
		y.contains("Lim"));
	//************************ testing => unite **********************
	// x = {D E F H }
	// y = {H Kim Lee Lim}
	// checking whether there are all elements in the result set
	Set result;
	unite(x, y, result);
	assert(result.contains("D") &&
		result.contains("E") &&
		result.contains("F") &&
		result.contains("H") &&
		result.contains("Kim") &&
		result.contains("Lee") &&
		result.contains("Lim"));

	//********************* testing => subtract **********************
	// x = {D E F H }
	// y = {H Kim Lee Lim}

	subtract(x, y, result);
	assert(result.contains("D") &&
		result.contains("E") &&
		result.contains("F") &&
		!result.contains("H") &&    // H is commonly existed in x and y
		!result.contains("Kim") &&
		!result.contains("Lee") &&
		!result.contains("Lim"));


	subtract(y, x, result);
	assert(!result.contains("D") &&
		!result.contains("E") &&
		!result.contains("F") &&
		!result.contains("H") &&    // H is commonly existed in x and y
		result.contains("Kim") &&
		result.contains("Lee") &&
		result.contains("Lim"));

	//******************* testing => assignment operator ********************
	// x = {D E F H }
	// y = {H Kim Lee Lim}

	x = y;
	// after assignment constructor
	// x = {H Kim Lee Lim }
	// y = {H Kim Lee Lim}

	assert(x.size() == 4);
	assert(x.contains("H") &&
		x.contains("Kim") &&
		x.contains("Lee") &&
		x.contains("Lim") &&
		!x.contains("D") &&   // not included in new x
		!x.contains("E") &&   // not included
		!x.contains("F"));      // not included
	printf("TEST CASE ALL PASSED");

}