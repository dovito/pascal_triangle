#include <iostream>
#include <limits>
using namespace std;

class PascalTriangle {
	protected:
		int rows;
	public:
		void setRows(int r) {
			rows = r;
		}
		int digitsInNumber(int n);
		void buildTriangle(void) {
			int i, j; // Outer and inner iterators
			int tmp, number, numSpaces; // Values to print
			string spaces;
			i = 0;
			// iterate over the numbe of rows to be displayed
			while (i < rows) {
				tmp = 1;

				// format spaces from beggining to the number
				if(rows %2 != 0)
					spaces = string((rows - i - 1)*(rows / 2), ' ');
				else 
					spaces = string((rows - i - 1)*((rows / 2)- 1), ' ');
				cout << spaces;
				
				j = 0;
				while (i >= j) {
					number = tmp;
					// calculate next number
					tmp = tmp * (i - j) / (j + 1);
					numSpaces = this->digitsInNumber(tmp);
					if (rows % 2 == 0)
						cout << number << string(rows - 2 - numSpaces, ' ');
					else
						cout << number << string(rows - 1 - numSpaces, ' ');
					++j;
				}
				cout << "\n";
				++i;
			}
		}

};

int PascalTriangle::digitsInNumber(int n) {
	int numOfDigits = 0;
	while (n != 0) {
		n = n / 10;
		++numOfDigits;
	}
	return numOfDigits;
}

int main() {
	cout << "This is a program that draws a Pascal's Trinagle." << endl;
	int rows;
	bool good = false;
	char state;
	do {
		cout << "Enter the number of rows to be displayed> ";
		cin >> rows;
		// validate input number of rows
		if (cin.good()) {
			cout << "You have entered " << rows << ". Proceed? (type 'y'-yes, 'n'-no, 'r'-reset): ";
			cin >> state;
			if (state == 'y') {
				good = true;
			}
			else if (state == 'n') {
				return 0;
			}
		}
		else {
			// wrong input, reset buffer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please re-enter." << endl;
		}
		
		// validate input
	} while (!good);
	
	PascalTriangle pascal_triangle;
	pascal_triangle.setRows(rows);
	pascal_triangle.buildTriangle();
	return 0;
}
