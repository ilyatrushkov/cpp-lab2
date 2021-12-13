#include "MyExperiment.hpp"
#include "for_investigation.hpp"

int main() {
  std::vector<MyExperiment*> results;
  const CacheSize cache_size;
  MasSize mas_info{};
  mas_info.min_size = 0.5 * cache_size.level1;
  mas_info.max_size = 1.5 * cache_size.level3;
  mas_info.current_size = mas_info.min_size;

  size_t N = mas_info.min_size / sizeof(int);
  size_t step = std::log2(mas_info.min_size);
  while (mas_info.current_size <= mas_info.max_size) {
    auto *experiment = new MyExperiment(N);
    experiment -> make_straight_experiment();
    experiment -> make_reverse_experiment();
    experiment -> make_random_experiment();
    results.push_back(experiment);
    ++step;
    mas_info.current_size = pow(2, step);
    N = mas_info.current_size / sizeof(int);
    make_report(results, std::cout);
    results.clear();
  }
  if (mas_info.current_size != mas_info.max_size) {
    auto *experiment = new MyExperiment(mas_info.max_size / sizeof(int));
    experiment -> make_straight_experiment();
    experiment -> make_reverse_experiment();
    experiment -> make_random_experiment();
    results.push_back(experiment);
    make_report(results, std::cout);
  }
  return 0;
}
