#include "Octree.h"
#include "Timer.h"
std::vector<Object*> StaticObjectList;
std::vector<Object*> DynamicObjectList;

void SetStaticObject(Octree& tree) {

}



int main()
{
	Octree tree;

	tree.BuildOctree(0, 0, 0, 1000, 1000, 1000);
	


	return 0;
}

