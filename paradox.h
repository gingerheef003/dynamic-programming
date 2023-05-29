#include <bits/chrono.h>
#include <chrono>
#include <iostream>
#include <iterator>
#include <ostream>
#include <type_traits>

template<typename Func, typename... Args>
typename std::enable_if<!std::is_void<decltype(std::declval<Func>()(std::declval<Args>()...))>::value,decltype(std::declval<Func>()(std::declval<Args>()...))>::type
calcTime(Func func, Args... args) {

	auto start = std::chrono::high_resolution_clock::now();
	auto result = func(args...);
	auto stop = std::chrono::high_resolution_clock::now();

	std::cout << "Execution time: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << " microseconds" << std::endl << std::endl;
	
	return result;

}

template<typename Func, typename... Args>
typename std::enable_if<std::is_void<decltype(std::declval<Func>()(std::declval<Args>()...))>::value>::type
calcTime(Func func, Args... args) {

	auto start = std::chrono::high_resolution_clock::now();
	func(args...);
	auto stop = std::chrono::high_resolution_clock::now();

	std::cout << "Execution time: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << " microseconds" << std::endl << std::endl;
	
}
