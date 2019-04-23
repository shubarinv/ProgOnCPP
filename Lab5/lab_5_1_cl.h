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
		for (int i = 0; i <totalAmoutOfElmnts ; ++i) {
			cin>>arr[i];
		}
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

	void showArr() {
		for (int i = 0; i <totalAmoutOfElmnts ; ++i) {
			cout<<arr[i]<<"\t";
			if(i%6==0)
				cout<<endl;
		}
		cout<<endl;
	};
	~Lab5_1_cl(){
		delete(arr);
	}
private:
	Tdata *arr;
	int totalAmoutOfElmnts = 0;
};


#endif //PROGONCPP_LAB_5_1_CL_H
