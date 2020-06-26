#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/****************************************************************************/
int appendToAll(string a[], int n, string value){	// append value to the end of each of n elements
	if(n < 0){			// if n is negative, return -1   also, n cannot be zero; it should be positive
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
	if(pos >= n){
		return -1;
	}
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
	if( n < 0){				// n should be at least 1
		return -1;
	}
	if(n ==0 )return 0;
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
		if( n < 0){					// n should be at least 1
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
	if( n1 < 0 || n2 < 0 ){					// each of them should be at least 
		return -1;
	}
	if( n1 ==0 || n2 == 0) return 0;	
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
int subsequence(const string a1[], int n1, const string a2[], int n2){

        if( n1 < 0 || n2 < 0){
                return -1;
        }
        if(n1 == 0 || n2 == 0){
                return 0;
        }

        int SaveLoc;
        int i1 = 0;
        int Counting = 0;


        while( i1 < n1){

        int i2;
                if( a1[i1] == a2[0]){
                    SaveLoc = i1; // this value is for return
                        for( i2=0; i2<n2; i2++){
                                if(a1[i1] == a2[i2]){
                                  i1++;
                                  Counting++;

                                }else{
                                  i2 = n2;  //go out this for loop
                                  Counting = 0;
                                }
                        }

                                if( Counting == n2 )return SaveLoc;
                i1 = SaveLoc;
                }
        i1++;
        }
        return 0;

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






