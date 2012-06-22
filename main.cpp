



#include "ViewerOgre3D.h"
#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/shapes/Shapes.h"




using namespace DGtal;
using namespace DGtal::Z3i;

int main( int argc, char** argv )
{
 ViewerOgre3D View;

 Point p1( 0, 0, 0 );
 Point p2( 5, 5 ,5 );
 Point p3( 2, 3, 4 );
 
 Point p4( 30, 30 ,30 );
 Point p5( -30, -30 ,-30 );
 Domain domain( p4, p5 );


 View <<p1;
 View <<p2;
 View <<p3;

 DigitalSet shape_set1( domain );
 Shapes<Domain>::addNorm1Ball( shape_set1, Point( 7, 7, 7 ), 4 );
 View << shape_set1;


 DigitalSet shape_set2( domain );
 Shapes<Domain>::addNorm1Ball( shape_set2, Point( -10, -10, -10 ), 2 );
 View << shape_set2;
 
 
 View.Start();
 return 0;
}

