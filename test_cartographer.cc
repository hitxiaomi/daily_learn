
#include <glog/logging.h>

#include <random>

#include "cartographer/mapping/2d/probability_grid.h"
#include "cartographer/mapping/2d/submap_2d.h"
#include "cartographer/mapping/probability_values.h"
int main(int argc, char** argv) {
  //   FLAGS_logtostderr = true;
  FLAGS_alsologtostderr = true;
  FLAGS_colorlogtostderr = true;
  //   cartographer::mapping::proto::Grid2D proto;
  const cartographer::mapping::MapLimits limits(
      1.0, {2.0, 3.0}, cartographer::mapping::CellLimits(4., 5.));
  auto proto = cartographer::mapping::ToProto(limits);
  CHECK_EQ(proto.resolution(), limits.resolution());
  LOG(INFO) << proto.resolution() << "," << limits.resolution();
  LOG(ERROR) << proto.resolution() << "," << limits.resolution();

  std::cout << "hello world" << std::endl;
}