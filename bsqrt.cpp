//	Name:   Croddy, Mei-Ying
//	Project: HW 1
// 	Due: October 3 2018
//	Course: CS-2560-02-F18

// Description:
//	This program calculates the square root using the Babylonian method as well as the predefined square root functions.
// Then it compares the difference between them.  


#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;
double bsqrt(double number, int iterations = 8);

double bsqrt(double number, int iterations)
{
	double guess = number/2.0;

	
	while(iterations > 0)
	{
		guess = (guess + (number/guess))/2.0;
		//cout << "loop\n";
		//cout << guess << endl;
		iterations--;
	}
	return guess;
}

int main()
{
	ofstream outputFile;
	double babylonianSquareRoot;
	double librarySquareRoot;
	double delta;
	
	outputFile.open("bsqrt.txt");

	outputFile << "M. Croddy's Babylonian Square Root\n\n";
	outputFile << setw(5) << "x" << setw(15) << "sqrt(x)" << setw(15) << "bsqrt(x)" << setw(13) << "delta\n";
	outputFile << "------    ------------  ------------  ----------- \n";
	
	for(int count = 1; count <= 10; count++)
	{
		babylonianSquareRoot = bsqrt(count, 5);
		librarySquareRoot = sqrt(count);
		delta = abs(babylonianSquareRoot - librarySquareRoot);
		
		outputFile << fixed << setprecision(8) << setw(4) << count << ".0" << setw(14) << librarySquareRoot;
		outputFile << setw(14) << babylonianSquareRoot;
		outputFile << setw(15) << delta << "\n";
	}
	outputFile.close();
	
	return 0;
}