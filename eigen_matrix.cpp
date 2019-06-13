//
// Created by xiaomi on 6/13/19.
//
#include <Eigen/Core>
#include<Eigen/Dense>
#include <iostream>
#define  MATRIX_SIZE 50
int main(int agrc,char **argv){
    Eigen::Matrix<double,2,3> matrix_23;
    Eigen::Vector3d v_3d;
    Eigen::Matrix3d matrix_3d;
    Eigen::MatrixXd matrix_xd;
    matrix_23<<1,2,3,4,5,6;
    std::cout<<matrix_23<<std::endl;
    std::cout<<matrix_23.trace();
    Eigen::Matrix<double, MATRIX_SIZE,MATRIX_SIZE> matrix_NN;
    matrix_NN=Eigen::MatrixXd::Random(MATRIX_SIZE,MATRIX_SIZE);
    Eigen::VectorXd  v_nd(MATRIX_SIZE);
    v_nd=Eigen::VectorXd::Random(MATRIX_SIZE);
    Eigen::VectorXd x(MATRIX_SIZE);
    x=matrix_NN.colPivHouseholderQr().solve(v_nd);
    std::cout<<"x :"<<x<<std::endl;

}

