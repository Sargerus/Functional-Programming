/*неизменяемую переменную,
чистую функцию,
функцию первого порядка,
функцию высшего порядка,
каррирование функций,
меморизацию функции,--
сделайте ленивое и энергичное вычисление функции,-
монаду,--
бесконечную структуру данных,
лямбда выражение
операции Map, Filter и Reduce.--*/

#include <iostream>
#include <cstddef>
#include <functional>
#include <vector>

using namespace std;

//https://habr.com/ru/post/149056/
template <typename R, typename T0, typename T1>
function<function<R(T1)>(T0)> curry_(function<R(T0, T1)> f)
{
	return [=](T0 const& t0) -> function<R(T1)>
	{
		return [=](T1 const& t1) { return f(t0, t1); };
	};
}


const auto unchangeableConst = 5;
typedef int (*pToFunc)(int, int);

int clearFunction(int x) {
	return x * x;
}

pToFunc upperFunction() {

	return [](int a, int b) -> int { return a + b; };

};

int sum(int a, int b) { return a + b; }

int main() {

	std::cout << upperFunction()(2, 3) << std::endl;

	auto curried_sum = curry_<int, int, int>(sum);
	cout << curried_sum(42)(10) << endl;

	vector<int> vector1;

	return 0;
}




