#include "data_handler.h"



void DataHandlerTabular::load_data_file(std::string& data_dir,
                        std::vector<std::vector<float>> &sets_x, 
                        std::vector<std::vector<float>> &sets_y,
                        int limit) {
  std::cout << "Loading data" << std::endl;

  std::string swift_train_x = data_dir + "swift_train_x.csv";
  std::string swift_train_y = data_dir + "swift_train_y.csv";

  std::fstream fin;
  int cnt;
  std::string line, word;

  std::cout << "load_preprocessed_swift_dataset std::vector" << std::endl;

  fin.open(swift_train_x, std::ios::in);
  cnt = 0;
  std::vector<std::vector<float>> train_x;
  while (std::getline(fin, line)) {
    std::stringstream s(line);
    std::vector<float> row;
    while (getline(s, word, ',')) {
        row.push_back(std::stof(word));
    }
    sets_x.push_back(row);
    //sets_x1.push_back(row);

    cnt++;
    if (limit > 0 && cnt == limit)
      break;
  }
  fin.close();
    
  fin.open(swift_train_y, std::ios::in);
  cnt = 0;
  std::vector<std::vector<float>> train_y;
  while (std::getline(fin, line)) {
    std::stringstream s(line);
    std::vector<float> row;
    while (getline(s, word, ',')) {
      row.push_back(std::stof(word));
    }
    sets_y.push_back(row);
    //sets_y1.push_back(row);

    cnt++;
    if (limit > 0 && cnt == limit)
      break;
  }
  fin.close();
}




void DataHandlerTabular::load_data_file(std::string& data_file,
                    std::vector<std::vector<float>> &sets,
                    bool header,
                    int limit) {
  std::cout << "Loading data" << std::endl;

  std::fstream fin;
  int cnt;
  std::string line, word;

  fin.open(data_file, std::ios::in);
  cnt = 0;
  while (std::getline(fin, line)) {

    if (header) {
      header = false;
      continue;
    }

    std::stringstream s(line);
    std::vector<float> row;
    while (getline(s, word, ',')) {
        row.push_back(std::stof(word));
    }
    sets.push_back(row);

    cnt++;
    if (limit > 0 && cnt == limit)
      break;
  }
  fin.close();
}


void DataHandlerTabular::split_labels(std::vector<std::vector<float>> &sets,
                  std::vector<std::vector<float>> &sets_x,
                  std::vector<std::vector<float>> &sets_y) {

  for (auto &row : sets) {
    std::vector<float> row_x;
    std::vector<float> row_y;
    for (int i = 0; i < row.size(); i++) {
      if (i == row.size() - 1) {
        row_y.push_back(row[i]);
      } else {
        row_x.push_back(row[i]);
      }
    }
    sets_x.push_back(row_x);
    sets_y.push_back(row_y);
  }
}



void DataHandlerTabular::split_dataset(std::vector<std::vector<float>> &sets_x,
                   std::vector<std::vector<float>> &sets_y,
                   std::vector<std::vector<float>> &train_x,
                   std::vector<std::vector<float>> &train_y,
                   std::vector<std::vector<float>> &test_x,
                   std::vector<std::vector<float>> &test_y,
                   float train_ratio) {

  int train_size = sets_x.size() * train_ratio;

  for (unsigned int i=0; i<sets_x.size(); i++) {
    if (i < train_size) {
      train_x.push_back(sets_x[i]);
      train_y.push_back(sets_y[i]);
    } else {
      test_x.push_back(sets_x[i]);
      test_y.push_back(sets_y[i]);
    }
  }
}






