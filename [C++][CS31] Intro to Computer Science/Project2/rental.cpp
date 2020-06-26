#include<iostream>
#include<string>
using namespace std;

int main(){

    cout << "Odometer at start: ";
    int Odometer_at_start;      // Odometer is an integer
    cin >> Odometer_at_start;

    if(Odometer_at_start < 0){
        cout << "---" << endl;
        cout << "The starting odometer reading must be nonnegative." << endl;
        return 1;
    }

    cout << "Odometer at end: ";
    int Odometer_at_end;        // Odometer is an integer
    cin >> Odometer_at_end;

    if(Odometer_at_end < Odometer_at_start){
        cout << "---" << endl;
        cout << "The final odometer reading must be at least as large as the starting reading." << endl;
        return 1;
    }

    cout << "Rental days: ";
    int Rental_days;
    cin >> Rental_days;        //rental days is an integer

    if(Rental_days <= 0){
         cout << "---" << endl;
         cout << "The number of rental days must be positive." << endl;
         return 1;
    }
    cin.ignore(10000,'\n');

    cout << "Customer name: ";
    string Customer_name;
    getline(cin,Customer_name);

    if(Customer_name.empty()){   // Customer_name.empty() is same with Customer_name == ""
        cout << "---" << endl;
        cout << "You must enter a customer name." << endl;
        return 1;
    }

    cout << "Luxury car? (y/n): ";
    string Luxury_car;
    getline(cin,Luxury_car);

    if(Luxury_car != "y" && Luxury_car != "n"){ // If user inserts some weird input (not y and not  n)
        cout << "---"<< endl;
        cout << "You must enter y or n." << endl;
        return 1;
    }

    cout << "Month (1=Jan, 2=Feb, etc.): ";
    int Month;
    cin >> Month;
    if(  Month < 1 || Month > 12){
       cout << "---" << endl;
       cout << "The month number must be in the range 1 through 12." << endl;        // Question here for if loop
       return 1;
    }


    int Distance = ((Odometer_at_end) - (Odometer_at_start));
    double Total = 0;      // I defined it with double because the calculation is dealt with some double numbers(such as 0.27 or 0.21).

    if(Luxury_car == "y"){          // setting the car fee in the beginning
        Total = Total + 61*(Rental_days);  // when typing y
    }else{
        Total = Total + 33*(Rental_days);  // when typing n
    }

    if( Distance <= 100){                                  // when user typed less than 100 for the distance
        Total = Total + (Distance * 0.27);
    }else if (Distance > 100 && Distance <= 400 ){                          // when user typed some number which is bigger than 100 and less than 400
        if(Month == 12 || Month == 1 || Month == 2 || Month == 3){
            Total = Total + (100 * 0.27) + ((Distance - 100) * 0.27);    // distance is over 100. calculate a fee for the distance 100 first
        }else{                                                                      //  find some remained distance and calculate the fee.   adding them each other
            Total = Total + (100 * 0.27) + ((Distance - 100) * 0.21);
        }
    }else{                                                                      // when Distance is bigger than 400
        if(Month == 12 || Month == 1 || Month == 2 || Month == 3){
            Total = Total + (100 * 0.27) + ((300) * 0.27) + (Distance - 400) * 0.19;     // it is over 400 so that dividing three steps
        }else{                                                                           // 100 , 100-400, and over 400. for distance
            Total = Total + (100 * 0.27) + ((300) * 0.21) + (Distance - 400) * 0.19;
        }
    }
    cout.setf(ios::fixed);                     // exactly two digits to the right of the decimal point
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "---" << endl;                                                                  // is it required to insert for the output
    cout << "The rental charge for " << Customer_name << " is $" << Total << endl;
    return 1;
}
