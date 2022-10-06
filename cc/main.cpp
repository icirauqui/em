#include <iostream>
#include <vector>



#include "data_handler.h"
#include "em.h"




void go_unlabeled() {

  std::cout << "Unsupervised" << std::endl;
  
  DataHandlerTabular data_handler;
  std::string data_file = "/home/icirauqui/w4rkspace/em/data/unlabeled.csv";

  std::vector<std::vector<float>> ds;
  data_handler.load_data_file(data_file, ds, true);

  EM em;
  em.InitializeRandomParams(2);

  em.RunEM(ds);


  





}



void go_labeled() {
  
  DataHandlerTabular data_handler;
  std::string data_file = "/home/icirauqui/w4rkspace/em/data/labeled.csv";

  std::vector<std::vector<float>> ds;
  data_handler.load_data_file(data_file, ds, true);

  std::vector<std::vector<float>> ds_x;
  std::vector<std::vector<float>> ds_y;
  data_handler.split_labels(ds, ds_x, ds_y);

  std::vector<std::vector<float>> train_x;
  std::vector<std::vector<float>> train_y;
  std::vector<std::vector<float>> test_x;
  std::vector<std::vector<float>> test_y;
  data_handler.split_dataset(ds_x, ds_y, train_x, train_y, test_x, test_y, 0.8);

}



int main() {


  go_unlabeled();
  


  return 0;
}