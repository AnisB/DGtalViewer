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
* @file CameraMan.h
* @author Anis Benyoub (\c anis.benyoub@insa-lyon.fr )
* INSTITUTION
*
* @date 2012/06/10
*
* Header file for module CameraMan.cpp
*
* This file is part of the DGtal library.
*/



#if defined(CameraMan_RECURSES)
#error Recursive header files inclusion detected in CameraMan.h
#else // defined(CameraMan_RECURSES)
/** Prevents recursive inclusion of headers. */
#define CameraMan_RECURSES

#if !defined CameraMane_h
/** Prevents repeated inclusion of headers. */
#define CameraMan_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include "OGRE/Ogre.h"
#include "OIS/OIS.h"

//////////////////////////////////////////////////////////////////////////////
// Static variables
  
const double DefaultCameraSpeed =700;
const double DefaultCameraRotationSpeed =200;

//////////////////////////////////////////////////////////////////////////////

namespace DGtal
  {

/////////////////////////////////////////////////////////////////////////////
// class CameraMan
  /**
  * Description of class 'CameraMan' <p>
  * \brief Aim: Acts on the camera of the viewer
  */

class CameraMan
  {

    // ----------------------- Standard services ------------------------------
    public:
      /**
      * Constructor 
      */
      CameraMan ( Ogre::Camera * aCamera, int aSpeed = DefaultCameraSpeed, 
			      int aRotationSpeed = DefaultCameraRotationSpeed );

   
      /**
      * Destructor.
      */
       virtual ~CameraMan( );
       
        // ----------------------- Interface --------------------------------------
    public:

     /**
       * Public method that handles the user key press
      */ 
      bool handleKeyPress ( const OIS::KeyEvent & evt );
   
     /**
       * Public method that handles the user key Release
      */
      bool handleKeyRelease ( const OIS::KeyEvent & evt );
   
      
      
     /**
       * Public method that handles the user mouse move
      */  
      bool handleMouseMove ( const OIS::MouseEvent & evt );
      
      
      
      /**
       *  Public method that handles the user mouse click
      */   
      bool handleMouseClick ( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    
      
      /**
       *  Public method that handles the user mouse release
      */   
      bool handleMouseRelease ( const OIS::MouseEvent &e, OIS::MouseButtonID id );


      /**
       *  Public method that acts on the camera geometric attributes
      */  
      void Render ( const Ogre::FrameEvent & evt );

      
      
      
       //--------------------------- Protected attributes---------------------------
  
  
  protected :

    // The camera Object
    Ogre::Camera * myCamera;

    
    // Control flags
    bool isOnShiftMode;
    
    // Moving flags
    bool isGoingFoward;
    bool isGoingBackward;
    bool isGoingLeftward;
    bool isGoingRightward;
    Ogre::Vector3 TempMouseMove;

    // Moving attributes
    int mySpeed;
    int myRotationSpeed;



 


 // ------------------------- Hidden services ------------------------------
    protected:
    /**
     *  private method that starts a motion
    */ 
    
    // Starting a motion
    void startGoingFoward()
    {
      isGoingFoward=true;
    }
    void startGoingBackward()
    {
      isGoingBackward=true;
    }
    void startGoingLeftward()
    {
      isGoingLeftward=true;
    }
    void startGoingRightward()
    {
      isGoingRightward=true;
    }

    
   /**
     *  private method that starts a motion
    */ 
    
    // Ending a motion
    void stopGoingFoward()
    {
      isGoingFoward=false;
    }
    void stopGoingBackward()
    {
      isGoingBackward=false;
    }
    void stopGoingLeftward()
    {
      isGoingLeftward=false;
    }
    void stopGoingRightward()
    {
      isGoingRightward=false;
    }

    
   /**
     *  private method that adds a camera moving
    */ 
    void updateCamera ( double x, double y, double z );

  }; // end of class CameraMan

} // namespace DGtal



///////////////////////////////////////////////////////////////////////////////

#endif // !defined CameraMan_h

#undef CameraMan_RECURSES
#endif // else defined(CameraMan_RECURSES)





