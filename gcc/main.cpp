#include <iostream>
#include <random>

#include "../octree.h"     

using namespace OrthoTree;

int main()
{
  std::vector<Point3D> points={};
  
  /*
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_real_distribution<> dis(-0.5, 0.5);
  const int N=50;
  for(int i=0;i<N;++i){
    points.push_back(Point3D{dis(gen), dis(gen), dis(gen)});
  }
  */

  points.push_back(Point3D{0.1,0.13,0.1});
  points.push_back(Point3D{0.1,0.2,0.1});
  points.push_back(Point3D{0.1,0.1,0.1});
  //points.push_back(Point3D{-0.499,-0.499,0.001});
  points.push_back(Point3D{-0.1,-0.1,0.4});
  auto const bounding_box_m = BoundingBox3D{{-0.5,-0.5,-0.5}, {0.5,0.5,0.5}};
  OctreePointC octree_container = OctreePointC(points, /*maxdepth*/4, bounding_box_m, /*max_elems*/ 3);
  OctreePoint octree = octree_container.GetCore();
  octree.PrintStructure();
  octree.BalanceOctree(points);
  octree.PrintStructure();
  
  return 0;
}