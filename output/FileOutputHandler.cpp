/*
 * FileOutputHandler.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#include "FileOutputHandler.hpp"

using namespace std;

namespace pixelgames {
namespace output {

FileOutputHandler::FileOutputHandler(string output_file) {
  ofile_.open(output_file);
  if (!ofile_) throw runtime_error { "Could not open" + output_file };

  ofile_ << "New Game starts" << endl;
}

FileOutputHandler::~FileOutputHandler() {
  ofile_.close();
}

void FileOutputHandler::operator<<(vector<vector<uint32_t>> const & vect) {
  ofile_ << FileOutputHandler::vectToString(vect) << endl;
}

string FileOutputHandler::vectToString(vector<vector<uint32_t>> const & vect) {
  string s;
  for (auto row : vect) {
    for (auto pixel : row) {
      s += to_string(pixel > 0 ? 1 : 0) + " ";
    }
    s = s + "\n";
  }
  return s;
}

} /* namespace output */
} /* namespace pixelgames */
