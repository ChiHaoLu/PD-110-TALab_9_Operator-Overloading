/*------------------------------------- Reference -------------------------------------*/
//  PD-110 TALab_9_Operator Overloading
//  Author: b08303113 ChiHaoLu
// 	Discussion with: 
//  2021/12/16 13:41
/*-------------------------------------------------------------------------------------*/

#include<iostream>
#include <iomanip>
using namespace std;
#include <cmath>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>

/*------------------------------------- Construct the Data Structure. --------------------*/

class Complex {
private:
    int real;
	int imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
      
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() { cout << real << " + " << imag << "i" << endl; }
};

class PhoneNumber {
//  +886-(2)-3366-3366
friend ostream &operator<<( ostream&, const PhoneNumber & );
friend istream &operator>>( istream&, PhoneNumber & );

private:
    int International_CallPrefixes;
	int Area_Code;
	int Exchange_NUM;
	int Line_NUM;

};

ostream &operator<<( ostream &output, const PhoneNumber &num ){
	
	output << "+" << num.International_CallPrefixes << "-(" << num.Area_Code << ")-"<< num.Exchange_NUM << "-" << num.Line_NUM;
	
	return output;
}

istream &operator>>( istream &input, PhoneNumber &num ){
	
	input.ignore(); // pass the "+" 
	
	char* temp = new char[10];
	input >> setw(4) >> temp;
	num.International_CallPrefixes = atoi(temp);
	
	input.ignore(2); // pass the "-(" 
	input >> setw(2) >> temp;
	num.Area_Code = atoi(temp);
	
	input.ignore(2); // pass the ")-" 
	input >> setw(5) >> temp;
	num.Exchange_NUM = atoi(temp);
	
	input.ignore(); // pass the "-" 
	input >> setw(5) >> temp;
	num.Line_NUM = atoi(temp);
	
	return input;
}

/*---------------------------------------------------------------------------------------*/

int main()
{	
	// Complex
	
//	int i = 0;
//	int j = 0;
//	cin >> i >> j;
//    Complex c1(i, j);
//	cin >> i >> j;
//    Complex c2(i, j);
//
//    Complex c3 = c1 + c2; // An example call to "operator+"
//    c3.print();
    
    // PhoneNumber

//    PhoneNumber NTU_number;
//    cout << "Enter phone number in the form +886-(2)-3366-3366:\n";
//    cin >> NTU_number;
//    cout << "\nThe phone number entered was: " << NTU_number << endl;
}
