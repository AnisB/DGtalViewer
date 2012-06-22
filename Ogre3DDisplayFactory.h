/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#pragma once

/**
 * @file   Ogre3DDisplayFactory.h
 * @author Anis Benyoub
 * @date   mercredi 14 juin 2012
 *
 * @brief
 *
 * Header file for module Ogre3DDisplayFactor
 *
 * This file is part of the DGtal library.
 */

#if defined(Ogre3DDisplayFactor_RECURSES)
#error Recursive header files inclusion detected in Ogre3DDisplayFactor.h
#else // defined(Ogre3DDisplayFactor_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Ogre3DDisplayFactor_RECURSES

#if !defined Ogre3DDisplayFactor_h
/** Prevents repeated inclusion of headers. */
#define Ogre3DDisplayFactor_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions

#include "DGtal/base/Common.h"
#include "DGtal/kernel/PointVector.h"
#include "DGtal/topology/Object.h"


namespace DGtal
  {

  class ViewerOgre3D;




/////////////////////////////////////////////////////////////////////////////
  struct Ogre3DDisplayFactory
        /**
         * Description of struct 'Ogre3DDisplayFactor' <p>
         * \brief Ogre Factory for Display3D:
         */
    {

      template<Dimension dim, typename TComponent>
      static void draw ( ViewerOgre3D & display, const PointVector<dim,TComponent> & );
      
      
      template <typename TDigitalTopology, typename TDigitalSet>
      static void draw (ViewerOgre3D &display, const DGtal::Object< TDigitalTopology, TDigitalSet > &);
      
      template<typename Domain>
      static void draw( ViewerOgre3D & viewer, 
									  const DGtal::DigitalSetBySTLSet<Domain> & s );
    }; // end of struct Ogre3DDisplayFactor

} //  namespace DGtal




///////////////////////////////////////////////////////////////////////////////
// Includes inline functions/methods
#include "ViewerOgre3D.h"
#include "Ogre3DDisplayFactory.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined Ogre3DDisplayFactor_h

#undef Ogre3DDisplayFactor_RECURSES
#endif // else defined(Ogre3DDisplayFactor_RECURSES)
