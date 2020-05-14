#include "filemanager.h"

void FileManager::parse_line(string &__line, vector<string> &__data) {
  /* heroId,heroName,heroHp,heroAtk,heroDef,heroInfo */
  int pos, start = 0;
  while (true) {
    pos = __line.find(',', start);
    if (pos == -1) {
      __data.push_back(__line.substr(start, __line.size() - start));
      break;
    }
    __data.push_back(__line.substr(start, pos - start));
    start = pos + 1;
  }
};

void FileManager::load_CSV_file(string __fp, map<int, map<string, string>> &__data) {
  if (__fp.size() == 0 || __fp.c_str() == nullptr) {
    cout << "invild argument [file_path]";
    return;
  };

  ifstream ifs(__fp);
  if (!ifs.is_open()) {
    cout << "file open error" << endl;
    return;
  }

  string first_line;
  ifs >> first_line;

  vector<string> columns;
  parse_line(first_line, columns);
  if (columns.size() == 0) {
    cout << "file empty" << endl;
    return;
  }

  vector<string> data_temp;
  string data_line;
  while (ifs >> data_line) {
    parse_line(data_line, data_temp);

    map<string, string> __m;
    for (size_t i = 0; i < columns.size(); ++i) {
      __m.insert(make_pair(columns[i], data_temp[i]));
    }
    __data.insert(make_pair(stoi(data_temp[0]), __m));

    data_temp.clear();
  }

  ifs.close();
};