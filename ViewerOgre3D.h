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
#include "DGtal/base/CountedPtr.h"
#include "CommonOgre.h"
#include "TextZone.h"
#include <OgreFontManager.h> 
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{
class Ogre3DDisplayFactory;

class InputListener;

const double scaleFactor= 20.0;
/////////////////////////////////////////////////////////////////////////////
// class ViewerOgre3D
/**
* Description of class 'ViewerOgre3D' <p>
* \brief Aim: The new viewer for DGtal
*/


class ViewerOgre3D 
{

  // ----------------------- local types ------------------------------
  public:
    
    
    /**
     * The associated map type for storing the default styles of
     * digital objects.
     */
    typedef std::map< std::string,CountedPtr<DrawableWithViewerOgre3D> > StyleMapping;

    /**
     * The associated map type for storing possible modes used for
     * displaying for digital objects.
     */
    typedef std::map< std::string, std::string > ModeMapping;
    
    
public:

      /**
       *  Constructor for the viewer
       */
      ViewerOgre3D(std::string aDirectory);
      
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
       *  Creates a texture, using the current color and texture attributes
       *  @param aName the name of the texture that will be created
       */
        void createMaterial(std::string  aName);
      
	
	
      /**
       *  Get a son node ( of the root one)
       *  @return a new SceneNode
       */
      Ogre::SceneNode * getANode();
      
      
      /**
       *  Returns the root scene node (Ogre)
       *  @return The Ogre root scenenode
       */
      Ogre::SceneNode * getRootSceneNode() { return mySceneMgr->getRootSceneNode();}
      
      
      /**
       *  get the root scene node (DGtal one) 
       *  @return the DGtal rootnode
       */
      DGtalNode * getRootDGtalNode() { return myRootNode;}
      
      
      
      /**
       *  Add a DgtalNode to the list
       *  @param anObject a DGtalNode to add to the nodes list
       */
      void addToList(DGtalNode * anObject);
      
      
      
      /**
       *  Flips the axis visibility .
       */
      void changeAxisVisibility();
      
      
      /**
       *  Set the near and far clip distance of the camera
       *  @param near the new near clip distance of the camera
       *  @param far the new far clip distance of the camera
       */
      void setNearFar(double near,double far);
      
      
      /**
       *  Increases the size of the current UNFR
       */
      void more( );
      
      
      /**
       *  Decreases the size of the current UNFR
       */
      void less( );
      
      
      
      
      /**
       *  Increases the transparency of the current UNFR
       */
      void moreTransparency( );
      
      
      /**
       *  Decreases the transparency of the current UNFR
       */
      void lessTransparency( );
      
      
      
      /**
       *  set's the camera upvector
       *  @param anUp the new upVector of the camera
       */
      void setCameraUpVector(Ogre::Vector3   anUp);
      
      
      /**
       *  Set's the camera Direction
       *  @param aPoint the new camera direction. 
       */
      void setCameraDirection(Ogre::Vector3   aPoint);
      
      
      /**
       *  Set's the camera position
       *  @param aPosition the new camera position
       */
      void setCameraPosition(Ogre::Vector3   aPosition);
      
      
      
      /**
       *  Returns back a pointer to the scene manager
       *  @return pointer to sceneManager
       */
      Ogre::SceneManager * getSceneMgr() { return mySceneMgr;}		
      
      
      /**
       *  looks for a point and changes the current selection if found (x, y) 
       *  the mouse coordinates and (h,w) the window dimension
       *  
       *  @param x the x position on the 2D screen
       *  @param y the y position en the 2D screen
       *  @param h the window height
       *  @param w the window widht
       */
      void lookForIt(unsigned int x,unsigned int y,unsigned int h,unsigned int w);
      
      
      /**
       *  Adds a clipping plane which has the followiing equation " ax + by + cz +d = 0 "
       *  @param a the first coefficient of the plane equation
       *  @param b the second coefficient of the plane equation
       *  @param c the third coefficient of the plane equation
       *  @param d the fourth  coefficient of the plane equation
       * 
       */
      void addClippingPlane(double a,double b,double c, double d); 
      
      
      /**
       *  Creates a voxel and returns it's representation
       *  @param x xCoordinate
       *  @param y yCoordinate
       *  @param z zCoordinate
       *  @param aNode the future representation node
       *  @param materialNode the material name (should be precreated)
       * 
       *  @return the new representation
       */
      Representation  * addVoxel(double x,double y, double z,
				 Ogre::SceneNode * aNode 
				 ,std::string materialName);
      
      
      /**
       *  Creates a line and returns it's representation
       *  @param x1 xCoordinate for the first point
       *  @param y1 yCoordinate for the first point
       *  @param z1 zCoordinate for the first point
       *  @param x2 xCoordinate for the second point
       *  @param y2 yCoordinate for the second point
       *  @param z2 zCoordinate for the second point
       *  @param aNode the future representation node
       *  @param materialNode the material name (should be precreated)
       * 
       *  @return the new representation
       */
      Representation * addLine(double x1, double y1, double z1,
			       double x2, double y2,double z2,Ogre::SceneNode * aNode,std::string materialName);
      
      /**
       *  Creates a point and returns it's representation
       *  @param x xCoordinate
       *  @param y yCoordinate
       *  @param z zCoordinate
       *  @param aNode the future representation node
       *  @param materialNode the material name (should be precreated)
       * 
       *  @return the new representation
       */
      Representation * addPoint (double x, double y, double z,
				 Ogre::SceneNode * aNode ,std::string materialName, double factor = 1);
      
      
      /**
       *  Creates a Kalimsky surfel and returns it's representation
       *  @param x xCoordinate
       *  @param y yCoordinate
       *  @param z zCoordinate
       *  @param aNode the future representation node
       *  @param materialNode the material name (should be precreated)
       * 
       *  @return the new representation
       */
      Representation * addKSSurfel (double x, double y, double z,
				    bool xSurfel, bool ySurfel, bool zSurfel,
				    Ogre::SceneNode * aNode,std::string materialName);
      
      /**
       *  Creates a Kalimsky voxel and returns it's representation
       *  @param x xCoordinate
       *  @param y yCoordinate
       *  @param z zCoordinate
       *  @param aNode the future representation node
       *  @param materialNode the material name (should be precreated)
       * 
       *  @return the new representation
       */
      Representation * addKSVoxel (int x, int y, int z,Ogre::SceneNode * aNode,std::string materialName);
      
      
      /**
       *  Creates a Kalimsky pointel and returns it's representation
       *  @param x xCoordinate
       *  @param y yCoordinate
       *  @param z zCoordinate
       *  @param aNode the future representation node
       *  @param materialNode the material name (should be precreated)
       * 
       *  @return the new representation
       */
      Representation * addKSPointel (double x, double y, double z,Ogre::SceneNode * aNode,std::string materialName);
      
      
      
      /**
       *  Creates a Kalimsky lignel and returns it's representation
       *  @param x xCoordinate
       *  @param y yCoordinate
       *  @param z zCoordinate
       *  @param aNode the future representation node
       *  @param materialNode the material name (should be precreated)
       * 
       *  @return the new representation
       */
      Representation * addKSLinel (double x1, double y1, double z1,double x2,
				   double y2, double z2,
				   Ogre::SceneNode * aNode,std::string materialName);
      
      
      /**
       *  Clears the scene, destroys all the DGtalNodes and their representation
       *  
       */
      void clearScene();
      
      
      /**
	*   Displays the scene content on the standard output
       */
      void sceneDisplay();
      
      
      
      /**
       *  Tells if we are in the manipulating mode
       *  @return a boolean that is true if the viewer is in manupulating
       */
      bool isInManupulatingMode() {return myManupilatingFlag;}
      
      
      /**
       *  Updates the manipulating value
       *  @param change is >  0 we increase the actual value by the step 
       *  if it's negative we decrease by the step ( if we dont go out the range)
       */
      void newManipulatingValue(int change);
      
      
      /**
       *   Returns the scene center
       */
      Ogre::Vector3 getSceneCenter(){ return mySceneCenter;}
      
      
      /**
       *  sets the scene center
       */
      void setSceneCenter(Ogre::Vector3 & aVector)
      {  
	      mySceneCenter= aVector;
	      myWristNode->setPosition(mySceneCenter);
      }
      

      /**
       *  Stops the manipulating mode
       */
      void abortManupulating();
      
      
      /**
	*  Computes the scene center
	*/
      void  computeSceneCenter (  );

      /**
	*  Updates the wrist position
	*/
      void  updateWrist (  );


      /**
      *  
      */
      void turn(double x, double y);
      
      
      
      /**
      * For instance, may associate a new style object T1 to the class
      * "HyperRectDomain": myStyles[ "HyperRectDomain" ] = T1.
      *
      * One can also store a new style T2 for a specific mode used for
      * drawing a class:  myStyles[ "HyperRectDomain/Paving" ] = T2.
      *
      * Modes may only be used in objects implementing the concept
      * CDrawableWithBoard2D.
      */
      StyleMapping myStyles;

      /**
      * May associate a current mode for a given class.
      * myModes[ "HyperRectDomain" ] = "Paving".
      *
      * Next display of a HyperRectDomain object will used the mode
      * "Paving".  Modes may only be used in objects implementing the
      * concept CDrawableWithBoard2D.
      */
      ModeMapping myModes;
	
      
    /**
     * @param objectName the name of the object (generally obtained
     * with a 'object.className()').
     *
     * @return the current mode for the given object name or "" if no
     * specific mode has been set.
     */
     std::string getMode( const std::string & objectName ) const;
    
    
     //-------------------------------------------------------------------------------------Color management
      /**
       *  Sets the self illumination color of the following object
       */
     void setSelfIlluminationColor(DGtal::Color aColor);
     
     
     /**
       *  Sets the Ambient illumination color of the following object
       */
     void setAmbientIlluminationColor(DGtal::Color aColor);
     
     /**
       *  Sets the Specular illumination color of the following object
       */
     void setSpecularIlluminationColor(DGtal::Color aColor);
     
      /**
       *  Sets the diphuse illumination color of the following object
       */
     void setDiphuseIlluminationColor(DGtal::Color aColor);
     
      /**
       *  Sets the texture of the following object
       */
     void setTexture(std::string aTexture);
     
     
      
     
     /**
       *  Returns the self illumination color of the following object
       */
     DGtal::Color  getSelfIlluminationColor( );
     
     
     /**
       *  Returns the Ambient illumination color of the following object
       */
     DGtal::Color  getAmbientIlluminationColor( );
     
     /**
       *  Returns the Specular illumination color of the following object
       */
     DGtal::Color  getSpecularIlluminationColor( );
     
      /**
       *  Returns the diphuse illumination color of the following object
       */
     DGtal::Color getDiphuseIlluminationColor( );
     
      /**
      *   Returns  the texture of the following object
      */
     std::string getTexture();
     

      /**
       * Destroys the scene
       */
       void destroyScene();
      
       /**
	*  Shows the commands on the standard output
	*/
       void showHelp();
       
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
       * Using manipulate on a DGtal Object
       *  @param ptrfonction is a pointer on the function you want to useful
       *  @param anObject is the initial Object
       *  @param minValue && @param @maxValue  are the range you want to study the object on
       *  @param step is the evolution step.
       */
      template <typename TDrawableWithDisplay3D>
      void manipulate(TDrawableWithDisplay3D & anObject, TDrawableWithDisplay3D & (*ptrfonction)(TDrawableWithDisplay3D,int), int minValue, int maxValue, int step);

protected:
	  
      /**
       *  Ogre Objects
       */
	Ogre::Root* 	myRoot;
	Ogre::RenderWindow* 	myWindow;
	Ogre::SceneManager* 	mySceneMgr;
	Ogre::Camera  * myCamera;
	static Ogre::SceneNode * myRootSceneNode;
	
	/**
	*  OIS Objects
	*/	
	InputListener * myInputManager;
	
	
	/**
	 *  Objects useful for selection
	 */
	Ogre::SceneNode * myCurrentObject;	//pointer to our currently selected object
	Ogre::RaySceneQuery* myRayScnQuery;	//pointer to our ray scene query
	DGtalNode * mySelectedDGtalNode;
        DGtalNode * myUpperFatherNonRoot;
	
	
	/**
	*  Node Pointer and lists
	*/
	std::map<std::string,DGtalNode *> myNodes;
	DGtalNode * myRootNode;
	
	
	
	/**
	 * Other objects
	 */
	Ogre::ManualObject* myAxis;
	Ogre::ManualObject * myWrist;
	Ogre::SceneNode *myWristNode;
	Ogre::SceneNode * myAxisNode;
	
	/**
	 * Scene center
	 */
	Ogre::Vector3 mySceneCenter;
	
	
	/**
	 * Flags
	 */
	bool mySelectionMode;
	bool myManupilatingFlag;
	
	
	/**
	 *  Manipulating data
	 */
	int myMaxManupulating;
	int myMinManupulating;
	int myCurrentManupulating;
	int myStep;
	
       /**
	* Current colors
	*/
       DGtal::Color myCurrentSelfIlluminationColor;
       DGtal::Color myCurrentAmbientIlluminationColor;
       DGtal::Color myCurrentDiphuseIlluminationColor;
       DGtal::Color myCurrentSpecularIlluminationColor;
       std::string myTexture;
       
       
       /**
	*  2D display
	* 
	*/
        TextZone * myTitle;
	TextZone * myMode;
	
        /**
	 *
         */
	Ogre::MaterialPtr  myTempMaterial;

	std::string myDirectory;
	
	Ogre::LogManager * myLogManager;
       


	
protected:
  
      /**
      *  Updates the manipulate label value
      */
      void updateManipulateDisplay();
      
      /**
	* draws the axes
	*/  
      void drawAxes();
      
      
      /**
	* draws the wrist
	*/
      void drawWrist();
      
     /**
       *   Returns the lower point of the scene
       */
      Ogre::Vector3 getLowerPosition();
      
      
      /**
       *  Returns the lower point
       */
      Ogre::Vector3 getUpperPosition();
      
     /**
       *  Find the representation coressponding to a point
       */
      Representation * findRepresentation(std::string aName);
      
      
      /**
       * Sets the new initial position of the cameraman
       */
      void updateInitialCameraPosition( );
      
      
      /**
      *  Returns the leftest point
      */
      Ogre::Vector3 getLeftestPosition();


      /**
	*  Returns the Fowardest point
	*/
      Ogre::Vector3 getFowardestPosition();


};
}
#include "InputListener.h"
#include "Ogre3DDisplayFactory.h"
#include "ViewerOgre3D.ih"
#endif /* VIEWEROGRE3D_H_ */

#undef ViewerOgre3D_RECURSES
#endif // else defined(Display3D_RECURSES)
