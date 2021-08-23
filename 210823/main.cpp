#include <iostream>
#include "CVector.h"

using namespace std;

int main() {
	CVector v1(3, 4, 1);
	CVector v2(3, 4, 1);

	cout << "v1 == v2 : " << (v1 == v2) << endl;
	cout << "v1 != v2 : " << (v1 != v2) << endl;

	CVector v3 = v1 + v2;

	cout << "v3 : " << v3 << endl;
	cout << "v1 - v2 : " << v1 - v2 << endl;

	v3 *= 3.0f;
	cout << "v3 : " << v3 << endl;
	cout << "Dist : " << CVector::Distance(v1, v2) << endl;

	v3.Normalize();
	cout << "v3 : " << v3 << endl;
	cout << "v3 Length : " << v3.Length() << endl;

	return 0;
}