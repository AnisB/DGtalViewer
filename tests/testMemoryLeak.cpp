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
* @file testMemoryLeak.cpp
* @ingroup Tests
* @author Anis Benyoub (\c anis.benyoub@insa-lyon.fr )
* INSA Lyon
*
* @date 2012/06/13
*
* Functions for testing class testDGtalSet.
*
* This file is part of the DGtal library.
*/

///////////////////////////////////////////////////////////////////////////////
#include "../ViewerOgre3D.h"
#include "DGtal/base/Common.h"
#include "DGtal/shapes/Shapes.h"
#include <iostream>
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// Functions for testing class ViewerOgre3D.
///////////////////////////////////////////////////////////////////////////////
/**
* Example of a test. To be completed.
*
*/
bool testMemoryLeak()
{  
  new ViewerOgre3D();
  DGtal::ViewerOgre3D & View = DGtal::ViewerOgre3D::getSingleton();
  View.start();
  return true;
}

///////////////////////////////////////////////////////////////////////////////
// Standard services - public :

int main( int argc, char** argv )
{
  trace.beginBlock ( "Testing adding DGtalSet  for ViewerOgre3D" );
  bool res = testMemoryLeak(); 
  trace.emphase() << ( res ? "Passed." : "Error." ) << endl;
  trace.endBlock();
  return res ? 0 : 1;
}
