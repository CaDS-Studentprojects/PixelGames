/*
 * FileOutputHandler.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#include "FileOutputHandler.hpp"

using namespace std;

FileOutputHandler::FileOutputHandler(string output_file)
{
	ofile.open(output_file);
}

FileOutputHandler::~FileOutputHandler() {
	ofile.close();
}

void FileOutputHandler::operator<<(vector<vector<uint32_t>> const & vect)
{
	ofile << FileOutputHandler::vectToString(vect);
}

string FileOutputHandler::vectToString(vector<vector<uint32_t>> const & vect)
{
	string s;
	for(auto row: vect){
		for(auto pixel: row){
			s += to_string(pixel) + " ";
		}
		s = s + "\n";
	}
	return s;
}


