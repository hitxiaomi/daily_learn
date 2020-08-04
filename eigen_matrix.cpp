//
// Created by xiaomi on 6/13/19.
//
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#define MATRIX_SIZE 50

#include <Eigen/Geometry>
#include <Eigen/SVD>
using namespace Eigen;
using namespace std;

void test1() {
  Eigen::AngleAxisd angle_axis(M_PI / 2, Eigen::Vector3d::UnitZ());
  Eigen::Matrix3d R = angle_axis.toRotationMatrix();
  std::cout << R << std::endl;
  Eigen::Vector3d p1(0, 1, 0);
  Eigen::Vector3d p2 = R * p1;
  std::cout << p2 << std::endl;
}
void test2() {
  MatrixXf m = MatrixXf::Random(3, 3);
  cout << "Here is the matrix m:" << endl << m << endl;
  JacobiSVD<MatrixXf> svd(m, ComputeThinU | ComputeThinV);
  cout << "Its singular values are:" << endl << svd.singularValues() << endl;
  cout << "Its left singular vectors are the columns of the thin U matrix:"
       << endl
       << svd.matrixU() << endl;
  cout << "Its right singular vectors are the columns of the thin V matrix:"
       << endl
       << svd.matrixV() << endl;
  Vector3f rhs(1, 0, 0);
  cout << "Now consider this rhs vector:" << endl << rhs << endl;
  cout << "A least-squares solution of m*x = rhs is:" << endl
       << svd.solve(rhs) << endl;
}
void test3() {
  Eigen::Matrix<double, 2, 3> matrix_23;
  Eigen::Vector3d v_3d;
  Eigen::Matrix3d matrix_3d;
  Eigen::MatrixXd matrix_xd;
  matrix_23 << 1, 2, 3, 4, 5, 6;
  std::cout << matrix_23 << std::endl;
  std::cout << matrix_23.trace();
  Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN;
  matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
  Eigen::VectorXd v_nd(MATRIX_SIZE);
  v_nd = Eigen::VectorXd::Random(MATRIX_SIZE);
  Eigen::VectorXd x(MATRIX_SIZE);
  x = matrix_NN.colPivHouseholderQr().solve(v_nd);
  std::cout << "x :" << x << std::endl;
}
void test4() {
  class A {
   public:
    void FunctionA() {}
  };
  class B : public A {
   public:
    void FuntionB() {}
  };

  B* b = new B();
  b->FuntionB();
  A* a = b;
  a->FunctionA();
  delete b;
}
void test5() {}

int main(int agrc, char** argv) {
  Eigen::Rotation2D<float> rotation(M_PI / 2.0);
  std::cout << rotation.angle() << std::endl;

  std::cout << rotation.toRotationMatrix() << std::endl;
}
