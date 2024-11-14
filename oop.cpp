#include<bits/stdc++.h>
using namespace std;

void pee(char c){
	cout<<"The char is "<<c<<endl;
}
void pee(double c){
	cout<<"The double is "<<c<<endl;
}

int boob=0;
class boobies{
	public:
	boobies(){
		boob++;
		cout<<"the count is : "<<boob<<endl;
	}
	~boobies(){
	boob--;
	cout<<"the count is : "<<boob<<endl;
	}
};

int main(){
	boobies b1,b2,b3,b4;
	pee('A');
	pee(2.0);
	return 0;
}
