//
// Created by xiaomi on 7/3/19.
//

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <iostream>

int main(int argc,char** argv){


    Eigen::AngleAxisd rotation_vector(M_PI/4,Eigen::Vector3d(0,0,1));

    std::cout<<"origin rotation matrix"<<std::endl;
    std::cout<<rotation_vector.toRotationMatrix()<<std::endl;

    Eigen::Vector3d w(0.01,0.02,0.03);


    Eigen::AngleAxisd update_so3(w.norm(),w.normalized());

    Eigen::Matrix3d rotation_matrix_update_by_exp=rotation_vector.toRotationMatrix()*update_so3.toRotationMatrix();


    std::cout<<"after update by exp map:"<<std::endl;
    std::cout<<rotation_matrix_update_by_exp<<std::endl;


    Eigen::Quaterniond origin_quaternion(rotation_vector);

    Eigen::Quaterniond update_quaternion(1,0.5*w[0],0.5*w[1],0.5*w[2]);

    Eigen::Quaterniond quaterniond_after_update=origin_quaternion*update_quaternion;

    Eigen::Quaterniond quaterniond_norm=quaterniond_after_update.normalized();
    std::cout<<"after update by small quaternion"<<std::endl;
    std::cout<<quaterniond_norm.toRotationMatrix()<<std::endl;

    std::cout<<"if quaternion not normilzed"<<std::endl;
    std::cout<<quaterniond_after_update.toRotationMatrix()<<std::endl;















    return  0;
}