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

#pragma once

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

#if defined(IndependentDiscreteObject_RECURSES)
#error Recursive header files inclusion detected in IndependentDiscreteObject.h
#else // defined(IndependentDiscreteObject_RECURSES)
/** Prevents recursive inclusion of headers. */
#define IndependentDiscreteObject_RECURSES

#if !defined IndependentDiscreteObject_h
/** Prevents repeated inclusion of headers. */
#define IndependentDiscreteObject_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "ElementaryDiscreteObject"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

/////////////////////////////////////////////////////////////////////////////
// class IndependentDiscreteObject
/**
* Description of class 'IndependentDiscreteObject' <p>
* \brief Aim: It's a generic class for a Primitive wich is not attached to a upper group
*/
class IndependentDiscreteObject : ElementaryDiscreteObject
{
    // ----------------------- Standard services ------------------------------
public:

    /**
* Destructor.
*/
    ~IndependentDiscreteObject();

    // ----------------------- Interface --------------------------------------
public:

    /**
* Writes/Displays the object on an output stream.
* @param out the output stream where the object is written.
*/
    void selfDisplay ( std::ostream & out ) const;

    /**
* Checks the validity/consistency of the object.
* @return 'true' if the object is valid, 'false' otherwise.
*/
    bool isValid() const;

    // ------------------------- Protected Datas ------------------------------
private:
    // ------------------------- Private Datas --------------------------------
private:

    // ------------------------- Hidden services ------------------------------
protected:

    /**
* Constructor.
* Forbidden by default (protected to avoid g++ warnings).
*/
    IndependentDiscreteObject();

private:

    /**
* Copy constructor.
* @param other the object to clone.
* Forbidden by default.
*/
    IndependentDiscreteObject ( const XXX & other );

    /**
* Assignment.
* @param other the object to copy.
* @return a reference on 'this'.
* Forbidden by default.
*/
    IndependentDiscreteObject & operator= ( const XXX & other );

    // ------------------------- Internals ------------------------------------
private:

}; // end of class IndependentDiscreteObject


/**
* Overloads 'operator<<' for displaying objects of class 'IndependentDiscreteObject'.
* @param out the output stream where the object is written.
* @param object the object of class 'IndependentDiscreteObject' to write.
* @return the output stream after the writing.
*/
std::ostream&
operator<< ( std::ostream & out, const IndependentDiscreteObject & object );


} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#if !defined(BUILD_INLINE)
#include "IndependentDiscreteObject.ih"
#endif


// //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined IndependentDiscreteObject_h

#undef IndependentDiscreteObject_RECURSES
#endif // else defined(IndependentDiscreteObject_RECURSES)
