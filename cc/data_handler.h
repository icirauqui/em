#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>




class DataHandlerTabular {

public:
  void load_data_file(std::string& data_dir,
                          std::vector<std::vector<float>> &sets_x, 
                          std::vector<std::vector<float>> &sets_y,
                          int limit = 0);


  void load_data_file(std::string& data_file,
                          std::vector<std::vector<float>> &sets,
                          bool header = false,
                          int limit = 0);


  void split_labels(std::vector<std::vector<float>> &sets,
                    std::vector<std::vector<float>> &sets_x,
                    std::vector<std::vector<float>> &sets_y);


  void split_dataset(std::vector<std::vector<float>> &set_x,
                    std::vector<std::vector<float>> &set_y,
                    std::vector<std::vector<float>> &train_x,
                    std::vector<std::vector<float>> &train_y,
                    std::vector<std::vector<float>> &test_x,
                    std::vector<std::vector<float>> &test_y,
                    float train_ratio = 0.8);

};






