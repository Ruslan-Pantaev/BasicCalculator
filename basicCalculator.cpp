/*
Author:	Ruslan Pantaev
Date:	10/27/2016
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio> //for system("cls"); clear screen
using namespace std;

ofstream fout; //for logging session
const int width = 15;

void printMenu();
int twoIntegers(double &operand1, double &operand2, char &mathFunc, double &result);
int reciprocal(double &operand1, double &result);
int factorial(double &operand1, double &result);
int sqRoot(double &operand1, double &result);
void header();

int main() {
	char mathFunc = ' ';
	char refresh = ' '; //could be any letter, except trailer value 'n'
	double 	op1, op2, result = 0.0;
	fout.open("mathData.txt");

	header(); //prints header for output and .txt log

	do {
		printMenu();
		cout << "Operation: ";
		cin >> mathFunc;

		switch(mathFunc) {
			case '+':
				twoIntegers(op1, op2, mathFunc, result);
				break;
			case '-':
				twoIntegers(op1, op2, mathFunc, result);
				break;
			case '*':
				twoIntegers(op1, op2, mathFunc, result);
				break;
			case '/':
				twoIntegers(op1, op2, mathFunc, result);
				break;
			case '%':
				twoIntegers(op1, op2, mathFunc, result);
				break;			
			case 'P':
				twoIntegers(op1, op2, mathFunc, result);
				break;
			case 'A':
				twoIntegers(op1, op2, mathFunc, result);
				break;
			case 'N':
				twoIntegers(op1, op2, mathFunc, result);
				break;
			case 'R':
				reciprocal(op1, result);
				break;
			case 'F':
				factorial(op1, result);
				break;
			case 'T':
				sqRoot(op1, result);
				break;
			case 'Q':
				return 0;
			default:
				break;
		}

		// prints to console, but also makes a mathData.txt log file

		if (mathFunc == 'R' || mathFunc == 'F' || mathFunc == 'T') {
			cout 	<< fixed << setprecision(2) << left << setw(width) << mathFunc 
					<< left << setw(width) << op1 << left << setw(width) << " " 
					<< left << setw(width) << result << endl;

			fout 	<< fixed << setprecision(2) << left << setw(width) << mathFunc 
					<< left << setw(width) << op1 << left << setw(width) << " "
					<< left << setw(width) << result << endl;
		}
		else {		
			cout 	<< fixed << setprecision(2) << left << setw(width) << mathFunc 
					<< left << setw(width) << op1 << left << setw(width) << op2 
					<< left << setw(width) << result << endl;

			fout 	<< fixed << setprecision(2) << left << setw(width) << mathFunc 
					<< left << setw(width) << op1 << left << setw(width) << op2 
					<< left << setw(width) << result << endl;
		}

		cout << "Continue? (y/n): "; //ok as long as user enters any single char
		cin >> refresh; //system("PAUSE") prob. makes more sense here...
	
	} while (refresh != 'n');

	//system("PAUSE");
	return 0;
}


void printMenu() {
	//system("cls"); //for win
	cout << "\033[2J\033[1;1H"; //supposed to clear screen on all OS, but didn't work in win. Works on osx
	cout << "Enter one of the following functions you would like to perform: \n\t(+, -, *, /, or %)" << endl;
	cout << "\tA average of two numbers" << endl;
	cout << "\tN minimum of two numbers" << endl;
	cout << "\tP a b" << endl;
	cout << "\tR reciprocal" << endl;
	cout << "\tF factorial" << endl;
	cout << "\tT square root" << endl << endl;
}

int twoIntegers(double &operand1, double &operand2, char &mathFunc, double &result) {

	cout << "enter first number: ";
	cin >> operand1;
	cout << "enter second number: ";
	cin >> operand2;

	if (mathFunc == '+') {
		result = operand1 + operand2;
	}
	else if (mathFunc == '-') {
		result = operand1 - operand2;
	}
	else if (mathFunc == '*') {
		result = operand1 * operand2;
	}
	else if (mathFunc == '/') {
		result = operand1 / operand2;
	}
	else if (mathFunc == '%') {
		result = fmod(operand1, operand2);
	}
	else if (mathFunc == 'P') {
		result = pow(operand1, operand2);
	}
	else if (mathFunc == 'A') {
		result = (operand1 + operand2) / 2;
	}
	else if (mathFunc == 'N') {
		if (operand1 < operand2){
			result = operand1;
		}
		else {
			result =operand2;
		}
	}
	
	return operand1;
	return operand2;
	return result;
}

int reciprocal(double &operand1, double &result) {

	cout << "enter number: ";
	cin >> operand1;

	result = 1 / operand1;

	return operand1;
	return result;
}

int factorial(double &operand1, double &result) {
	int factorial = 1;

	cout << "enter number: ";
	cin >> operand1;

	for (int i = 1; i <= operand1; i++) {
		factorial = factorial * i;
	}

	result = factorial;

	return operand1;
	return result;
}

int sqRoot(double &operand1, double &result) {

	cout << "enter number: ";
	cin >> operand1;

	result = pow(operand1, .5);

	return operand1;
	return result;
}

void header(){
	cout 	<< fixed << left << setw(width) << "Operation" 
			<< left << setw(width) << "Operand 1" 
			<< left << setw(width) << "Operand 2"
			<< left << setw(width) << "Result" << endl;

	fout 	<< fixed << left << setw(width) << "Operation" 
			<< left << setw(width) << "Operand 1" 
			<< left << setw(width) << "Operand 2"
			<< left << setw(width) << "Result" << endl;

}


/* OUTPUT

output in mathData.txt file:

Operation      Operand 1      Operand 2      Result         
+              2.00           1.00           3.00           
-              45.00          54.00          -9.00          
*              12.00          11.00          132.00         
/              123.00         321.00         0.38           
%              7.00           3.00           1.00           
A              123.00         321.00         222.00         
N              0.00           34.00          0.00           
N              2.00           567.00         2.00           
R              4.00                          0.25           
F              5.00                          120.00         
T              144.00                        12.00          
        

*/
