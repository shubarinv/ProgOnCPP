//
// Created by vhundef on 22.04.19.
//


#include "lab_5_1_cl.h"

int main(){
	char inp;
	cout<<"Float(0) или Unsigned char(1)?"<<endl;
	cin>>inp;
	if(inp=='0'){
		Lab5_1_cl<float> ts;
		ts.showArr();
		cout<<"Min value: "<<ts.findMin()<<endl;
		cout<<endl<<"=========="<<endl;
		ts.norm();
		ts.showArr();
	}
	else if(inp=='1'){
		Lab5_1_cl<unsigned char> ts;
		ts.showArr();
		cout<<"Min value: "<<ts.findMin()<<endl;
		cout<<endl<<"=========="<<endl;
		ts.norm();
		ts.showArr();
	}
	else
		throw invalid_argument("unexpected value was entered");
}
