#include <iostream>
#include <vector>

#include <boost/geometry/algorithms/intersection.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

namespace geom = boost::geometry;

int main()
{
  // point in 2d cartesian c.s.
  typedef geom::model::d2::point_xy<double> point;
  // polygon of points, counterclockwise, open (i.e. last != first)
  typedef geom::model::polygon<point, false, false> polygon;

  polygon q4{{ {0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0} }};
  polygon t3{{ {0.2, 0.2}, {0.8, 0.2}, {0.2, 0.8} }};

  std::vector<polygon> N;
  geom::intersection(q4, t3, N);

  for (auto i = 0; i < N.size(); ++i) {
    std::cout << "polygon " << i << std::endl;
    const auto& polyNodes = N[i].outer();

    for (auto j = 0; j < polyNodes.size(); ++j) {
      const auto& nd = polyNodes[j];
      std::cout << "  node " << j << ": "
                << nd.get<0>() << " " << nd.get<1>() << std::endl;
    }

  }

  return 0;
}
