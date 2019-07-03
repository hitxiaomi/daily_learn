//
// Created by xiaomi on 7/3/19.
//

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <iostream>

int main(int argc,char** argv){

    //通过旋转向量，建立初始的旋转矩阵,绕z轴旋转45度
    Eigen::AngleAxisd rotation_vector_origin(M_PI/4,Eigen::Vector3d(0,0,1));
    std::cout<<"origin rotation matrix"<<std::endl;
    std::cout<<rotation_vector_origin.toRotationMatrix()<<std::endl;


    //更新量
    Eigen::Vector3d w(0.01,0.02,0.03);
    Eigen::AngleAxisd update_exp(w.norm(),w.normalized());//利用更新量构建旋转向量，这个旋转向量也是对应的李代数

    //更新旋转矩阵,toRotationMatrix()方法应该就是将旋转向量通过罗德里格斯公式转化为旋转矩阵。
    Eigen::Matrix3d rotation_matrix_update_by_exp=rotation_vector_origin.toRotationMatrix()*update_exp.toRotationMatrix();


    std::cout<<std::endl<<"after update by exp map:"<<std::endl;
    std::cout<<rotation_matrix_update_by_exp<<std::endl;


    //初始的四元数
    Eigen::Quaterniond origin_quaternion(rotation_vector_origin);

    //更新量对应的四元数
    Eigen::Quaterniond update_quaternion(1,0.5*w[0],0.5*w[1],0.5*w[2]);

    Eigen::Quaterniond quaternion_after_update=origin_quaternion*update_quaternion;
    Eigen::Quaterniond quaternion_normalized=quaternion_after_update.normalized();


    std::cout<<std::endl<<"after update by small quaternion_normalized"<<std::endl;
    std::cout<<quaternion_normalized.toRotationMatrix()<<std::endl;

    std::cout<<std::endl<<"if not normilzed"<<std::endl;
    std::cout<<quaternion_after_update.toRotationMatrix()<<std::endl;















    return  0;
}