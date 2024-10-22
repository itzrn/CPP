// TOPIC: Introduction to thread in c++ (c++11)

// QUESTIONS
// 1. What do you understand by thread and give one example in C++?

// ANSWER
// 0. In evey application there is a default thread which is main(), in side this we create other threads.
// 1. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads. 
//    For example:
//    (a) The browser has multiple tabs that can be different threads. 
//    (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
//    (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

// WAYS TO CREATE THREADS IN C++11
// 1. Function Pointers
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static Member functions

// REQUIREMENT
// Find the addition of all odd number from 1 to 1900000000 and all even number from 1 to 1900000000


#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
#define ull unsigned long long

// int OddSum=0;
// int EvenSum=0;

void findEven(ull start, ull end, ull& EvenSum) { // ull* EvenSum
	for (ull i = start; i <= end; ++i){
		if (!(i & 1)){
			// (*EvenSum) += i;
            EvenSum+=i;
		}
	}
}

void findOdd(ull start, ull end, ull& OddSum) {// ull* OddSum
	for (ull i = start; i <= end; ++i){
		if (i & 1){
			// (*OddSum) += i;
            OddSum += i;
		}
	}
}

int main() {
	
	ull start = 0, end = 1900000000;

	ull OddSum = 0; 
	ull EvenSum = 0;
    
    auto startTime = high_resolution_clock::now(); 

	// // WITH THREAD
    thread t1(findEven, start, end, ref(EvenSum));
    thread t2(findOdd, start, end, ref(OddSum));

    // when using cref then the parameter in the function should be passed normal and in that variable is no need to change
    // thread t1(findEven, start, end, cref(EvenSum)); // cref for constant reference
    // thread t2(findOdd, start, end, cref(OddSum));
    // fucntion will be -> void findOdd(ull start, ull end, ull OddSum){}




    // this when u using as pointer argumnet in the above function
    // thread t1(findEven, start, end, &EvenSum);
    // thread t2(findOdd, start, end, &OddSum);

    // if you wont write join it will not get join with the main thread
	t1.join();
	t2.join();

	// // WITHOUT THREAD
	// findEven(start,end, &EvenSum);
	// findOdd(start, end, &OddSum);
    auto stopTime = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "OddSum : " << OddSum << endl;
	cout << "EvenSum : " << EvenSum << endl;

	cout << "Sec: " << duration.count()/1000000 << endl;

	return 0;
}