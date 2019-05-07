//
// Created by vhundef on 22.04.19.
//


#include "lab_5_1_cl.h"

int main() {
	char inp;
	cout << "Float(0) или Unsigned char(1)?" << endl;
	cin >> inp;
	if (inp == '0') {
		float tmp;
		Lab5_1_cl<float> ts;
		cin >> tmp;
		while (ts.addElement((unsigned char) tmp)) {
			cin >> tmp;
		}
		ts.showArr();
		cout << "Min value: " << ts.findMin() << endl;
		cout << endl << "==========" << endl;
		ts.norm();
		ts.showArr();
	} else if (inp == '1') {
		Lab5_1_cl<unsigned char> ts;
		int tmp;
		cin >> tmp;
		while (ts.addElement((unsigned char) tmp)) {
			cin >> tmp;
		}
		ts.showArr();
		cout << "Min value: " << (int) ts.findMin() << endl;
		for (int i = 0; i < ts.getTotalAmoutOfElmnts(); ++i) {
			cout << (int) ts.showArr()[i] << "\t";
		}
		cout << endl << "==========" << endl;
		ts.norm();
		for (int i = 0; i < ts.getTotalAmoutOfElmnts(); ++i) {
			cout << (int) ts.showArr()[i] << "\t";
		}
	} else
		throw invalid_argument("unexpected value was entered");
}
