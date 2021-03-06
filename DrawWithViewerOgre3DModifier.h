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
 * @file DrawWithViewerOgre3DModifier.h
   @author Anis Benyoub (\c anis.benyoub@insa-lyon.fr )
 * Liris CNRS
 *
 * @date 2012/07/11
 *
 * Header file for module DrawWithViewerOgre3DModifier.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(DrawWithViewerOgre3DModifier_RECURSES)
#error Recursive header files inclusion detected in DrawWithViewerOgre3DModifier.h
#else // defined(DrawWithViewerOgre3DModifier_RECURSES)
/** Prevents recursive inclusion of headers. */
#define DrawWithViewerOgre3DModifier_RECURSES

#if !defined DrawWithViewerOgre3DModifier_h
/** Prevents repeated inclusion of headers. */
#define DrawWithViewerOgre3DModifier_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "CommonOgre.h"
#include "DGtal/base/CountedPtr.h"
#include "ViewerOgre3D.h"

//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{
   

 /**
   *@brief Base class specifying the methods for classes which intend to
   * modify a ViewerOgre3D stream.
   * 
   */
  struct DrawWithViewerOgre3DModifier {
    virtual std::string className() const
    {
      return "DrawWithViewerOgre3DModifier";
    }

  };




  /**
   * @brief Modifier class in a Display3D stream. Useful to choose your
   * own mode for a given class. Realizes the concept
   * CDrawableWithDisplay3D.
   */
  
  struct SetViewerMode3D : public DrawWithViewerOgre3DModifier {
    /**
     * @param classname the name of the class to which the style is associated.
     *
     * @param mode the name of the new mode.
     */
    SetViewerMode3D( std::string classname, std::string mode )
      : myClassname( classname ), myMode( mode )
    {}
    

    std::string myClassname;
    std::string myMode;
  };




  /**
   * @brief Modifier class in a Display3D stream. Useful to choose your own
   * style for a given class. Realizes the concept
   * CDrawableWithDisplay3D.
   */
  struct CustomViewerStyle3D {
    /**
     * @param classname the name of the class to which the style is associated.
     *
     * @param style a pointer on a dynamically allocated style, which
     * is acquired by the class.
     */
    CustomViewerStyle3D( std::string classname, DrawableWithViewerOgre3D* style )
      : myClassname( classname ), myStyle( style )
    {}

    std::string className() const
    {
      return "CustomViewerStyle3D";
    }

    virtual void setStyle()
    {
      
    }

    std::string myClassname;
    CountedPtr<DrawableWithViewerOgre3D> myStyle;
  };



  
  /**
   * @brief Custom style class redefining the fill color and the
   * gl_LINE/gl_POINT color. You can use DGtal::Color with alpha
   * transparency value but you nedd to take into account the z-buffer
   * during the Open-GL based rendering.
   *
   \code
   Display3D display;
   display << CustomColors3D(Color(250, 0,0),Color(250, 0,0));
   ...
   \endcode
   * @see Display3D
   */
  struct CustomViewerColors3D : public DrawableWithViewerOgre3D
  {
       DGtal::Color myCurrentSelfIlluminationColor;
       DGtal::Color myCurrentAmbientIlluminationColor;
       DGtal::Color myCurrentDiphuseIlluminationColor;
       DGtal::Color myCurrentSpecularIlluminationColor;
       std::string myTexture;


    /**
     * Constructor.
     *
     * @param penColor specifies the pen color.
     * @param fillColor specifies the fill color.
     */
    CustomViewerColors3D( const Color &  aSelfIlluminationColor,
       const Color &  aAmbientIlluminationColor,
       const Color &  aDiphuseIlluminationColor,
      const Color & aSpecularIlluminationColor,
      std::string  aTexture)
      :  myCurrentSelfIlluminationColor(aSelfIlluminationColor),
        myCurrentAmbientIlluminationColor(aAmbientIlluminationColor),
        myCurrentDiphuseIlluminationColor(aDiphuseIlluminationColor),
        myCurrentSpecularIlluminationColor(aSpecularIlluminationColor),
        myTexture(aTexture)
    {}

      std::string className() const
      {
	return "CustomViewerColors3D";
      }

      virtual void setStyle( ViewerOgre3D & aViewer ) const 
      {
	    aViewer.setSelfIlluminationColor(myCurrentSelfIlluminationColor);
	    aViewer.setAmbientIlluminationColor(myCurrentAmbientIlluminationColor);
	    aViewer.setDiphuseIlluminationColor(myCurrentDiphuseIlluminationColor);
	    aViewer.setSpecularIlluminationColor(myCurrentSpecularIlluminationColor);
	    aViewer.setTexture(myTexture);
      }
  };



  
 /**
  * @brief Class for adding a Clipping plane through the Viewer3D
  * stream. Realizes the concept CDrawableWithViewer3D.
  */
  
  struct ViewerClippingPlane : public DrawWithViewerOgre3DModifier {
    /**
     * @param classname the name of the class to which the style is associated.
     *
     * @param style a pointer on a dynamically allocated style, which
     * is acquired by the class.
     */
    ViewerClippingPlane( double a, double b, double c, double d, bool drawPlane=true )
      : myA( a ), myB( b ), myC( c ), myD ( d ), myDrawPlane(drawPlane)  
    {}
    
    // MT: why setStyleViewer3D here and not setStyleDisplay3D ???
    /*void setStyleViewer3D( Display3D & display ) const
    {
      display.addClippingPlane(myA, myB, myC, myD, myDrawPlane);
    }*/
    
    double * getEquation(){
      double *r = new double[4];
      r[0] = myA;
      r[1] = myB;
      r[2] = myC;
      r[3] = myD;
      return r;
    } 
    
    double myA;
    double myB;
    double myC;
    double myD;
    bool myDrawPlane;
  };


  /**
   * @brief  CameraPosition class to set camera position.
   */
  struct ViewerCameraPosition : public DrawWithViewerOgre3DModifier
  {
    /**
     * Constructor.
     *
     * @param x x position.
     * @param y y position.
     * @param z z position.
     */
    ViewerCameraPosition( const double x, const double y, const double z )
    {
      eyex=x; eyey=y; eyez=z;
    }
    
    /*void setStyleDisplay3D( Display3D & display) const
    {
      display.setCameraPosition(eyex, eyey, eyez);
    }*/
    
      double eyex, eyey, eyez;
  };
  
  /**
   * @brief CameraDirection class to set camera direction.
   */
  struct ViewerCameraDirection : public DrawWithViewerOgre3DModifier
  {
    /**
     * Constructor.
     *
     * @param x x direction.
     * @param y y direction.
     * @param z z direction.
     */
    ViewerCameraDirection( const double x, const double y, const double z )
    {
      dirx=x; diry=y; dirz=z;
    }
    
    /*virtual void setStyleDisplay3D( Display3D & display) const
    {
      display.setCameraDirection(dirx, diry, dirz);
    }*/
    
      double dirx, diry, dirz;
  };
  
  /**
   * @brief CameraUpVector class to set camera up-vector.
   */
  struct ViewerCameraUpVector : public DrawWithViewerOgre3DModifier
  {
    /**
     * Constructor.
     *
     * @param x x coordinate of up-vector.
     * @param y y coordinate of up-vector.
     * @param z z coordinate of up-vector.
     */
   ViewerCameraUpVector( const double x, const double y, const double z )
    {
      upx=x; upy=y; upz=z;
    }
    
    /*virtual void setStyleDisplay3D( Display3D & viewer) const
    {
      viewer.setCameraUpVector(upx, upy, upz);
    }*/
    
      double upx, upy, upz;
  };
  
  /**
   * @brief CameraZNearFar class to set near and far distance.
   */
  struct ViewerCameraZNearFar : public DrawWithViewerOgre3DModifier
  {
    /**
     * Constructor.
     *
     * @param near near distance.
     * @param far far distance.
     */
    ViewerCameraZNearFar( const double _near, const double _far )
    {
      ZNear=_near; ZFar=_far;
    }
    
    /*virtual void setStyleDisplay3D( Display3D & viewer) const
    {
      viewer.setNearFar(ZNear, ZFar);
    }*/
    
      double ZNear, ZFar;
  };

 



} // namespace DGtal




//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#endif // !defined DrawWithDisplay3DModifier_h

#undef DrawWithDisplay3DModifier_RECURSES
#endif // else defined(DrawWithDisplay3DModifier_RECURSES)