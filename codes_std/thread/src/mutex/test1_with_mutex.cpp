
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <stdexcept>
 
int counter = 0;
std::mutex mtx;
void increase(int time){
	for(int i=0;i<time;i++){
	mtx.lock();
	//当前线程休眠1ms
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	counter++;
	mtx.unlock(); //利用锁来保护共享变量
	}
}
 
int main(int argc, char** argv){
	std::thread t1(increase, 10000);
	std::thread t2(increase, 10000);
	t1.join();
	t2.join();
	std::cout<<"counter:"<<counter<< std::endl;
	return 0;
}
