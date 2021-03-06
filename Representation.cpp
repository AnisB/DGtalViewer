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
* @file Representation.cpp
* @author Anis Benyoub (\c anis.benyoub@insa-lyon.fr )
* INSTITUTION
*
* @date 2012/06/15
*
* Header file for module Representation.cpp
*
* This file is part of the DGtal library.
*/

///////////////////////////////////////////////////////////////////////////////
#include "Representation.h"
// Includes inline functions/methods if necessary.
#if !defined(BUILD_INLINE)
#include "Representation.ih"
#endif
///////////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// class Representation
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Standard services - public :

/**
* Constructor for a real representation
*/
  DGtal::Representation::Representation(  Ogre::SceneManager * aSceneMgr, Ogre::MovableObject * aMovableObject,
  Ogre::SceneNode *aSceneNode, std::string aName,std::string aMovableObjectType)
  {
    myMovableObject=aMovableObject;
    mySceneNode=aSceneNode;
    myName=aName;
    mVirtual=false;
    mySceneMgr = aSceneMgr;
    myMovableObjectType=aMovableObjectType;
    myScale=3;
  }

/**
* Constructor for a virtual representation
*/
  DGtal::Representation::Representation( Ogre::SceneManager * aSceneMgr, Ogre::SceneNode *aSceneNode, std::string aName)
  {
    mySceneNode=aSceneNode;
    myName=aName;
    mVirtual=true;
    mySceneMgr = aSceneMgr;
    myScale=3;

  }
  
 
/**
* Destructor.
*/
DGtal::Representation::~Representation()
{
}



///////////////////////////////////////////////////////////////////////////////
// Interface - public :

/**
* Writes/Displays the object o5n an output stream.
* @param out the output stream where the object is written.
*/
void
DGtal::Representation::selfDisplay ( std::ostream & out ) const
{
    out << "[XXX]";
}

/**
* Checks the validity/consistency of the object.
* @return 'true' if the object is valid, 'false' otherwise.
*/
bool
DGtal::Representation::isValid() const
{
    return true;
}



/**
* Returns the name of the entity
*
*/
std::string DGtal::Representation::getName()
{
	return myName;
}



/**
* Return the name of the entity
*
*/
std::string DGtal::Representation::getEntityName()
{
  
   return myMovableObject->getName();
}




/**
* Returns a pointer on the Node
*
*/
Ogre::SceneNode * Representation::getNode()
{
  return mySceneNode;
}



/**
* Changes the father of this entity
*
*/
void  Representation::setAttachedParent(DGtalNode * aParent)
{
  myParent =aParent;
}



/**
* Returns a pointer on the associated DGtal Object
*
*/
DGtalNode * Representation::getAttachedParent()
{
  return myParent;
}



/**
*  Operator =
*
*/
Representation& Representation::operator=(const Representation& other)
{
    return *this;
}




/**
* Set this entity as a selected one
*
*/
void Representation::select()
{
  if(myMovableObjectType=="Entity")
  { 
    ((Ogre::Entity*) myMovableObject)->setMaterialName("Texture/Selected");
    ((Ogre::Entity*) myMovableObject)->setCastShadows(true);
  }
}



/**
* Set this entity as in a selected group
*
*/
void Representation::groupSelect()
{
  if(myMovableObjectType=="Entity")
  { 
    ((Ogre::Entity*) myMovableObject)->setMaterialName("Texture/Group");
    ((Ogre::Entity*) myMovableObject)->setCastShadows(true);
  }
}



/**
* Set this entity as a unselected
*
*/
void Representation::unselect()
{
  if(myMovableObjectType=="Entity")
  { 
    ((Ogre::Entity*) myMovableObject)->setMaterialName(myMaterialName);
    ((Ogre::Entity*) myMovableObject)->setCastShadows(true);
  }
}




/**
* Tells if the representation is virtual, is means that is has or not an associated entity 
*
*/
bool Representation::isVirtual()
{
  return mVirtual;
}




/**
* Tells if the representation is virtual, is means that is has or not an associated entity 
*
*/
void  Representation::clear()
{

  if(!mVirtual)
  {
    mySceneNode->detachAllObjects();
    if(myMovableObjectType=="Entity")
    mySceneMgr->destroyEntity((Ogre::Entity*)myMovableObject);
  }
  mySceneMgr->destroySceneNode(mySceneNode);
}

/**
 *  Adds a new material to apply
 */
void Representation::setMaterialName(std::string aMaterial)
{
    myMaterialName=aMaterial;
}

/**
 *  Sets the  material to apply
 */
void Representation::setMaterial(Ogre::MaterialPtr  aMaterial)
{
  myMaterial = aMaterial;
}


/**
 *  Returns the material name
 */
std::string Representation::getMaterialName()
{
  return myMaterialName;
}


/**
 *  Returns the material 
 */
Ogre::MaterialPtr Representation::getMaterial()
{
  return myMaterial;
}



/**
  *  
  */
void Representation::more( )
{
  if(myScale<5)
  {
    mySceneNode->scale(2.0,2.0,2.0);
    myScale++;
  }
}


/**
  *  
  */
void Representation::less( )
{
  if(myScale>1)
  {
    mySceneNode->scale(0.5,0.5,0.5);
    myScale --;
  }
}

/**
*  
*/
void Representation::moreTransparency( )
{
  

}


/**
* 
*/
void Representation::lessTransparency( )
{
  std::cout<<"Hello"<<std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Internals - private :

// //
///////////////////////////////////////////////////////////////////////////////

