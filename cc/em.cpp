#include "em.h"






EM::EM() {
    srand (static_cast <unsigned> (time(0)));
};



EM::~EM() {};



void EM::InitializeRandomParams(unsigned int n){

  phi_ = std::vector<float>(1, static_cast <float> (rand()) / static_cast <float> (RAND_MAX));

  //mu0_ = std::vector<float>(2, static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
  //mu1_ = std::vector<float>(2, static_cast <float> (rand()) / static_cast <float> (RAND_MAX));

  //for (unsigned int i=0; i<2; i++) {
  //  mu0_.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
  //  mu1_.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
  //}

  //sigma0_ = af::randn(n, n);
  //sigma0_ = af::matmulNT(sigma0_, sigma0_);
  //sigma1_ = af::randn(n, n);
  //sigma1_ = af::matmulNT(sigma1_, sigma1_);

  phi_ = Eigen::VectorXd::Random(1,1);
  mean0_ = Eigen::VectorXd(1, n);
  sigma0_ = Eigen::MatrixXd(n, n);
  mean1_ = Eigen::VectorXd(1, n);
  sigma1_ = Eigen::MatrixXd(n, n);
}




//unsupervised_forecastsforecasts, unsupervised_posterior, unsupervised_loglikelihoods = run_em(x_unlabeled, random_params)

void EM::RunEM(std::vector<std::vector<float>> &data) {

  std::vector<std::vector<float>> avg_loglikelihoods;

  while(1) {
    std::vector<float> avg_loglikelihood = GetAvgLogLikelihood(data);
    avg_loglikelihoods.push_back(avg_loglikelihood);






  }
}


std::vector<float> EM::GetAvgLogLikelihood(std::vector<std::vector<float>> &x) {
  std::vector<float> loglikelihood = E_Step(x);




}


std::vector<float> EM::E_Step(std::vector<std::vector<float>> &x) {
  double pdfval0 = pdf(x, mean0_, sigma0_);


}




double EM::pdf(const Eigen::VectorXd& x, 
                Eigen::VectorXd mean,
                Eigen::MatrixXd sigma ) const {
  double n = x.rows();
  double sqrt2pi = std::sqrt(2 * M_PI);
  double quadform  = (x - mean).transpose() * sigma.inverse() * (x - mean);
  double norm = std::pow(sqrt2pi, - n) *
                std::pow(sigma.determinant(), - 0.5);

  return norm * exp(-0.5 * quadform);
}



Eigen::VectorXd EM::sample(unsigned int nr_iterations) const
{
  double n = mean.rows();

  // Generate x from the N(0, I) distribution
  Eigen::VectorXd x(n);
  Eigen::VectorXd sum(n);
  sum.setZero();
  for (unsigned int i = 0; i < nr_iterations; i++)
  {
    x.setRandom();
    x = 0.5 * (x + Eigen::VectorXd::Ones(n));
    sum = sum + x;
  }
  sum = sum - (static_cast<double>(nr_iterations) / 2) * Eigen::VectorXd::Ones(n);
  x = sum / (std::sqrt(static_cast<double>(nr_iterations) / 12));

  // Find the eigen vectors of the covariance matrix
  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigen_solver(sigma);
  Eigen::MatrixXd eigenvectors = eigen_solver.eigenvectors().real();

  // Find the eigenvalues of the covariance matrix
  Eigen::MatrixXd eigenvalues = eigen_solver.eigenvalues().real().asDiagonal();
  
  // Find the transformation matrix
  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> es(eigenvalues);
  Eigen::MatrixXd sqrt_eigenvalues = es.operatorSqrt();
  Eigen::MatrixXd Q = eigenvectors * sqrt_eigenvalues;

  return Q * x + mean;
}