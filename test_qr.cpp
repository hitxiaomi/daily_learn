//
// Created by xiaomi on 7/31/19.
//


#include <iostream>
#include <Eigen/Geometry>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/SVD>
#include <Eigen/QR>






int main(int argc ,char** argv ){
    Eigen::Matrix3d k;
    k<<1,1,1,
        2,-1,-1,
        2,-4,5;
    Eigen::HouseholderQR<Eigen::Matrix3d> qr;
    qr.compute(k);
    Eigen::Matrix3d R=qr.matrixQR().triangularView<Eigen::Upper>();
    Eigen::Matrix3d Q=qr.householderQ();
    std::cout<<"k:"<<k<<std::endl;

    std::cout<<"qr.matricQR:"<<qr.matrixQR()<<std::endl;
    std::cout<<"Q:"<<Q<<std::endl;
    std::cout<<"R:"<<R<<std::endl;
    std::cout<<"Q*R:"<<Q*R<<std::endl;

    return 0;

}