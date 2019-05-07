//
// Created by vhundef on 22.04.19.
//

#ifndef PROGONCPP_LAB_5_1_CL_H
#define PROGONCPP_LAB_5_1_CL_H

#include <iostream>

using namespace std;

template<class Tdata>
class Lab5_1_cl {
public:
	Lab5_1_cl() {
		cout << "Введите количество элементов в массиве: ";
		cin >> totalAmoutOfElmnts;
		arr = new Tdata[totalAmoutOfElmnts];
	}


	Tdata findMin() {
		Tdata tmp = arr[0];
		for (int i = 1; i < totalAmoutOfElmnts; ++i) {
			if (arr[i] < tmp)
				tmp = arr[i];
		}
		return tmp;
	}

	void norm() {
		Tdata min = findMin();
		for (int i = 0; i < totalAmoutOfElmnts; ++i) {
			arr[i] -= min;
		}
	}

	Tdata * showArr() {
		return arr;
	};

	~Lab5_1_cl() {
		delete (arr);
	}

	bool addElement(Tdata dt) {
		if (tmpI < totalAmoutOfElmnts){
			arr[tmpI] = dt;
			tmpI++;
			cout<<tmpI<<"now"<<endl;
			return true;
		}
		else{
			cout<<"Cannot add more"<<endl;
			return false;
		}
	}

private:
	Tdata *arr;
	int totalAmoutOfElmnts = 0, tmpI = 0;
public:
	int getTotalAmoutOfElmnts() const {
		return totalAmoutOfElmnts;
	}
};


#endif //PROGONCPP_LAB_5_1_CL_H
