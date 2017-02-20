#ifndef GUARD_analysis
#define GUARD_analysis 
#include <vector>
#include <iostream>
#include <string>
#include "StudentInfo.hpp"


double median_analysis(const std::vector<StudentInfo>& students);
void write_analysis(std::ostream&,
		    std::string,
		    double analysis(const std::vector<StudentInfo>&),
		    const std::vector<StudentInfo>&,
		    const std::vector<StudentInfo>&);

#endif
