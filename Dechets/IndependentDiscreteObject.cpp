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
* @file IndependentDiscreteObject.h
* @author Anis Benyoub (\c anis.benyoub@insa-lyon.fr )
* INSTITUTION
*
* @date 2012/06/14
*
* Header file for module IndependentDiscreteObject.cpp
*
* This file is part of the DGtal library.
*/

///////////////////////////////////////////////////////////////////////////////
#include "IndependentDiscreteObject.h"
// Includes inline functions/methods if necessary.
#if !defined(BUILD_INLINE)
#include "IndependentDiscreteObject.ih"
#endif
///////////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// class IndependentDiscreteObject
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Standard services - public :

/**
* Destructor.
*/
DGtal::IndependentDiscreteObject::~IndependentDiscreteObject()
{
}



///////////////////////////////////////////////////////////////////////////////
// Interface - public :

/**
* Writes/Displays the object on an output stream.
* @param out the output stream where the object is written.
*/
void
DGtal::IndependentDiscreteObject::selfDisplay ( std::ostream & out ) const
{
    out << "[IndependentDiscreteObject]";
}

/**
* Checks the validity/consistency of the object.
* @return 'true' if the object is valid, 'false' otherwise.
*/
bool
DGtal::IndependentDiscreteObject::isValid() const
{
    return true;
}



///////////////////////////////////////////////////////////////////////////////
// Internals - private :

// //
///////////////////////////////////////////////////////////////////////////////
