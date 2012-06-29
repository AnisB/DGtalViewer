



#include "ViewerOgre3D.h"
#include "DGtal/base/Common.h"
#include "DGtal/shapes/Shapes.h"



int main( int argc, char** argv )
{
  
 /*
 DGtal::ViewerOgre3D View;

 DGtal::Z3i::Point p1( 0, 0, 0 );
 DGtal::Z3i::Point p2( 5, 5 ,5 );
 DGtal::Z3i::Point p3( 2, 3, 4 );
 
 DGtal::Z3i::Point p4( 30, 30 ,30 );
 DGtal::Z3i::Point p5( -30, -30 ,-30 );
 DGtal::Z3i::Domain domain( p4, p5 );


 View <<p1;
 View <<p2;
 View <<p3;

 DGtal::Z3i::DigitalSet shape_set1( domain );
 DGtal::Shapes<DGtal::Z3i::Domain>::addNorm1Ball( shape_set1, DGtal::Z3i::Point( 7, 7, 7 ), 4 );
 View << shape_set1;


 DGtal::Z3i::DigitalSet shape_set2( domain );
 DGtal::Shapes<DGtal::Z3i::Domain>::addNorm1Ball( shape_set2, DGtal::Z3i::Point( -10, -10, -10 ), 2 );
 View << shape_set2;
 View.Start();*/
 
 DGtal::ViewerOgre3D View;
  
 DGtal::Z3i::Point p4( 30, 30 ,30 );
 DGtal::Z3i::Point p5( -30, -30 ,-30 );
 DGtal::Z3i::Domain domain( p4, p5 );
 
 DGtal::Z3i::DigitalSet shape_set1( domain );
 DGtal::Shapes<DGtal::Z3i::Domain>::addNorm1Ball( shape_set1, DGtal::Z3i::Point( 7, 7, 7 ), 4 );
 View << shape_set1;
 
 DGtal::Z3i::Point p10( 30, 30 ,30);
 View <<p10;

 
 DGtal::Z3i::Point p1( 0, 0, 0 );
 DGtal::Z3i::Point p2( 0, 0 ,0 );

 
 /*
 cout<<" Begin Scene display "<<endl;
 View.sceneDisplay();
 cout<<" End scene display "<<endl;
*/
 
 
 View>>p1;

 View>>p2;



 shape_set1.erase(p1);
 shape_set1.erase(p2);
 View.ClearScene();
 
// On met le nouvel objet
 View<<shape_set1;
 View <<p10;

 View.functionApply(p10, translatePoint  ,10, 50);
 
 View.Start();
 return 0;
}

