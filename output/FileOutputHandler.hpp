/*
 * FileOutputHandler.hpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#ifndef FILEOUTPUTHANDLER_HPP_
#define FILEOUTPUTHANDLER_HPP_

#include <string>
#include <fstream>
#include "IOutputHandler.hpp"

using namespace std;

class FileOutputHandler: public IOutputHandler {
public:
	FileOutputHandler(string output_file);
	~FileOutputHandler();
	void operator<<(vector<vector<uint32_t>> const & vect) override;

	static string vectToString(vector<vector<uint32_t>> const & vect);
private:
	ofstream ofile;

};

#endif /* FILEOUTPUTHANDLER_HPP_ */
