#include "stdio.h"
#include "DGtalObjectContainer.h"
#include "DGtal/base/Common.h"
#include "DGtal/kernel/PointVector.h"
#include "DGtal/topology/Object.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/shapes/Shapes.h"


#include <list>
#include <iostream>
using namespace DGtal;
using namespace DGtal::Z3i;
int main()
{

	TDrawable<PointVector<2u,double> > * aPoint = new TDrawable<PointVector<2u,double> >;
	
	TDrawable< DigitalSetBySTLSet < Space > > * aPointSet=  new TDrawable< DigitalSetBySTLSet < Space > > ;
	
	std::list<TDrawableWithOgre *> thelist;
	thelist.push_back(aPoint);
	thelist.push_back(aPointSet);
	
	TDrawableWithOgre * anObject = thelist.front();
	TDrawable<PointVector<2u,double> > * thePoint = (TDrawable<PointVector<2u,double> > *) anObject;
	std::cout<<(thePoint->className())<<std::endl;
	
	TDrawableWithOgre * anObject2 = thelist.back();
	TDrawable< DigitalSetBySTLSet < Space > > * theSet = (TDrawable< DigitalSetBySTLSet < Space > > *) anObject2;
	std::cout<<(theSet->className())<<std::endl;
	
	return 0;
}
