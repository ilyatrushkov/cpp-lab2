// Copyright 2021 Trushkov Ilya ilya.tr20002@gmail.com

#include "for_investigation.hpp"

void make_report(std::vector <MyExperiment*> &results, std::ostream &os) {
  os << "investigation:\n";
  os << "\ttravel_variant: Direct\n";
  os << "\texperiments:\n";
  for (size_t i = 0; i < results.size(); i++) {
    os << "\t- experiment:\n";
    os << "\t\tnumber: " << i + 1 << "\n";
    os << "\t\tinput data:\n";
    os << "\t\t\tbuffer size: \""
         << results[i] -> get_number_of_elements() * sizeof(int) / 1024
       << " kB\"\n";
    os << "\t\tresults:\n";
    os << "\t\t\tduration: \"" << results[i] -> get_time().time_straight
         << " ms\"\n";
  }
  os << "\n";
  os << "investigation:\n";
  os << "\ttravel_variant: Reverse\n";
  os << "\texperiments:\n";
  for (size_t i = 0; i < results.size(); i++) {
    os << "\t- experiment:\n";
    os << "\t\tnumber: " << i + 1 << "\n";
    os << "\t\tinput data:\n";
    os << "\t\t\tbuffer size: \""
         << results[i] -> get_number_of_elements() * sizeof(int) / 1024
       << " kB\"\n";
    os << "\t\tresults:\n";
    os << "\t\t\tduration: \"" << results[i]->get_time().time_reverse
         << " ms\"\n";
  }
  os << "\n";
  os << "investigation:\n";
  os << "\ttravel_variant: Random\n";
  os << "\texperiments:\n";
  for (size_t i = 0; i < results.size(); i++) {
    os << "\t- experiment:\n";
    os << "\t\tnumber: " << i + 1 << "\n";
    os << "\t\tinput data:\n";
    os << "\t\t\tbuffer size: \""
         << results[i] -> get_number_of_elements() * sizeof(int) / 1024
       << " kB\"\n";
    os << "\t\tresults:\n";
    os << "\t\t\tduration: \"" << results[i]->get_time().time_random
         << " ms\"\n";
  }
  os << "\n";
}

