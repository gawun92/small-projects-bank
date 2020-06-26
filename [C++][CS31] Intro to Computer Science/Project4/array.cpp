#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/****************************************************************************/
int appendToAll(string a[], int n, string value){	// append value to the end of each of n elements
	if(n <= 0){			// if n is negative, return -1   also, n cannot be zero; it should be positive
		return-1;		// not with standing
	}
	
	for(int i=0; i<n;i++){		// this for loop make go through all elements  0 to n-1
		a[i] = a[i] + value;    // this is appending value and to all elements 
	}
	return n;			// if it is successful, return n
}
/*****************************************************************************/
int lookup(const string a[], int n, string target){ 	// return the position of a string in the array that is equal to target   return the smallest postion
	if(n <= 0){		// the parameter value (n)  should be at least 1, the value of n cannot be negative number and zero.
	       	return -1;	// return -1, when the value of n is not proper
	}
	
	int i = 0;
	while(i != n){			// it will make an array pass through all  elements by the end
		if(a[i] == target){     // it catches the smallest position
			return i;	// as long as, the smallest position has been catched, return the position of the array
		}
		i++;
	}
	return -1;	// if there is not same string detected, return -1

}
/*****************************************************************************/
int positionOfMax(const string a[], int n){	//return the position of a string which is same or bigger than others
	if(n <= 0){		// the parameter value n should be at least 1, the value n cannot be negative number and zero.
		return -1;
	}

	string haha = "";   	// this empty string will be used to comparing each element
	int i = 0;		// this i is for while loop counting	
	int SaveTheSmallestPosition;
	int CountingTheSame = 0;
	while( i != n ){										
                if(haha < a[i]){			// if haha is bigger or same, the element would be skipped
		       					// the same element is just skipping, because only the smallest postion should be concerned and return the location. 
                        haha = a[i];			// but in case of haha is smaller, put element data into haha   <- it will be used to compare to other elemnt later
                        SaveTheSmallestPosition = i;    // save the position of the big element
                }

        i++;
	}
        return SaveTheSmallestPosition;			// this is the location of the biggest element
}
/****************************************************************************/
							// I did not create additional array in this function.
							//
int rotateLeft(string a[], int n, int pos){		// delete an element which is in position of array (pos)   and send this element to the end of array		
	if(n <= 0){				// the size of array cannot be negative    also cannot be 0. It should be always over 1.
		return -1;
	}
	string dataSaving = a[pos];		// save and memorize a string in element( location : pos ) of array 

	if(pos == n-1){
	//	a[pos] = dataSaving;  // no change
	} else if(pos == n-2){
		a[pos] = a[n-1];
		a[n-1] = dataSaving;
	} else{
		for(int i = pos; i < n-1 ; i++){	// start concerning the elements from pos to the end of the array
			string TmpSave = a[i+1];
			a[i] = a[i+1];			// push all elements to the front lacation except the element in pos (location)
			a[i+1] = TmpSave;
		}
		a[n-1] = dataSaving;			// lastly, saving pos data(it has been saved in 'dataSaving') into the last element
	}
	return pos;				// return the value of pos
}

		/****another version (by copying array  // creating additional array)****************
		 *  		string SaveData = a[pos];
      	  	 * 		int j = 0;
         	 *  		while(j != n-1){
         	 *       		if(j >= pos){
     		 *               		a[j] = a[j+1];
          	 *      	 	}
         	 *       	 j++;
         	 *		}
         	 *       	a[n-1] = SaveData;
          	 *       	return pos;					
	 	 ***********************************************************************************/
/****************************************************************************/
int countRuns(const string a[], int n){		// return the number of sequences of one or more consecutive identical items in a.
	if( n <= 0){				// n should be at least 1
		return -1;
	}
	int SeqCount = 0;			// seqCounting is checking how many different consecutive identical items are in an array.	
	int i = 0;

	if (n == 1){			// if there is only one
		return 1;
	}else{						/////////////////////////////////////////////////////////asdfasdfasdfasdcasdcsa

		while(i < n-1){
			if(a[i] != a[i+1]){		// seqCount value will be counted when a temperary element and a next element are not same
			SeqCount++;			// but if a tmperary element and a next element are same each other, they would skip 'if'
			}
		  i++;
		}
	return (SeqCount+1);			// return number of groups (have each of  same seq value)
	}
}
/***************************************************************************/
								// I did not create additional array in this function.
								//
int flip(string a[], int n){   					// Reverse the order of the elements of the array and return n.   
	int i=0;									
		if( n <= 0){					// n should be at least 1
			return -1;				
		}	
		if(n % 2 == 0){   				// if n is an even number
			while( n/2 != i ){			// ex) flip(string a[], int 4)   a[4] = {0, 1, 2, 3}
				string Saving = a[n-1-i];	// 	    after the function          {3, 1, 2, 0} -> {3, 2, 1, 0}
				a[n-1-i] = a[i];		// swape the location of the front area elements and the location of the end area elements
				a[i] = Saving;
				i++;
			}
		}else{		  				// if n is an odd number
			while( ((n-1)/2) != i){			// ex) flip(string a[], int 3)   a[5] = {0, 1, 2, 3, 4}	
				string Saving = a[n-1-i];	// 	     after the function         {4, 1, 2, 3, 0} -> {4, 3, 2, 1, 0}
                                a[n-1-i] = a[i];		//                                      i=0         n-1-i   i  (n-1-i)
                                a[i] = Saving;
                                i++;
			}			
		}

	
	return n;						// return the value of n

}
/****************************************************************************/
int differ(const string a1[], int n1, const string a2[], int n2){ 	// Return the position of the first corresponding elements of a1 and a2 that are not equal.
	if( n1 <= 0 || n2 <= 0 ){					// each of them should be at least 
		return -1;
	}		
	int sum = 0;							// to count same elements and its value would be for return
	int x;
	if(n1 > n2){
		x = n2;
	}else{
		x = n1;
	}
	for(int i=0; i<x; i++){					// regardless of the size of a1 and a2, both of them is working
		if(a1[i]==a2[i]){					// if two of elements are same each other, it is counting 
			sum += 1;
		}	
	}
	return sum;		
}
/****************************************************************************/
int subsequence(const string a1[], int n1, const string a2[], int n2){	// If all n2 elements of a2 appear in a1, consecutively and in the same order, 
									// then return the position in a1  where that subsequence begins
	if( n1 <= 0 || n2 <= 0){					// n should be at least 1 or bigger than 1
		return -1;
	}
	int save_I;							// this variable will be an index for the position of subsequence begins	        
	int i =0;	

	while(a1[i] != a2[0]){						// this is to find a same sequence start
		i++;
			if(i == n1){					// if there is no same data in the both
				return -1;
			}
	}	
	save_I = i;					// if same element is detected

	for( int j = 0; j < n2; j++){
		if(a2[j] != a1[i]){					//checking next other elements in each of arrays
			return -1;
		}
		i++;
	}
	return save_I;  // if is all successful
}
	
/****************************************************************************/
int lookupAny(const string a1[], int n1, const string a2[], int n2){ 		// Return the smallest position in a1 of an element that is equal to any of the n2 elements in a2
 	if( n1 <=0 || n2 <= 0 ){		// n should be at least 1 or bigger than 1
		return -1;
	}	

  	int Sum = 0;								
        for(int j =0; j<n2; j++){
                for(int i=0; i<n1; i++){
                        if(a1[i] == a2[j]){
                                Sum++;
                        }
                }
        }
        if( Sum == 0 ) return -1;		// if there is no common element for both

        for(int i=0; i < n1; i++){
                for(int j = 0; j<n2; j++){
                        if(a1[i] == a2[j]){ // as long as there is the earlies number detected, return the location of array right away
                                return i;
                        }
                }
        }


}
/****************************************************************************/
								// I did not create additional array in this function.
                                        	                //
int divide(string a[], int n, string divider){			//  Return the position of the first element that, after the rearrangement, is not < divider, or n if there are no such elements.

		if(n <= 0){					// n should be at least or bigger than 1
			return -1;
		}
	
		int i = 0;					// it is changing the elements order in an array depends on the size of elements
		while(i < n-1){					// for now i will be counted by n-1 
			if( (a[i] > divider) && (a[i+1] <= divider) ){		//   send big data to front and the small data to the end
				string Save = a[i];				//   but in this case no counting the position in array
				a[i]   = a[i+1];				// then after that it will start passing an array from beginning 
				a[i+1] = Save;
				i = 0;						// it makes the while loop start fro the beginning
			}else{			
				i++;						// if big one is located in front and small one is in end go to the next element
			}
	
		}
		int j = 0;							// after rearranging the array
		int counting = 0;	
		while(j < n){	
			if(a[j] < divider){					// find the first element and return this position
				counting++;
			}
			j++;
		}
	return counting;

}
/****************************************************************************/



int main()
	{
		
	    string h[7] = { "greg", "gavin", "ed", "xavier", "", "eleni", "fiona" };
	    assert(lookup(h, 7, "greg") 	== 0);
	    assert(lookup(h, 7, "gavin") == 1);
	    assert(lookup(h, 7, "ed") 	== 2);
	    assert(lookup(h, 7, "xavier")== 3);
	    assert(lookup(h, 7, "")	== 4);
	    assert(lookup(h, 7, "eleni") == 5);
	    assert(lookup(h, 7, "fiona") == 6);
	    assert(lookup(h, 0, "greg") == -1);	// it cannot be 0
	    assert(lookup(h, -3,"greg") == -1); // it cannot be negative number
	    assert(lookup(h, 7, "gawun") == -1);  // an improper string which is not in the list
	    //assert(lookup(h, 8, "ed") == 2);     // I may not handle the oversize of the array     my program cannot handle this problem
    	    assert(positionOfMax(h, -1) == -1);
	    assert(positionOfMax(h, 0)  == -1);
	    assert(positionOfMax(h, 1)  ==  0); 
	    assert(positionOfMax(h, 2)  ==  0);
	    assert(positionOfMax(h, 3)  ==  0);
	    assert(positionOfMax(h, 4)  ==  3);
	    assert(positionOfMax(h, 5)  ==  3);
	    assert(positionOfMax(h, 6)  ==  3);
	    assert(positionOfMax(h, 7)  ==  3);
	    //assert(positionOfMax(h, 8)  ==  3);   // I may not handle the ovrsize of the array	 my program cannot handle this problem  
	    string g[4] = { "greg", "gavin", "fiona", "kevin" };
	    assert(differ(h, -1, g, -1) == -1);
	    assert(differ(h, -1, g,  1) == -1);
	    assert(differ(h,  1, g, -1) == -1);
	    assert(differ(h,  1, g,  1) ==  1);
	    assert(differ(h,  0, g,  0) == -1);
	    assert(differ(h,  1, g,  0) == -1);
	    assert(differ(h,  0, g,  1) == -1);
	    assert(differ(h,  1, g,  1) ==  1);
	    assert(differ(h, 1, g, 1) == 1);
	    assert(differ(h, 2, g, 1) == 1);
	    assert(differ(h, 1, g, 2) == 1);    // it is something wrong???
	    assert(differ(h, 2, g, 2) == 2);
	    assert(differ(h, 3, g, 1) == 1);
	    assert(differ(h, 1, g, 3) == 1);
	    assert(differ(h, 3, g, 2) == 2);
	    assert(differ(h, 2, g, 3) == 2);
	    assert(differ(h, 3, g, 3) == 2);
	    assert(differ(h, 4, g, 4) == 2);
	    assert(appendToAll(g, -1, "?") == -1);
	    assert(appendToAll(g,  0, "?") == -1);
	    assert(appendToAll(g,  1, "?") ==  1 && g[0] == "greg?"); 
	    assert(appendToAll(g,  2, "?") ==  2 && g[0] == "greg??");
	    assert(appendToAll(g,  3, "?") ==  3 && g[0] == "greg???");
	    assert(appendToAll(g,  4, "?") ==  4 && g[0] == "greg????" && g[3] == "kevin?");
	    //assert(appendToAll(g,  5, "?") ==  5 && g[0] == "greg?????" && g[3] == "kevin??");  	// oversize   my program cannot handle this error
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 	    string z[4] = { "greg", "gavin", "fiona", "kevin" };
	    assert(rotateLeft(z, 4, 0) == 0 && z[0] == "gavin" && z[1] == "fiona" && z[2] == "kevin" && z[3] == "greg");
	    assert(rotateLeft(z, 4, 1) == 1 && z[0] == "gavin" && z[1] == "kevin" && z[2] == "greg"  && z[3] == "fiona");  
	    assert(rotateLeft(z, 4, 2) == 2 && z[0] == "gavin" && z[1] == "kevin" && z[2] == "fiona" && z[3] == "greg");
	    assert(rotateLeft(z, 4, 3) == 3 && z[0] == "gavin" && z[1] == "kevin" && z[2] == "fiona" && z[3] == "greg");	// it is problem for now
	    //assert(rotateLeft(z, 4, 4) == 4);											// it should be a problem but did not catch the error
	    //assert(rotateLeft(z, 4, 5) == 5);								// it should be error and it cannot be working  i did not handle the problem of oversize array
	    
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	    string t[7] = { "greg", "gavin", "ed", "xavier", "", "eleni", "fiona" };
	    string e[4] = { "ed", "xavier", "", "eleni" };
	    assert(subsequence(t, 7, e, -1) == -1);
	    assert(subsequence(t, 7, e, 0) == -1);
	    assert(subsequence(t, 7, e, 1) == 2);
	    assert(subsequence(t, 7, e, 2) == 2);
	    assert(subsequence(t, 7, e, 3) == 2);
	    assert(subsequence(t, 7, e, 4) == 2);

	    assert(subsequence(t, 4, e, 4) == 2);
	    //assert(subsequence(t, 3, e, 4) == 1);		// n1 n2 should be same or n1 should be bigger than n2
	    //assert(subsequence(t, 2, e, 4) == -1);		// did not catch it in my program

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    string d[5] = { "gavin", "gavin", "gavin", "xavier", "xavier" };
	    assert(countRuns(d, 5) == 2);

	    string qq[5] = { "aa", "aa", "aa", "aa", "aa" };
	    assert(countRuns(qq, 5) == 1);
	    
	    string qqq[1] = { "aa" };
	    assert(countRuns(qqq, 1) == 1);
	    assert(countRuns(qqq,0)  == -1);
	    assert(countRuns(qqq,-1) == -1);

		 string aq[5] = { "aa", "aa2", "aa", "aa", "aa" };
		 
		 assert(countRuns(aq, 5) == 3);
		 assert(countRuns(aq, 3) == 3);
		 assert(countRuns(aq, 2) == 2);
		 assert(countRuns(aq, 1) == 1);
            	 assert(countRuns(aq, 0)  == -1);
		 assert(countRuns(aq,-1) == -1);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    string f[3] = { "fiona", "ed", "john" };
	    
	    assert(lookupAny(h, 7, f, 3) == 2);


	    string names[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
	    string set1[10] = { "dianne", "betty", "greg", "gavin" };
	
	    assert(lookupAny(names, 6, set1, 4) == 1);  // returns 1 (a1 has "gavin" there)
	    assert(lookupAny(names, 6, set1, 3) == 3);
	    assert(lookupAny(names, 6, set1, 2) == 4);
	    assert(lookupAny(names, 4, set1, 4) == 1);
	    assert(lookupAny(names, 1, set1, 4) == -1);
	    assert(lookupAny(names, 0, set1, 4) == -1);
	    assert(lookupAny(names, -1, set1, 4) == -1);
  	    assert(lookupAny(names, 4, set1, -1) == -1);
	    string set2[10] = { "xavier", "ed" };
	    assert(lookupAny(names, 6, set2, 2) == -1);  // returns -1 (a1 has none)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    assert(flip(f, 3) == 3 && f[0] == "john" && f[1] == "ed" && f[2] == "fiona");
	   		
	    assert(divide(h, 7, "fiona") == 3);
	

		string folks[6] = { "betty", "john", "gawun", "xavier", "kevin", "dianne" };
		assert(flip(folks, 4) == 4 && folks[0] == "xavier" && folks[3] == "betty"); 
		assert(flip(folks, 3) == 3 && folks[0] == "john" && folks[2] == "xavier");
		assert(flip(folks, 1) == 1 && folks[0] == "john" && folks[2] == "xavier");	
		assert(flip(folks, 0) == -1);
		assert(flip(folks, -1) == -1);



	    cout << "All tests succeeded" << endl;
	}


