#include <iostream>

#include "person.pb.h"
int main(int argc, char *argv[]) {
  daily_learn::proto::Person person;
  person.set_name("zhang san");
  person.set_age(10);
  *person.mutable_name() = "zhangsan";
  person.set_id(11111);
  std::cout << person.DebugString() << std::endl;
}
