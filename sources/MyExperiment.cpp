// Copyright 2021 Trushkov Ilya ilya.tr20002@gmail.com
#include "MyExperiment.hpp"

MyExperiment::MyExperiment(const size_t &N)
    : _times()
    , _number_of_elements(N) {
//  counter_of_experiments += 1;
  _mas = new int[_number_of_elements];

//  std::random_device rd;
//  std::mt19937 mersenne(rd());
  std::mt19937 generator(clock());
  for (size_t i = 0; i < _number_of_elements; ++i)
    _mas[i] = (int) generator();

  for (size_t i = 0; i < _number_of_elements; i += 16)
    _indexes_for_warming.push_back(i);

  for (size_t i = 0; i < _number_of_elements; i++)
    _indexes_for_buffer.push_back(i);
}

size_t MyExperiment::get_number_of_elements() const {
  return  _number_of_elements;
}

ExperimentTimes MyExperiment::get_time() const {
  return _times;
}

int MyExperiment::get_element(int a) {
  return a;
}

void MyExperiment::warming_cache() {
  for (const size_t &i : _indexes_for_warming) {
    get_element(_mas[i]);
  }
}

auto MyExperiment::loop_mas() {
  auto start_time = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < 1000; ++i) {
    for (const size_t &j : _indexes_for_buffer)
      get_element(_mas[j]);
  }
  auto end_time = std::chrono::high_resolution_clock::now();
  auto elapsed_ns = std::chrono::
      duration_cast<std::chrono::milliseconds>(end_time - start_time);
  return elapsed_ns.count();
}

void MyExperiment::make_straight_experiment() {
  warming_cache();
  _times.time_straight = (double) loop_mas();
//  std::cout << "Straight bypass duration: " << _times.time_straight << " ms"
//            << std::endl;
}

void MyExperiment::make_reverse_experiment() {
  std::reverse(_indexes_for_warming.begin(), _indexes_for_warming.end());
  warming_cache();
  std::reverse(_indexes_for_buffer.begin(), _indexes_for_buffer.end());
  _times.time_reverse = (double) loop_mas();
//  std::cout << "Reverse bypass duration: " << time.duration_reverse << " ms"
//            << std::endl;
}

void MyExperiment::make_random_experiment() {
  std::mt19937 g(clock());
  std::shuffle(_indexes_for_warming.begin(), _indexes_for_warming.end(), g);
  warming_cache();
  std::shuffle(_indexes_for_buffer.begin(), _indexes_for_buffer.end(), g);
  _times.time_random = (double) loop_mas();
//  std::cout << "Random bypass duration: " << time.duration_random << " ms"
//            << std::endl;
}

MyExperiment::~MyExperiment() {
  delete[] _mas;
}
