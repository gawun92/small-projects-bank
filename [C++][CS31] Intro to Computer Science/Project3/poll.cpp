#include <iostream>
#include <cassert>
#include <cctype>
#include <cstdio>
using namespace std;


	bool isValidUppercaseStateCode(string stateCode)
	{
    		const string codes =
      		  "AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
      		  "LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
       		 "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    		return (stateCode.size() == 2  &&
 		    stateCode.find('.') == string::npos  &&  // no '.' in stateCode
       		     codes.find(stateCode) != string::npos);  // match found
	}
		
bool hasProperSyntax(string pollData){  //  This is for checking a string  ..whether it has proper syntax or not 
       					//  if input is valid and proper, it is returning true
					//  if input is invalid and not proper, it is returning false
					//  This function is receiving a string and this string will be checked by this function

                for(int i =0; i < pollData.size(); i++){     //  from 0 to the end of the string
			pollData[i] = toupper(pollData[i]);  //change all characters to uppercase
                                if(pollData[i] == ' '){      // if there is space detected, the string is not proper 
                                        return false;        // This is finding space into string and sorting it as an invalid value
                                }
			       	if( !isdigit(pollData[i]) && !isalpha(pollData[i]) ){		// if a passing character is not number and alphabet
						if(pollData[i] != ','){				//                                  all other cases except ,  
							return false;	 			//  invalid string
						}
				}
                }  	// finish the for loop here

        int j=0;				// this j will be used in while loop and it is declared from here
	if(pollData == "") return true;		// if it is an empty string, just telling that it is true .
	while( j != pollData.size()){		

			if(j == 0){ 							    // this is checking the most front and it should be only statecode except empty string
				string StateTesting = ""; 			 	    // to check the statecode, copy two characters into a new string
				pollData[0]=toupper(pollData[0]);				
				pollData[1]=toupper(pollData[1]);		 	    // made an empty string for the new string and inserted two chars
				StateTesting = StateTesting + pollData[0] + pollData[1];	
				
				if(!isValidUppercaseStateCode(StateTesting)){		// checking whether the new string(statecode) is valid or not
				      	return false;					// if it is not valid, then return false
				}
				
				j = j+2; // there is no problem detected, skip the state code
			
				if(j == pollData.size()) return true; 	 	// if the line is finished

				if( !isdigit(pollData[j]) && pollData[j] != ','){  // it should be number or comma, if not then it is not valid
				return false;
				}	
			}
		

		if(pollData[j] == ','){							
			j++; 					// skip the char and go to a char (for statecode) 
				if(j == pollData.size()) return false;	// if the string is finished with ,   then it is wrong
			string StateTesting = "";
                                pollData[j] = toupper(pollData[j]);
                                pollData[j+1] = toupper(pollData[j+1]);				// two chars and making string to check statecode
                                StateTesting = StateTesting + pollData[j] + pollData[j+1];

                                if(!isValidUppercaseStateCode(StateTesting)){
                                        return false;
                                }
                                j = j+2; 		// if it is a valid statecode, then go skip the statecode 

				 if(j == pollData.size()) return true;	// if the end of string, end the function with valid

                                if( !isdigit(pollData[j]) && pollData[j] != ','){  // after statecode, it should be digit or ,
                                return false;					   // if not it is invalid
                                }

					
                            

			
		}else if(isdigit(pollData[j])){					// if a char is number then passing this 
			if( isdigit(pollData[j]) && isdigit(pollData[j+1]) ){ 		
				j = j+2;    // example 13D  //  go to next next and it will be indicating group (char D)
			}
			else if( isdigit(pollData[j]) && isalpha(pollData[j+1]) ){
			  	j = j+1;   // example 1D    // when there is one digit and a group code
			}									//  when j is a digit but j+1 is not digit	
                        else{
				return false; // when there are more than three digits, it should be false    // ex) 1234D is not valid
			}
                         
	 			
		        if( !isalpha(pollData[j])){		// a group character should be alphabet
                            return false;
                        }else{     				// if it is alphabet
                          j++;  				// passing
			  	if( isalpha(pollData[j]) ) return false;	// if the next of the group char is not alphabet, it is not valid
                        }

		}
	}
	return true;	// if all passing through this while loop, it concludes that a string is valid
}	
	
	

	int tallySeats(string pollData, char party, int& seatTally)
	{
		if(pollData == ""){	// if empty string in parameter, it returns 0
			seatTally = 0;
			return 0;
		}
	
		if(!hasProperSyntax(pollData) || !isalpha(party)){  // it will catch both not proper syntax and not alphabet party
	  	
	   		if(!hasProperSyntax(pollData) && !isalpha(party)){ //If either of the preceding situations occur, seatTally must be left unchanged. 
				seatTally = seatTally; // is that for ... seatTally not to be changed   
			     	return 1;
			}   
			else if(!hasProperSyntax(pollData)) return 1; 			//the parameter pollData is not a poll data string, this function return 1
			else return 2;							// the parameter party is not a letter, this function returns 2
		} // out of this if  -> there is no error.
		
		//
		//If neither of those situations occurs, then the function returns 0 after setting seatTally to the total number of seats that pollData predicts the party indicated by party will win.
		//
		for(int i=0; i< pollData.size(); i++){
			pollData[i] = toupper(pollData[i]);
		}   //change then all to upper case   -> i think it is not working well

		int sum=0;	// this sum will be counting all number		
		int j=0;

		while (j != pollData.size()){     //statecodes is not really important here because it is checking the sum of part
			if(j == 0){ // passing through the first state codes 
				j = j+2;	// do not consider them.
			}else if(pollData[j] == ','){	
				j = j+3;  // skip ,  and statecodes
			}else if (isdigit(pollData[j])){  
				j++;
			}else{		
				

			int x;
			string TmpNum;
					if(tolower(party) == pollData[j] || toupper(party) == pollData[j]){   // this is checking the partycode and if it is
						if(isdigit(pollData[j-2]) && isdigit(pollData[j-1])){         // if two characters are all numbers
							TmpNum = "";
							TmpNum = TmpNum + pollData[j-2] + pollData[j-1]; // make it a new string to make digits number
							 x = stoi(TmpNum);				// making a string to an int format
							sum = sum + x; 					// adding this number to sum
							
						}else{ 							 // only  when  pollData[j-1] is digit not [j-2]
							TmpNum = "";  					 /// make a string with number.
							TmpNum = TmpNum + pollData[j-1];
							x = stoi(TmpNum);    				// make an integer with number in string
							sum = sum + x;					// adding into sum
						
						}

			
				      }
					j++; // j was a group code and go to the next
		}  // the end of the while loop
			

	}
		seatTally = sum;  		// if while loop is done then put the value of sum into seatTally
		return 0;   			// return zero since it is successful
	}

int main()
	{




    assert(!hasProperSyntax("ZZ"));

    assert(!hasProperSyntax("CA-1d"));

    assert(!hasProperSyntax("CA1-d"));

    assert(!hasProperSyntax("CA1d,wa1-d"));
    assert(!hasProperSyntax("CA1d-"));

      assert(!hasProperSyntax("CA1d-,wad"));


    assert(!hasProperSyntax("CA1d,wA-1d"));

    assert(!hasProperSyntax("CA1"));

    assert(!hasProperSyntax("CA3%,Wa12d"));

    assert(!hasProperSyntax("CA4 D"));

    assert(!hasProperSyntax("CAD"));

    assert(!hasProperSyntax("WA1R,CA123D"));

    assert(!hasProperSyntax("WA1R,CA1234D"));

    assert(!hasProperSyntax("CA 4R"));

    assert(!hasProperSyntax(",CA3D,Wa12R"));

    assert(!hasProperSyntax("CA3D,Wa12R,"));

    assert(hasProperSyntax("CT5D,NY9R17D1I,VT,ne3r00D"));


	


	    assert(hasProperSyntax("CT5D,NY9R17D1I,VT,ne3r00D"));
   	    assert(hasProperSyntax("Ca5d,Ny9r17r1i,VT,Ne3R00D"));
	    assert(hasProperSyntax("CT5a,NY9q17D1I,VT,ne3a00D"));   // 8a
	    assert(hasProperSyntax("CT,NY"));
	    assert(hasProperSyntax("CT,Ny,VT,ne3r01D"));
	    assert(hasProperSyntax(""));


	    assert(!hasProperSyntax("ZT5D,NY9R17D1I,VT,ne3r00D"));
	    	
	    assert(!hasProperSyntax("CTNY"));   // 8a
            assert(!hasProperSyntax("CT,"));
            assert(!hasProperSyntax("CT,Ny1,VT,ne3r01D"));
            assert(!hasProperSyntax(","));
		
	    assert(hasProperSyntax("MA9D,KS4R")  &&  hasProperSyntax("KS4R,MA9D"));                           //FAQ 6
	    assert(hasProperSyntax("MA9D,,KS4R") == hasProperSyntax("KS4R,,MA9D"));                           //FAQ 6


	    int seats;
	    seats = -999;    // so we can detect whether tallySeats sets seats
	    
	    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", 'd', seats) == 0  &&  seats == 22);
            
	    assert(tallySeats("Ca5d,Ny9r17d1i,VT,Ne3R00D", 'd', seats) == 0  &&  seats == 22);
            seats = -999;
	    assert(tallySeats("",'a',seats) == 0 && seats == 0);                                         // FAQ 5
	    assert(tallySeats("wa",'a',seats) == 0 && seats == 0);
	    assert(tallySeats("wa,ca",'a',seats) == 0 && seats == 0);
	    assert(tallySeats("CT5a,NY9q17D1I,VT,ne3a00D", 'a', seats) == 0  &&  seats == 8);
	    assert(tallySeats("CT,NY", 'a', seats) == 0  &&  seats == 0);
	    assert(tallySeats("CT,Ny,VT,ne3r01D", 'd', seats) == 0  &&  seats == 1);

	    seats = -999;    // so we can detect whether tallySeats sets seats
	    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", '%', seats) == 2  &&  seats == -999);    // part is not proper
	    assert(tallySeats("ZT5D,NY9R17D1I,VT,ne3r01D", 'd', seats) == 1  &&  seats == -999);  // string is not proper
	    assert(tallySeats("ZT5D,NY9R17D1I,VT,ne3r00D", '%', seats) == 1  &&  seats == -999);  // not proper party and string
	    assert(tallySeats("MA9D", '@', seats) == 2 && seats == -999);                                       //FAQ 4
	    assert(tallySeats("MA9@", '@', seats) == 1 && seats == -999);                                            //FAQ 4
  	    assert(tallySeats("MA9@", '@', seats) == 1 && seats == -999);                                           //FAQ 4
	   
	    cout << "All tests succeeded" << endl;
	}




















