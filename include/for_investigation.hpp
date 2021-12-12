// Copyright 2021 Trushkov Ilya ilya.tr20002@gmail.com
#ifndef INCLUDE_FOR_INVESTIGATION_HPP_
#define INCLUDE_FOR_INVESTIGATION_HPP_

#include "MyExperiment.hpp"

#include <cstdlib>
#include <fstream>
#include <vector>

struct CacheSize {
  const std::size_t level1 = 128 * 1024;
  const std::size_t level2 = 512 * 1024;
  const std::size_t level3 = 8192 * 1024;
};

struct MasSize {
  double min_size;
  double max_size;
  double current_size;
};

void make_report(std::vector <MyExperiment*> &results, std::ostream &os);

#endif  // INCLUDE_FOR_INVESTIGATION_HPP_
