//
// Created by xiaomi on 8/5/19.
//

#include <vector>
#include <memory>
#include <iostream>
using namespace std;


class A{
public:
    int a_;
    A(int a=0):a_(a){}
    ~A(){ std::cout<<"A destructor  "<< a_<<std::endl;}

};






int main(){

    A* raw_pointer=new A(0);
    shared_ptr<A> sp3(raw_pointer);
    shared_ptr<A> sp4(raw_pointer);

    std::cout<<"sp1 use count"<<sp3.use_count()<<std::endl;
    std::cout<<"sp2 use count"<<sp4.use_count()<<std::endl;

    std::shared_ptr<A> sp1(new A(1)) ;
    std::cout<<"sp1 use count"<<sp1.use_count()<<std::endl;

    sp1.reset();
    sp1=std::make_shared<A>(2);



    std::shared_ptr<A> sp2=sp1;

    std::cout<<"sp1 use count"<<sp1.use_count()<<std::endl;
    std::cout<<"sp2 use count"<<sp2.use_count()<<std::endl;


    if(sp1==sp2){
        std::cout<<"sp1  and sp2 pointing to same pointer"<<std::endl;
    }

    std::cout<<"sp1 reset"<<std::endl;

    sp1.reset();

    std::cout<<"sp1 use count"<<sp1.use_count()<<std::endl;
    std::cout<<"sp2 use count"<<sp2.use_count()<<std::endl;

    sp1=std::make_shared<A>(3);

    std::cout<<"sp1 use count"<<sp1.use_count()<<std::endl;
    std::cout<<"sp2 use count"<<sp2.use_count()<<std::endl;

    sp1= nullptr;

    std::cout<<"sp1 use count"<<sp1.use_count()<<std::endl;
    std::cout<<"sp2 use count"<<sp2.use_count()<<std::endl;




    std::cout<<" end of program"<<std::endl;
    return  0;


}