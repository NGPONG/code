#ifndef __FILE_MANAGER_H__
#define __FILE_MANAGER_H__

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class FileManager {
public:
  void load_CSV_file(string __fp, map<int, map<string, string>> &__data);
private:
  void parse_line(string &__line, vector<string> &__data);
};

#endif /* end of include guard: __FILE_MANAGER_H__ */
