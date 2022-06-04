#include <iostream>
#include <thread>
using namespace std;

class singleInstance {
public:
	static singleInstance* GetsingleInstance() {
		if (instance == NULL) {
			mutex_t mutex;//mutex mlock; 加锁互斥
			pthread_mutex_lock(&mutex);//mlock.lock();
			if (instance == NULL) {
				instance = new singleInstance();
			}
			mutex_unlock(&mutex);//mlock.unlock();
		}
		return instance;
	};
	~singleInstance() {};
private:// 涉及创建对象的函数都设置为private
	singleInstance() {};
	singleInstance(const singleInstance& other) {};
	singleInstance& operator=(const singleInstance& other) { return *this; };
	static singleInstance* instance;
};

//懒汉式
singleInstance* singleInstance::instance = nullptr;

int main() {
	// 因为没有办法创建对象，就得采用静态成员函数的方法返回静态成员变量
	singleInstance *s = singleInstance::GetsingleInstance();
	//singleInstance *s1 = new singleInstance(); // 报错
	cout << "Hello World";
	return 0;
}