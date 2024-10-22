// TOPIC: Use Of join(), detach() and joinable() In Thread In C++ (C++11)

// JOIN NOTES
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
// 1. Double join will result into program termination.
// 2. If needed we should check thread is joinable before joining. ( using joinable() function)


// DETACH NOTES
// 0. This is used to detach newly created thread from the parent thread.
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
//    double detach() will result into program termination.
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.

// NOTES:
// Either join() or detach() should be called after thred object, otherwise during threading object of destructor it will 
// terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.


#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void run(int count) {
	while(count --> 0)
		cout << count << " CppNuts" << endl;
	//std::this_thread::sleep_for(chrono::seconds(5));
	cout << "thread finished" << endl;
}

int main() {
	std::thread t1(run, 10);
	cout << "main()" << endl;

    t1.join(); // main thread wait for the thread t1 to complete
    // t1.detach() -> main thread do not wait for the thread t1 to complete

    if(t1.joinable()){ // it ensure that if t1 is not joined then it will join it
        t1.join();
    } // this is the solution for double join

    // if(t1.joinable()){
    //     t1.detach();
    // } // this is the solution for double detach

	
	cout << "main() after" << endl;
	//std::this_thread::sleep_for(chrono::seconds(5));
	return 0;
}

// https://github.com/cppnuts-yt/CppNuts/tree/master/Threading