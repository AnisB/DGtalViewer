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
#include "DrawableWithOgreWrapper.h"
#include "DGtal/io/DrawWithDisplay3DModifier.h"
#include "DGtal/geometry/curves/representation/ArithmeticalDSS3d.h"
#include "DGtal/kernel/sets/DigitalSetBySTLSet.h"
#include "DGtal/kernel/sets/DigitalSetBySTLVector.h"
#include "DGtal/kernel/domains/HyperRectDomain.h"
#include "DGtal/topology/KhalimskySpaceND.h"
#include "DGtal/topology/Object.h"
#include "DGtal/kernel/PointVector.h"

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
      // ArithmeticalDSS
      template < typename TIterator,typename TInteger, int connectivity>
      static void draw ( ViewerOgre3D & display, const DGtal::ArithmeticalDSS3d <TIterator, TInteger,connectivity> & c);
      
      //DGtalSetBySTLSet
      template<typename Domain>
      static void draw( ViewerOgre3D & viewer, const DGtal::DigitalSetBySTLSet<Domain> & s );
      
      //DigitalSetBySTLVector
      template<typename Domain>
      static void draw( ViewerOgre3D & viewer, const DGtal::DigitalSetBySTLVector<Domain> & s );
      
      
      //HyperRectDomain      
      template<typename TSpace>
      static void draw( ViewerOgre3D & viewer, const DGtal::HyperRectDomain<TSpace> & s );
 
      //KhalimskyCell
      template<Dimension dim, typename TInteger>
      static void draw ( ViewerOgre3D & display, const DGtal::KhalimskyCell<dim,TInteger> & kc );
      
      
      //Object
      template <typename TDigitalTopology, typename TDigitalSet>
      static void draw (ViewerOgre3D &display, const DGtal::Object< TDigitalTopology, TDigitalSet > &);
      
      //PointVector
      template<Dimension dim, typename TComponent>
      static void draw ( ViewerOgre3D & display, const PointVector<dim,TComponent> & );
      
      
     //SignedKhalimskyCell
     template< Dimension dim,typename TInteger>
     static void draw ( ViewerOgre3D & display, const DGtal::SignedKhalimskyCell<dim,TInteger> & skc);
     
     
     

  /*
     static void draw( ViewerOgre3D & display, const DGtal::SetMode3D & );
     static void draw( ViewerOgre3D & display, const DGtal::CustomStyle3D & );
     static void draw( ViewerOgre3D & display, const DGtal::CustomColors3D & );
 */
  
     static void draw( ViewerOgre3D & display, const DGtal::ClippingPlane & );
     //Camera 
     static void draw( ViewerOgre3D & display, const DGtal::CameraPosition & );
     static void draw( ViewerOgre3D & display, const DGtal::CameraDirection & );
     static void draw( ViewerOgre3D & display, const DGtal::CameraUpVector & );
     static void draw( ViewerOgre3D & display, const DGtal::CameraZNearFar & );

      


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
