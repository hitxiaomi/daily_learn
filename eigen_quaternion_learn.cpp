#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>



int main() {

    Eigen::AngleAxisd rotation_vector(M_PI/4,Eigen::Vector3d(0,0,1));

    Eigen::Vector3d p1(1,0,0);
    Eigen::Vector3d p1_rotated=rotation_vector*p1;
    std::cout<<p1_rotated<<std::endl;
    Eigen::Quaterniond q(rotation_vector);
//    std::cout<<q.w()<<"  "<<q.vec()<<q.coeffs()<<std::endl;
    Eigen::Quaterniond p;
    p.vec()=p1;
    p.w()=0;
    Eigen::Quaterniond p_rotated2=q*p*q.inverse();

    std::cout<<p_rotated2.vec()<<p_rotated2.w()<<std::endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}