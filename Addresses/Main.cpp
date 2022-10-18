#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Address {
private:
	string townName;
	string streetName;
	int houseNum;
	int apartmentNum;

public:
	Address(string townName, string streetName, int houseNum, int apartmentNum) {
		this->townName = townName;
		this->streetName = streetName;
		this->houseNum = houseNum;
		this->apartmentNum = apartmentNum;
	}

	string collectString() {
		string string = townName + ", " + streetName + ", " + to_string(houseNum) + ", " + to_string(apartmentNum);

		return string;
	}
};

int main() {
	ifstream in("in.txt");
	int size;
	in.is_open();
	in >> size;
	int count = size;

	string* stringArr = new string[size];
	if (in.is_open()) {
		while (!in.eof()) {
			string townName;
			string streetName;
			int houseNumber = 0;
			int apartmentNumber = 0;

			in >> townName >> streetName >> houseNumber >> apartmentNumber;

			Address addr(townName, streetName, houseNumber, apartmentNumber);
			string address = addr.collectString();

			stringArr[size - count] = address;
			--count;
		}
	}
	else {
		cout << "Не удалось открыть файл!" << endl;
	}
	in.close();

	ofstream out("out.txt");
	out << size << endl;
	for (int i = size - 1; i >= 0; --i) {
		string string = stringArr[i];
		out << string << endl;
	}
	out.close();

	delete[] stringArr;

	return 0;
}