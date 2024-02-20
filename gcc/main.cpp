#include <iostream>
#include <random>

#include "../octree.h"     

using namespace OrthoTree;

int main()
{
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_real_distribution<> dis(-0.5, 0.5);
  const int N=20;
  std::vector<Point3D> points={};
  for(int i=0;i<N;++i){
    points.push_back(Point3D{dis(gen), dis(gen), dis(gen)});
  }
  auto const bounding_box_m = BoundingBox3D{{-0.5,-0.5,-0.5}, {0.5,0.5,0.5}};
  OctreePointC octree_container = OctreePointC(points, /*maxdepth*/4, bounding_box_m, /*max_elems*/ 5);
  OctreePoint octree = octree_container.GetCore();
  octree.PrintStructure();
  octree.GetCoarseNeighbours(8);


  return 0;
}