#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;


const int MAX_WORD_LENGTH = 20;


// This function is receiving three arrays. 
// word1 and word2 arrays are the arrays and each of them is the collection of words. separation is also an array which has the maximum distance between word to word.
// This function is checking each of arrays and if any element is improper, it is to remove the element.
// Each of elements for word1 and word2 should be alphabet but not anyothers.
// Each of elements in separation cannot be negative value.
// nPattern is nevigating how many elements of each arrays would be to be used


int makeProper(char word1[][MAX_WORD_LENGTH+1], 		
	       char word2[][MAX_WORD_LENGTH+1],			
	       int  separation[],				
	       int  nPatterns)				
{		
 
  int sum = nPatterns;					// sum is for returning the value.  If one set of elements would be deleted, the value of sum would be changed.
  int i = 0;
	while( i < sum ){ 				// This while loop is to check invalid value in a word1 array		
		int j1 = 0;
		while( j1 < strlen(word1[i]) ){
			if( !isalpha(word1[i][j1]) ){	// and in word1 array, it is catching any improper format of elements and delete it
			
			   for(int x = i; x < (sum-1); x++){		//when delete the value, delete all corresponded elemets in each array
				strcpy(word1[x], word1[x+1]);		
                                strcpy(word2[x], word2[x+1]);
				separation[x]= separation[x+1];			
				
			   }
			     sum = sum - 1;				// this is for returning value
			     j1 = strlen(word1[i]); 			// it will enforce this while loop(j1) to go out;  
			     i--;					// i-- is making...to start to check all element from the beginning.
			}						
			else{
			  word1[i][j1] = tolower(word1[i][j1]);		// if character is alhpabet, then change it to lower case
			  j1++;
			  
			}
			
		}
		i++;
	}

	i = 0;
	while( i < sum ){       				// This is while loop to check invalid value in a word2 array. 
                int j2 = 0;
                while( j2 < strlen(word2[i]) ){
                        if( !isalpha(word2[i][j2]) ){		// if there is non alphabet noticed, remove all corresponded elements in each array

                           for(int x = i; x < (sum-1); x++){
				strcpy(word1[x], word1[x+1]);
                                strcpy(word2[x], word2[x+1]);
                                separation[x]= separation[x+1];                        

                           }
                             sum = sum - 1;
                             j2 = strlen(word2[i]);	 	// it will enforce this while loop(j1) to go out;
                       	     i--;	
		       	}
                        else{
                          word2[i][j2] = tolower(word2[i][j2]);
                          j2++;
			  
                        }
			
                }
		i++;
                
        }
	
	i = 0;
	while( i < sum ){						// this while loop is to check a separation array; it is catching negative number and delete it
                        if( separation[i] < 0 ){
                           	for(int x = i; x < (sum-1); x++){
                               	 strcpy(word1[x], word1[x+1]);
                               	 strcpy(word2[x], word2[x+1]);
                               	 separation[x]= separation[x+1];                        // delete
                           	}
                          sum = sum - 1;
                          i--;
                        }
                
                i++;

        }
///////////////////////////////////////////////////////////////////

	
	int q = 0;

		while(q < sum){
			for(int p = q+1; p < sum; p++){				// This is checking same elements in word1 and word2.
				if( ( strcmp(word1[p], word1[q]) == 0 && strcmp(word2[p], word2[q]) == 0) || 
				    ( strcmp(word1[p], word2[q]) == 0 && strcmp(word2[p], word1[q]) == 0) )
				{
					if(separation[p] < separation[q]){	// also, checking corresponded separation value and replace the small value with bigger one
						separation[p] = separation[q];
					}
					for(int x = p; x < (sum-1); x++){
                                		strcpy(word1[x], word1[x+1]);
                                		strcpy(word2[x], word2[x+1]);
                                		separation[x] = separation[x+1];                        // delete

                           		}		
                       		        sum = sum - 1;
					q--;
				}
			}
		  q++;
		}

	return sum;

}

// This function is checking the pattern of a string and to find any set to have a given pattern
// There are 5 of paramters, document[] is to receive a string, word1 and word2 are an array of words, separation is an array and it is a  pattern of each set 
// nPatterns is to nevigate the number sets to be concerned.
// Once this function find a set  and pattern  to be applied in this function and checking others, it will count one regardless of counting multiple  times (repeated one).

int rate(const char document[],
         const char word1[][MAX_WORD_LENGTH+1],
         const char word2[][MAX_WORD_LENGTH+1],
         const int  separation[],
         int nPatterns)
{
        char changed_sentence[200];			// copy the parameter string and the original string would be modified in his new string
							// leave characters and spaces but delete other characters
        int i = 0;
        int j = 0;
        while(i < strlen(document)){    // ===copy a string into new string delete non alphabet character except space
                if(isalpha(document[i])){
                        changed_sentence[j] = tolower(document[i]);
                        j++;
                }else if(document[i] == ' '){
                        changed_sentence[j] = document[i];
                        j++;
                }
                i++;
        }
                changed_sentence[j] = '\0';		// I added null character just in case
////////////////////////////////////////////////////////////////////////////////
	int sum = nPatterns;
	int   x = 0;
	int Total = 0;
	while( x  < sum ){
		int start_pattern_point = -1;			// these two integer would be nevigating, the lacation of a pairs 
		int end_pattern_point = -1;			//  this is used in counting their separation
								// after the process, if one of them is still -1, then the counted value is zero
		i = 0;

		while( i < strlen(changed_sentence) )
		{
			if(word1[x][0] ==  changed_sentence[i] && (changed_sentence[i-1] == ' ' || i ==0)){	// this is finding a word in word1 array
				int Checking1 = 0;						
                                int j = 0;
                                while(j < strlen(word1[x]))
				{
                                        int k = j+i;					// k is the vale for word1 character checking but it will not affect the value of i
                                        if(word1[x][j] == changed_sentence[k])		 // if they are exactly same word
					{						// then Checking1 value wil be same with j
                                                Checking1++;
                                        }
                                   j++;
                                }
                                if( Checking1 == strlen(word1[x]) && !isalpha(changed_sentence[j+i]))
				{
                                  i = i+j;						// this value is indicating a space character 
                                  start_pattern_point = i-1;				// but start_pattern_pointer is indicating the end of character in a target word.
				}
			}

			if(word2[x][0] == changed_sentence[i] && (changed_sentence[i-1] == ' ' || i ==0)){       // this is finding a word in word2 array
                                int Checking2 = 0;								  // but same algorithm with upper
                                int j1 = 0;
                                while(j1 < strlen(word2[x])){
                                int k = i + j1;
                                        if(word2[x][j1] == changed_sentence[k]){
                                                Checking2++;
                                        }
                                j1++;
                                }


                                if( Checking2 == strlen(word2[x]) && !isalpha(changed_sentence[j1+i])){
                                  i = i+j1;
                                  end_pattern_point = i-1;
                                }
                        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			if(end_pattern_point != -1 && start_pattern_point != -1){  	// as long as this function find a pattern.
											// it means end & start pattern pointer have more than 1
                        	int counting_number_of_space = 0;			
                        	int big;						//a word which is located in ealier order of then string will be called as  big
                        	int small;						//a word which is located in later order of the string will be called as small


				if(end_pattern_point > start_pattern_point){		
                                	small = start_pattern_point;			// only differnce (between this if and below else if) is this line
                                	big  = end_pattern_point;			// 

				      	for(int i = small; i < big; i++ ){
                                        	if(isalpha(changed_sentence[i]) && changed_sentence[i+1] == ' '){	// space and one character will be counted with one
                                           		counting_number_of_space++;
                                       		}
                                	}

                               		 counting_number_of_space = counting_number_of_space -1;			// delete 1 because ... #ofspace-1 =  separation

                                	if(counting_number_of_space <= separation[x]){
                                       		 Total++;
						i = strlen(changed_sentence);			// this is enforcing to go out this loop
                                	}
                        	}


				else if(end_pattern_point < start_pattern_point){		
                                	big   = start_pattern_point;			//// only differnce (between this if and below else if) is this line
                                	small = end_pattern_point;

                                	for(int i = small; i <= big; i++ ){
                                        	if(isalpha(changed_sentence[i]) && changed_sentence[i+1] == ' '){
                                           		counting_number_of_space++;
                                        	}
                                	}

					counting_number_of_space = counting_number_of_space -1;

					if(counting_number_of_space <= separation[x]){
                                        	Total++;
						i = strlen(changed_sentence)-1;
                                	}

                		}

			}
		 i++;
		}
	  x++;
	}
	return Total;
}


int main(){
	
	const int TEST1_NRULES = 4;
cout << "---------------------------------------------testing--------------------------------------------" << endl;

        cout << "mMAD(1)      -deranged(3)  -nefarious(0)   ve-(12)" << endl;
        cout << "scienTist(1)  Robot(3)    -PLOT(0)        Mad(12)" << endl;
            char test8w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {"mMAD",     "-deranged","-nefarious","ve-"};
            char test8w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {"scienTist","Robot",    "-PLOT","Mad"};
            int  test8dist[TEST1_NRULES] =                   {1, 3, 0, 12};

         number = makeProper(test8w1, test8w2, test8dist, TEST1_NRULES);
        cout << "The return value is "<<  number << endl;
        for(int i = 0; i < number; i++){
          cout << " " << test8w1[i] << "&" << test8w2[i] << "("<< test8dist[i] << ") ";

        }
        cout << endl;

cout << "---------------------------------------------testing--------------------------------------------" << endl;
	const int TEST2_NRULES = 4
        
	cout << "-mMAD(1)      -deranged(3)  -nefarious(0)   ve(12)" << endl;
        cout << "-scienTist(1)  Robot(3)    -PLOT(0)        Mad(12)" << endl;
            char test9w1[TEST2_NRULES][MAX_WORD_LENGTH+1] = {"-mMAD",     "-deranged","-nefarious","ve"};
            char test9w2[TEST2_NRULES][MAX_WORD_LENGTH+1] = {"-scienTist","Robot",    "-PLOT","Mad"};
            int  test9dist[TEST2_NRULES] =                   {1, 3, 0, 12};

         number = makeProper(test9w1, test9w2, test9dist, TEST2_NRULES);
        cout << "The return value is "<< number << endl;
        for(int i = 0; i < number; i++){
          cout << " " << test9w1[i] << "&" << test9w2[i] << "("<< test9dist[i] << ") ";

        }
        cout << endl;

cout << "---------------------------------------------testing--------------------------------------------" << endl;
	 const int TEST10_NRULES = 8;

        cout << "mad(1)        derange(3)    NEFARIOUS(0)    half-writted(2)    robot(1)     plot(0)      have(12)      NeFaRiOuS(0)" << endl;
        cout << "scienTist(1)  Robot(3)      PLOT(0)         assistant(2)       deranged(1)  Nefarious(0) mad(12)       pLot(0) " << endl;
            char test10w1[TEST10_NRULES][MAX_WORD_LENGTH+1] = {"mad", "derange","NEFARIOUS","half-writted"," robot","plot","have","NeFaRiOuS"};
            char test10w2[TEST10_NRULES][MAX_WORD_LENGTH+1] = {"scienTist","Robot","PLOT","assistant","deranged","Nefarious","mad","pLot"};
            int  test10dist[TEST10_NRULES] =                   {1,3,0,2,1,0,12,0};

         number = makeProper(test10w1, test10w2, test10dist, TEST10_NRULES);
 	 cout << "The return value is "<< number << endl;
        for(int i = 0; i < number; i++){
          cout << " " << test10w1[i] << "&" << test10w2[i] << "("<< test10dist[i] << ") ";

        }
        cout << endl;
cout << "---------------------------------------------testing--------------------------------------------" << endl;
         const int TEST11_NRULES = 7;

        cout << "mad(1)        derange(3)    half-writted(2)    robot(1)     plot(0)      have(12)      NeFaRiOuS(0)" << endl;
        cout << "scienTist(1)  Robot(3)      assistant(2)       deranged(1)  Nefarious(0) mad(12)       pLot(0) " << endl;
            char test11w1[TEST11_NRULES][MAX_WORD_LENGTH+1] = {"mad", "derange","half-writted"," robot","plot","have","NeFaRiOuS"};
            char test11w2[TEST11_NRULES][MAX_WORD_LENGTH+1] = {"scienTist","Robot","assistant","deranged","Nefarious","mad","pLot"};
            int  test11dist[TEST11_NRULES] =                   {1,3,2,1,0,12,0};

         number = makeProper(test11w1, test11w2, test11dist, TEST11_NRULES);
         cout << "The return value is "<< number << endl;
        for(int i = 0; i < number; i++){
          cout << " " << test11w1[i] << "&" << test11w2[i] << "("<< test11dist[i] << ") ";

        }
        cout << endl;




	    const int TEST2_NRULES = 4;
       
     	    char test18w1[TEST2_NRULES][MAX_WORD_LENGTH+1] = {
                "mad",       "deranged", "nefarious", "have"
            };
            char test18w2[TEST2_NRULES][MAX_WORD_LENGTH+1] = {
                "scientist", "robot",    "plot",      "mad"
            };
            int test18dist[TEST2_NRULES] = {
                1,           3,          0,           12
            };
	    
            assert(rate("The mad UCLA scientist unleashed a deranged evil giant robot.",
	 			test18w1, test18w2, test18dist, TEST2_NRULES) == 2);
            assert(rate("The mad UCLA scientist unleashed    a deranged robot.",
			test18w1, test18w2, test18dist, TEST2_NRULES) == 2);
            assert(rate("**** 2018 ****",
			test18w1, test18w2, test18dist, TEST2_NRULES) == 0);
            assert(rate("  That plot: NEFARIOUS!",
			test18w1, test18w2, test18dist, TEST2_NRULES) == 1);

            assert(rate("deranged deranged robot deranged robot robot",
				test18w1, test18w2, test18dist, TEST2_NRULES) == 1);
            assert(rate("That scientist said two mad scientists suffer from deranged-robot fever.",
			test18w1, test18w2, test18dist, TEST2_NRULES) == 0);
	
	    assert(rate("scientist `mad",
                        test18w1, test18w2, test18dist, TEST2_NRULES) == 1);
	    assert(rate("mad  `1scientists",
                        test18w1, test18w2, test18dist, TEST2_NRULES) == 0);
	    assert(rate("scientist i s mad",
                        test18w1, test18w2, test18dist, TEST2_NRULES) == 0);
	    assert(rate(" deranged mad scientist robot scientist root scientist nefarious plot  mad have", test18w1, test18w2, test18dist, TEST2_NRULES) == 4);
	    
	    assert(rate(" deranged. mad ,  , , scientist robot scientist root scientist nefarious plot  mad have", test18w1, test18w2, test18dist, TEST2_NRULES) == 4);

	    assert( rate(" deranged  m ad scientist robot scientist root scientist nefarious plot  mad have", test18w1, test18w2, test18dist, TEST2_NRULES) == 3);
	    
	   
            cout << "*************************************************** All tests succeeded *****************************************" << endl;
}
