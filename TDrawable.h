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
* @file TDrawable.h
* @author Anis Benyoub (\c anis.benyoub@insa-lyon.fr )
* Liris CNRS
*
* @date 2012/06/26
*
* Implementation of methods defined in DrawableWithOgre.h
*
* This file is part of the DGtal library.
*/

#if defined(TDrawable_RECURSES)
#error Recursive header files inclusion detected in TDrawable.h
#else // defined(TDrawable_RECURSES)
/** Prevents recursive inclusion of headers. */
#define TDrawable_RECURSES

#if !defined TDrawable_h
/** Prevents repeated inclusion of headers. */
#define TDrawable_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "DrawableWithOgre.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // template class TDrawable
  /**
* Description of template class 'TDrawable' <p>
* \brief Aim:
*/
  template <typename T> 
  class TDrawable : public DrawableWithOgre
  {
    // ----------------------- Standard services ------------------------------
  public :

/**
* Constructor.
*/
    TDrawable(T* anObject);
    

    /**
* Destructor.
*/
    ~TDrawable();

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
    
    
/**
* Returns the object's class name
*/   
virtual const char * className() const;



/**
* Returns the Dgtal object
*/  
T*  getDgtalObject() ;

    // ------------------------- Protected Datas ------------------------------
protected :
  T * myObject;
    // ------------------------- Private Datas --------------------------------
  private:

    // ------------------------- Hidden services ------------------------------
  protected:

    /**
* Constructor.
* Forbidden by default (protected to avoid g++ warnings).
*/
    TDrawable();

  private:

    /**
* Copy constructor.
* @param other the object to clone.
* Forbidden by default.
*/
    TDrawable ( const TDrawable & other );

    /**
* Assignment.
* @param other the object to copy.
* @return a reference on 'this'.
* Forbidden by default.
*/
    TDrawable & operator= ( const TDrawable & other );

    // ------------------------- Internals ------------------------------------
  private:

  }; // end of class TDrawable


  /**
* Overloads 'operator<<' for displaying objects of class 'TDrawable'.
* @param out the output stream where the object is written.
* @param object the object of class 'TDrawable' to write.
* @return the output stream after the writing.
*/
  template <typename T>
  std::ostream&
  operator<< ( std::ostream & out, const TDrawable<T> & object );

} // namespace DGTal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#include "TDrawable.ih"

// //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined TDrawable_h

#undef TDrawable_RECURSES
#endif // else defined(TDrawable_RECURSES)