#ifndef __H_UTILITY_HPP__
#define __H_UTILITY_HPP__

#include <string>
#include <vector>

using namespace std;

namespace h_utility{

/**
 * example:
 * vector<string> strs = split_string_single_delim("abc def gh ", " ");
 * notes:
 * 1. the string read from a line of a file DOES NOT contain the '\n', therefore the spliting of an empty line will return an empty vector of string
 */
vector<string> split_string_single_delim(string str, string delim);
// wrapper for vector<string> split_string_single_delim(string str, string delim)
vector<string> split(string str, string delim);

/**
 * example:
 * vector<string> strs = split_string_multi_delim("abc ,def,ghi, , ", " >,");
 * notes:
 * 1. the string read from a line of a file DOES NOT contain the '\n', therefore the spliting of an empty line will return an empty vector of string
 */
vector<string> split_string_multi_delim(string str, string delim_str);
// wrapper for vector<string> split_string_multi_delim(string str, string delim_str)
vector<string> splitm(string str, string delim_str);

}	// end namespace hstd

#endif