#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;


class PhysicalCheck {
	string name;
	int height;
	double vision;
public:
	PhysicalCheck(string name, int height, double vision) {
		this->name = name;
		this->height = height;
		this->vision = vision;
	}
	string getName() { return this->name; }
	int getHeight() { return this->height; }
	double getVision() { return this->vision; }
};

void Physic() {
	vector<PhysicalCheck*> v;
	
	for (int i = 0; i < 5; i++) {
		string name;
		int height;
		double vision;

		cout << "이름: "; cin >> name;
		cout << "키: "; cin >> height;
		cout << "시력: "; cin >> vision;

		v.push_back(new PhysicalCheck(name, height, vision));
	}

	for (int i = 0; i < v.size(); i++) 
		cout << v[i]->getName() << "\t" << v[i]->getHeight() << "\t" << v[i]->getVision() << "\t" << endl;
	cout << "평균키: ";
	int sum_height = 0;
	for (int i = 0; i < v.size(); i++) 
		sum_height += v[i]->getHeight();
	cout << sum_height / v.size() << endl;
	
	

	for (int i = 0; i < v.size(); i++) 
		delete v[i];
}