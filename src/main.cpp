#include <cmath>
#include <iostream>
#include <ostream>
#include <random>
#include <vector>

int sumPositive(const std::vector<int> &vec) {
  int sum = 0;
  for (int el : vec) {
    if (el > 0)
      sum += el;
  }
  return sum;
}

int countOdds(const std::vector<int> &vec) {
  int odds = 0;
  for (int el : vec) {
    if (abs(el) % 2 == 1)
      odds++;
  }
  return odds;
}

std::vector<int> generateVector(int n) {
  int min = -n / 2 - 1;
  int max = n / 2;

  std::random_device rnd;
  std::mt19937 gen(rnd());
  std::uniform_int_distribution<> dist(min, max);
  std::vector<int> A;

  for (int i = 0; i < n; i++) {
    int num = dist(gen);
    std::cout << num << " ";

    A.push_back(num);
  }
  std::cout << std::endl;
  return A;
}

int main() {
  int n;
  std::cout << "Введите целое число: ";

  // Бесконечный цикл для запроса ввода
  while (true) {
    std::cout << "Введите n (размер массива)" << std::endl;
    std::cin >> n;
    if (std::cin.good() && n != 0) {
      break;
    }

    std::cout << "Ошибка! Пожалуйста, введите целое число: ";

    std::cin.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  std::vector<int> A = generateVector(n);

  unsigned char mode;
  do {
    std::cout
        << "Выберите режим" << std::endl
        << "1. Подсчитать сумму всех элементов, имеющих положительные значения"
        << std::endl
        << "2. Подсчитать количество элементов с нечетными значениями"
        << std::endl;
    std::cin >> mode;
  } while (mode != '2' && mode != '1');

  std::cout << "Ответ: " << ((mode == '2') ? countOdds(A) : sumPositive(A))
            << std::endl;
  return 0;
}
