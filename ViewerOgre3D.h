#pragma once 
/*
 * ViewerOgre3D.h
 *
 *  Created on: 4 mai 2012
 *      Author: anis
 */

#if defined(ViewerOgre3D_RECURSES)
#error Recursive header files inclusion detected in ViewerOgre3D.h
#else // defined(ViewerOgre3D_RECURSES)
/** Prevents recursive inclusion of headers. */
#define ViewerOgre3D_RECURSES

#if !defined (ViewerOgre3D_h)
#define ViewerOgre3D_h


#include "OGRE/Ogre.h"
#include <list>
#include <DGtal/io/Color.h>
#include "DGtal/base/Common.h"
#include "OgreEntity.h"
#include "DGtalNode.h"


namespace DGtal {
  
class Ogre3DDisplayFactory;

class InputListener;


class ViewerOgre3D 
{
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
	
	


	public:
		ViewerOgre3D();
		
		virtual ~ViewerOgre3D();
		
		void Start();
		
		void InitMaterials();
		
		bool InitConfigs();
		
		void CreateScene();
		
		void CreateFrameListener();
		
		void draw();
		
		Ogre::SceneNode * getANode();
		
		Ogre::SceneNode * getRootSceneNode() { return mSceneMgr->getRootSceneNode();}
		
		DGtalNode * getRootDGtalNode() { return mRootNode;}
		
		void addToList(DGtalNode * anObject);
		
		void DrawInitialItems();
		
		Ogre::SceneManager * getSceneMgr() { return mSceneMgr;}		
		
		void LookForIt(unsigned int x,unsigned int y,unsigned int h,unsigned int w);
		
		Representation * findRepresentation(std::string aName);
		
		Representation  * addVoxel(double x,double y, double z,Ogre::SceneNode * aNode);
		
		void ClearScene();
		
		void sceneDisplay();
		
		ViewerOgre3D & operator<< ( const DGtal::Color & aColor );
		
		template <typename TDrawableWithDisplay3D>
		ViewerOgre3D & operator<< ( const  TDrawableWithDisplay3D & object );
		
		template <typename TDrawableWithDisplay3D>
		void operator>> (   TDrawableWithDisplay3D & object );

};
}
#include "InputListener.h"
#include "Ogre3DDisplayFactory.h"
#include "ViewerOgre3D.ih"
#endif /* VIEWEROGRE3D_H_ */

#undef ViewerOgre3D_RECURSES
#endif // else defined(Display3D_RECURSES)