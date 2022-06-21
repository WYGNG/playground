#include <iostream>
using namespace std;
// int main()
// {
//     double m = 1, n = 0;
//     try {
//         cout << "before dividing." << endl;
//         if (n == 0)
//             throw - 1;  //抛出int型异常
//         else if (m == 0)
//             throw - 1.0;  //拋出 double 型异常
//         else
//             cout << m / n << endl;
//         cout << "after dividing." << endl;
//     }
//     catch (double d) {
//         cout << "catch (double)" << d << endl;
//     }
//     catch (...) {
//         cout << "catch (...)" << endl;
//     }
//     cout << "finished" << endl;
//     return 0;
// }
// //运行结果
// //before dividing.
// //catch (...)
// //finished


class A{
public:
  virtual ~A();
};
 
using namespace std;
int main() {
	A* a = NULL;
	try {
  		cout << typeid(*a).name() << endl; // Error condition
  	}
	catch (bad_typeid){
  		cout << "Object is NULL" << endl;
  	}
    return 0;
}
//运行结果：bject is NULL