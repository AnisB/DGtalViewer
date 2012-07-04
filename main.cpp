/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**/

/**
* @file main.cpp
* @ingroup Tests
* @author Anis Benyoub (\c anis.benyoub@insa-lyon.fr )
* Liris CNRS
*
* @date 2012/06/26
*
* Functions for testing class ViewerOgre3D.
*
* This file is part of the DGtal library.
*/

///////////////////////////////////////////////////////////////////////////////
#include "ViewerOgre3D.h"
#include "DGtal/base/Common.h"
#include "DGtal/shapes/Shapes.h"
#include "DGtal/io/DrawWithDisplay3DModifier.h"
#include <iostream>
///////////////////////////////////////////////////////////////////////////////



void test3( )
{


  DGtal::ViewerOgre3D View;

  DGtal::Z3i::Point p4 ( 30, 30 , 30 );
  DGtal::Z3i::Point p5 ( -30, -30 , -30 );
  DGtal::Z3i::Domain domain ( p4, p5 );

  DGtal::Z3i::DigitalSet shape_set1 ( domain );
  DGtal::Shapes<DGtal::Z3i::Domain>::addNorm1Ball ( shape_set1, DGtal::Z3i::Point ( 7, 7, 7 ), 4 );

  View.manipulate ( shape_set1, setModify  , 1, 150, 5 );

}


void test1()
{
  DGtal::ViewerOgre3D View;

  DGtal::Z3i::Point p1 ( 0, 0, 0 );
  DGtal::Z3i::Point p2 ( 5, 5 , 5 );
  DGtal::Z3i::Point p3 ( 2, 3, 4 );

  DGtal::Z3i::Point p4 ( 30, 30 , 30 );
  DGtal::Z3i::Point p5 ( -30, -30 , -30 );
  DGtal::Z3i::Domain domain ( p4, p5 );


  View << p1;
  View << p2;
  View << p3;

  DGtal::Z3i::DigitalSet shape_set1 ( domain );
  DGtal::Shapes<DGtal::Z3i::Domain>::addNorm1Ball ( shape_set1, DGtal::Z3i::Point ( 7, 7, 7 ), 4 );
  View << shape_set1;


  DGtal::Z3i::DigitalSet shape_set2 ( domain );
  DGtal::Shapes<DGtal::Z3i::Domain>::addNorm1Ball ( shape_set2, DGtal::Z3i::Point ( -10, -10, -10 ), 2 );
  View << shape_set2;
  View.start();
}

void test2()
{
  DGtal::ViewerOgre3D View;

  DGtal::Z3i::Point p4 ( 30, 30 , 30 );
  DGtal::Z3i::Point p5 ( -30, -30 , -30 );
  DGtal::Z3i::Domain domain ( p4, p5 );

  DGtal::Z3i::DigitalSet shape_set1 ( domain );
  DGtal::Shapes<DGtal::Z3i::Domain>::addNorm1Ball ( shape_set1, DGtal::Z3i::Point ( 7, 7, 7 ), 4 );
  View << shape_set1;

  DGtal::Z3i::Point p10 ( 30, 30 , 30 );
  View << p10;

  View << DGtal::ClippingPlane ( 1, 0, 0, -4.9 );
  View << DGtal::ClippingPlane ( 0, 1, 0.3, -10 );
  View << CameraPosition ( 2.500000, 2.500000, 16.078199 )
  << CameraDirection ( 0.000000, 0.000000, -1.000000 )
  << CameraUpVector ( 0.000000, 1.000000, 0.000000 );
  View << CameraZNearFar ( 0.1, 200 );

  DGtal::Z3i::Point p1 ( 0, 0, 0 );
  DGtal::Z3i::Point p2 ( 0, 0 , 0 );


  /*
  cout<<" Begin Scene display "<<endl;
  View.sceneDisplay();
  cout<<" End scene display "<<endl;
  */


  View >> p1;

  View >> p2;

  shape_set1.erase ( p1 );
  shape_set1.erase ( p2 );
  View.clearScene();

// On met le nouvel objet
  View << shape_set1;
  View << p10;
  View.start();


}


int main ( int argc, char** argv )
{
  test1();
//  test2();
//  test3();

  return 0;
}