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
  DGtal::Representation::Representation(  Ogre::Entity * aEntity,
  Ogre::SceneNode *aSceneNode, std::string aName)
  {
    myEntity=aEntity;
    mySceneNode=aSceneNode;
    myName=aName;
    mVirtual=false;
    
  }

/**
* Constructor for a virtual representation
*/
  DGtal::Representation::Representation( Ogre::SceneNode *aSceneNode, std::string aName)
  {
    mySceneNode=aSceneNode;
    myName=aName;
    mVirtual=true;
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
* Writes/Displays the object on an output stream.
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
  
   return myEntity->getName();
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
void Representation::Select()
{
  myEntity->setMaterialName("Texture/Selected");
}



/**
* Set this entity as in a selected group
*
*/
void Representation::GroupSelect()
{
  myEntity->setMaterialName("Texture/Group");
}



/**
* Set this entity as a unselected
*
*/
void Representation::Unselect()
{
    myEntity->setMaterialName("Texture/Unselected");
}




/**
* Tells if the representation is virtual, is means that is has or not an associated entity 
*
*/
bool Representation::isVirtual()
{
  return mVirtual;
}

///////////////////////////////////////////////////////////////////////////////
// Internals - private :

// //
///////////////////////////////////////////////////////////////////////////////

