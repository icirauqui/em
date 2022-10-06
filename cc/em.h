#include <iostream>
#include <vector>

#include <cstdlib>
#include <ctime>

#include <arrayfire.h>

#include <Eigen/StdVector>




class EM {

public:

  EM();
  ~EM();

  void InitializeRandomParams(unsigned int n);

  void RunEM(std::vector<std::vector<float>> &data);

  std::vector<float> GetAvgLogLikelihood(std::vector<std::vector<float>> &x);

  std::vector<float> E_Step(std::vector<std::vector<float>> &x);


  double pdf(const Eigen::VectorXd& x, 
                   Eigen::VectorXd mean,
                   Eigen::MatrixXd sigma ) const;

  //std::vector<std::vector<float>> GetRandomPsd(unsigned int n);

private:

  Eigen::VectorXd phi_;
  Eigen::VectorXd mean0_;
  Eigen::VectorXd mean1_;
  Eigen::MatrixXd sigma0_;
  Eigen::MatrixXd sigma1_;

  


  //std::vector<float> phi_;
  //std::vector<float> mu0_;
  //std::vector<float> mu1_;
  //af::array sigma0_;
  //af::array sigma1_;



  bool debug_ = false;



};