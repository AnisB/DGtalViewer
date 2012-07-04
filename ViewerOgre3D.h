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
* @file ViewerOgre3D.h
* @author Anis Benyoub (\c anis.benyoub@insa-lyon.fr )
* Liris CNRS
*
* @date 2012/06/26
*
* Header file for module ViewerOgre3D.cpp
*
* This file is part of the DGtal library.
*/

#if defined(ViewerOgre3D_RECURSES)
#error Recursive header files inclusion detected in ViewerOgre3D.h
#else // defined(ViewerOgre3D_RECURSES)
/** Prevents recursive inclusion of headers. */
#define ViewerOgre3D_RECURSES

#if !defined ViewerOgre3D_h
/** Prevents repeated inclusion of headers. */
#define ViewerOgre3D_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "OGRE/Ogre.h"
#include <list>
#include <DGtal/io/Color.h>
#include "DGtal/base/Common.h"
#include "OgreEntity.h"
#include "DGtalNode.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{
class Ogre3DDisplayFactory;

class InputListener;

const double scaleFactor= 40.0;
/////////////////////////////////////////////////////////////////////////////
// class XXX
/**
* Description of class 'ViewerOgre3D' <p>
* \brief Aim: The new viewer for DGtal
*/


class ViewerOgre3D 
{
	
    // ----------------------- Standard services ------------------------------
public:

      /**
       *  Constructor.
       */
      ViewerOgre3D();
      
      /**
       *  Destructor.
       */
      virtual ~ViewerOgre3D();
      
      
      /**
       *  Rendering launch method.
       */      
      void start();
      
      
      /**
       * Initiate ressources 
       */
      void initMaterials();
      
      
      /**
       *  Config initiate
       */      
      bool initConfigs();
      
      /**
       *  Scene create
       */      
      void createScene();
      
      
      /**
       *  Frame listenner creartion
       */
      void createFrameListener();
      
      
      
      /**
       *  Get a son node ( of the root one)
       */
      Ogre::SceneNode * getANode();
      
      
      /**
       *  get the root scene node (Ogre)
       */
      Ogre::SceneNode * getRootSceneNode() { return mSceneMgr->getRootSceneNode();}
      
      
      /**
       *  get the root scene node (DGtal one) 
       */
      DGtalNode * getRootDGtalNode() { return mRootNode;}
      
      
      
      /**
       *  Add a DgtalNode to the list
       */
      void addToList(DGtalNode * anObject);
      
      
      /**
       *  Flips the axis visibility .
       */
      void changeAxisVisibility();
      
      
      /**
       *  Set the near and far clip distance of the camera
       */
      void setNearFar(double near,double far);
      
      
      /**
       *  set's the camera upvector
       */
      void setCameraUpVector(Ogre::Vector3   anUp);
      
      
      /**
       *  Set's the camera Direction
       */
      void setCameraDirection(Ogre::Vector3   aPoint);
      
      
      /**
       *  Set's the camera position
       */
      void setCameraPosition(Ogre::Vector3   aPosition);
      
      /**
       *  Returns back a pointer to the scene manager
       */
      Ogre::SceneManager * getSceneMgr() { return mSceneMgr;}		
      
      
      /**
       *  looks for a point and changes the current selection if found (x, y) 
       *  the mouse coordinates and (h,w) the window dimension
       */
      void LookForIt(unsigned int x,unsigned int y,unsigned int h,unsigned int w);
      
      
      /**
       *  Find the representation coressponding to a point
       */
      Representation * findRepresentation(std::string aName);
      
      
      /**
       *  adds a clipping plane
       */
      void addClippingPlane(double a,double b,double c, double d); 
      
      
      /**
       *  adds a voxel
       */
      Representation  * addVoxel(double x,double y, double z,Ogre::SceneNode * aNode);
      
      
      /**
       *  adds a line
       */
      Representation * addLine(double x1, double y1, double z1, double x2, double y2,double z2,Ogre::SceneNode * aNode);
      
      /**
       *  adds a point
       */
      Representation * addPoint (double x, double y, double z,Ogre::SceneNode * aNode );
      
      
      /**
       *  adds a kalimsky surfel
       */
      Representation * addKSSurfel (double x, double y, double z,Ogre::SceneNode * aNode);
      
      /**
       *  adds a kalimsky voxel
       */
      Representation * addKSVoxel (int x, int y, int z,Ogre::SceneNode * aNode);
      
      
      /**
       * adds a kalimsky pointel
       */
      Representation * addKSPointel (double x, double y, double z,Ogre::SceneNode * aNode);
      
      /** 
       * adds a kalimsky pointel
       */
      Representation * addKSLinel (double x1, double y1, double z1,Ogre::SceneNode * aNode);
      
      
      /**
       *  clears the scene
       */
      void clearScene();
      
      
      /**
       *   Displays the scene
       */
      void sceneDisplay();
      
      /**
       *  Tells if we are in the manipulating mode
       */
      bool isInManupulatingMode() {return myManupilatingFlag;}
      
      
      /**
       *  updates the manipulating value
       */
      void newManipulatingValue(int change);
      
      
      /**
       *   Returns the scene center
       */
      Ogre::Vector3 getSceneCenter(){ return mySceneCenter;}
      
      
      /**
       *  sets the scene center
       */
      Ogre::Vector3 setSceneCenter(Ogre::Vector3 & aVector)
      {  
	      mySceneCenter= aVector;
	      myWristNode->setPosition(mySceneCenter);
      }
      
      /**
       *   Returns the lower point of the scene
       */
      Ogre::Vector3 getLowerPosition();
      
      
      /**
       *  Returns the lower point
       */
      Ogre::Vector3 getUpperPosition();
      
      
      /**
       *  Stops the manipulating mode
       */
      void abortManupulating();
  
      /**
       *  Sets the color
       */
      ViewerOgre3D & operator<< ( const DGtal::Color & aColor );
      
      /**
       *  adding dgtal objects to the scene
       */
      template <typename TDrawableWithDisplay3D>
      ViewerOgre3D & operator<< ( const  TDrawableWithDisplay3D & object );
      
      /**
       *  Returns a dgtal object from selection
       */
      template <typename TDrawableWithDisplay3D>
      void operator>> (   TDrawableWithDisplay3D & object );
      
      /**
       *  
       */
      template <typename TDrawableWithDisplay3D>
      void manipulate(TDrawableWithDisplay3D & anObject, TDrawableWithDisplay3D & (*ptrfonction)(TDrawableWithDisplay3D,int), int minValue, int maxValue, int step);

protected:
	  
	// Scene items
	Ogre::Root* 	mRoot;
	Ogre::RenderWindow* 	mWindow;
	Ogre::SceneManager* 	mSceneMgr;
	Ogre::Camera  * mCamera;
	static Ogre::SceneNode * RootSceneNode;
	
	// Input items
	InputListener * mInputManager;
	
	
	// Selection items
	Ogre::SceneNode *mCurrentObject;	//pointer to our currently selected object
	Ogre::RaySceneQuery* mRayScnQuery;	//pointer to our ray scene query
	std::map<std::string,DGtalNode *> myObjects;
	DGtalNode * mRootNode;
	DGtalNode * SelectedDGtalNode;
        DGtalNode * UpperFatherNonRoot;
	bool SelectionMode;
	Ogre::ManualObject* myAxis;
	
	Ogre::ManualObject * myWrist;
	Ogre::SceneNode *myWristNode;
	
	Ogre::SceneNode * myAxisNode;
	Ogre::Vector3 mySceneCenter;
	
	
	// Flags
	bool myManupilatingFlag;
	
	
	int myMaxManupulating;
	int myMinManupulating;
	int myCurrentManupulating;
	int myStep;
	
protected:
  
  
      void drawAxes();
      void drawWrist();



};
}
#include "InputListener.h"
#include "Ogre3DDisplayFactory.h"
#include "ViewerOgre3D.ih"
#endif /* VIEWEROGRE3D_H_ */

#undef ViewerOgre3D_RECURSES
#endif // else defined(Display3D_RECURSES)