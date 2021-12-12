// Copyright 2021 Trushkov Ilya ilya.tr20002@gmail.com
#ifndef TEMPLATE_MYEXPERIMENT_HPP
#define TEMPLATE_MYEXPERIMENT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>
#include <algorithm>

struct ExperimentTimes {
  double time_straight;
  double time_reverse;
  double time_random;
};

class MyExperiment {
 private:
  ExperimentTimes _times;
  int *_mas;
  size_t _number_of_elements;
  std::vector<size_t> _indexes_for_warming;
  std::vector<size_t> _indexes_for_buffer;

 public:
//  static int counter_of_experiments;
  MyExperiment(const size_t &N);
  size_t get_number_of_elements() const;
  ExperimentTimes get_time() const;
  static int get_element(int a);
  void warming_cache();
  auto loop_mas();
  void make_straight_experiment();
  void make_reverse_experiment();
  void make_random_experiment();
  ~MyExperiment();
};

#endif  // TEMPLATE_MYEXPERIMENT_HPP
