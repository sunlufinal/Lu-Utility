#include "h_string.hpp"

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
vector<string> string_split_string_single_delim(string str, string delim)
{
	vector<string> strs;	// returned vector
	int str_len = str.length();
	int delim_len = delim.length();	// length of the delimitation

	// temporary variables
	size_t pos;	// position of found delimitation
	size_t start = 0;	// used in str.find() to specify the searching starting point
	string substring;	// used to store extracted sub-string

	pos = str.find(delim);	// find the position of the first occurrence of the delimitation
	// loop until no more delimitation is found
	while(pos != string::npos){
		if(pos == start){	// pos == start shows that continuous delimitations occur, continue
			start = pos + delim_len;
			pos = str.find(delim, start);
			continue;
		}
		substring = str.substr(start, pos - start);
		strs.push_back(substring);
		start = pos + delim_len;
		pos = str.find(delim, start);
	}
	if(start < str_len){	// this guards for the delimitation at the end of the string
		substring = str.substr(start);
		strs.push_back(substring);
	}
	
	return strs;
}

/**
 * wrapper for vector<string> split_string_single_delim(string str, string delim)
 */
vector<string> string_split(string str, string delim)
{
	return string_split_string_single_delim(str, delim);
}

/**
 * example:
 * vector<string> strs = split_string_multi_delim("abc ,def,ghi, , ", " >,");
 * notes:
 * 1. the string read from a line of a file DOES NOT contain the '\n', therefore the spliting of an empty line will return an empty vector of string
 */
vector<string> string_split_string_multi_delim(string str, string delim_str)
{
	vector<string> strs;	// returned vector
	vector<string> delims = string_split_string_single_delim(delim_str, ">");
	int str_len = str.length();
	int num_delims = delims.size();	// lengths of the delimitations
	vector<int> delim_lens(num_delims);
	for(int i = 0; i < num_delims; i++)
		delim_lens[i] = delims[i].length();

	// temporary variables
	size_t pos, pos_temp;	// position of found delimitation
	size_t start = 0;	// used in str.find() to specify the searching starting point
	string substring;	// used to store extracted sub-string
	int delim_len;	// length of the delimitation found
	int delim_index;

	// find the position of the first occurrence of the delimitation
	pos = string::npos;
	for(int i = 0; i < num_delims; i++){
		pos_temp = str.find(delims[i]);
		if(pos_temp < pos){
			pos = pos_temp;
			delim_index = i;
		}
	}
	delim_len = delim_lens[delim_index];
	// loop until no more delimitation is found
	while(pos != string::npos){
		if(pos == start){	// pos == start shows that continuous delimitations occur, continue
			start = pos + delim_len;
			pos = string::npos;
			for(int i = 0; i < num_delims; i++){
				pos_temp = str.find(delims[i], start);
				if(pos_temp < pos){
					pos = pos_temp;
					delim_index = i;
				}
			}
			delim_len = delim_lens[delim_index];
			continue;
		}
		substring = str.substr(start, pos - start);
		strs.push_back(substring);
		start = pos + delim_len;
		pos = string::npos;
		for(int i = 0; i < num_delims; i++){
			pos_temp = str.find(delims[i], start);
			if(pos_temp < pos){
				pos = pos_temp;
				delim_index = i;
			}
		}
		delim_len = delim_lens[delim_index];
	}
	if(start < str_len){	// this guards for the delimitation at the end of the string
		substring = str.substr(start);
		strs.push_back(substring);
	}
	
	return strs;
}

/**
 * wrapper for vector<string> split_string_multi_delim(string str, string delim_str)
 */
vector<string> string_splitm(string str, string delim_str)
{
	return string_split_string_multi_delim(str, delim_str);
}

}	// end namespace hstd