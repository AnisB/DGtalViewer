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
* @file DGtalNode.cpp
* @author Anis Benyoub (\c anis.benyoub@insa-lyon.fr )
* Liris CNRS
*
* @date 2012/06/10
*
*
* This file is part of the DGtal library.
*/


#include "DGtalNode.h"
#include <iostream>
#include "TDrawable.h"
#include "DGtal/kernel/PointVector.h"
#include "DGtal/kernel/sets/DigitalSetBySTLSet.h"

/**
* Constructor.
*/
DGtalNode::DGtalNode ( std::string aName, Ogre::SceneManager * aSceneMgr ) : myName ( aName ), mySceneMgr ( aSceneMgr )
{
  myIsRoot = false;
}

DGtalNode::DGtalNode ( Ogre::SceneManager * aSceneMgr ) : mySceneMgr ( aSceneMgr )
{
  myIsRoot = false;
}

DGtalNode::DGtalNode ( const DGtalNode& other )
{
  myIsRoot = false;
}

DGtalNode::~DGtalNode()
{

}

void
DGtalNode::selfDisplay ( std::ostream & out ) const
  {
    out << "[DGtalNode]";
  }



bool DGtalNode::setRepresentation ( Representation * newRepresentation )
{
  myRepresentation = newRepresentation;
}


DGtalNode& DGtalNode::operator= ( const DGtalNode & other )
{
  return *this;
}

bool DGtalNode::operator== ( const DGtalNode& other ) const
  {
    return ( myName == other.myName );
  }



/**
*  Sets this node as the root one
*/
void DGtalNode::setRoot()
{
  myIsRoot = true;
}

/**
  *  Returns back the representation if entity is matching with the name
  *  If not, returns NULL
  */
Representation * DGtalNode::getRepresentation ( std::string aName )
{
  if ( !myRepresentation->isVirtual() )
    {
      if ( myRepresentation->getEntityName() == aName )
        {

          return myRepresentation;
        }
    }

  return NULL;
}


/**
*  Returns back the representation
*/
Representation * DGtalNode::returnRepresentation()
{
  return myRepresentation;
}

/**
* Set this object as a selected one
*
*/
void DGtalNode::select()
{
  if ( !myRepresentation->isVirtual() )
    {
      myRepresentation->Select();
    }
  else
    {
      std::map<std::string , DGtalNode * >::iterator it = mySons.begin();

      while ( it != mySons.end() )
        {
          ( *it ).second->select();
          it++;
        }
    }
}


/**
  *  Displays on the stanard input the node's content
  */
void DGtalNode::display ( int level )
{
  if ( myType == "PointVector" )
    {
      cout << "PointVector" << endl;
    }
  else
    if ( myType == "DigitalSetBySTLSet" )
      {
        cout << "DigitalSetBySTLSet" << endl;
      }

  std::map<std::string , DGtalNode * >::iterator it = mySons.begin();

  while ( it != mySons.end() )
    {
      ( *it ).second->display ( level + 1 );
      it++;
    }
}




/**
* Set this object as a unselected
*
*/
void DGtalNode::unselect()
{
  if ( !myRepresentation->isVirtual() )
    {
      myRepresentation->Unselect();
    }
  else
    {
      std::map<std::string , DGtalNode * >::iterator it = mySons.begin();

      while ( it != mySons.end() )
        {
          ( *it ).second->unselect();
          it++;
        }
    }
}







/**
* Set this virtual object as a selected one
*
*/
void DGtalNode::groupSelect()
{
  if ( !myRepresentation->isVirtual() )
    {
      myRepresentation->GroupSelect();
    }

  std::map<std::string , DGtalNode * >::iterator it = mySons.begin();

  while ( it != mySons.end() )
    {
      ( *it ).second->groupSelect();
      it++;
    }

}

/**
*  Sets the name of the Object
*/
void DGtalNode::setName ( std::string aName )
{
  myName = aName;
}



/**
*  Returns back the scene node matching this object
*/
Ogre::SceneNode * DGtalNode::getNode()
{
  return myRepresentation->getNode();
}





/**
*  Sets the DGtal associated object
*/
void DGtalNode::setDGtalObject ( DGtal::DrawableWithOgre  * obj )
{
  myDGtalObject = obj;
  myType = myDGtalObject->className();
}


/**
*  Returns back the DGtal associated object
*/
DGtal::DrawableWithOgre * DGtalNode::getDGtalObject()
{
  return myDGtalObject;
}




/**
*  Adds a son the the sons list
*/
void DGtalNode::addSon ( DGtal::DGtalNode  * newNode )
{
  if ( !newNode->returnRepresentation()->isVirtual() )
    {
      mySons[newNode->returnRepresentation()->getEntityName() ] = newNode;
    }
  else
    {
      mySons[newNode->getName() ] = newNode;
    }
}


/**
*  Sets the father's Node
*/
void DGtalNode::setFather ( DGtal::DGtalNode  * newNode )
{
  myFather = newNode;
}


/**
*  Returns the father's Node
*/
DGtal::DGtalNode  * DGtalNode::getFather( )
{
  return myFather;
}



/**
*  Says if this node is the root node of the DGtal tree or not.
*/
bool  DGtalNode::isRoot( )
{
  return myIsRoot;
}



/**
* Delete the Node's sons and it's self
*
*/
void DGtalNode::clear()
{
  std::map<std::string , DGtalNode * >::iterator it = mySons.begin();

  while ( it != mySons.end() )
    {
      ( *it ).second->clear();
      it++;
    }

  if ( !myIsRoot )
    {
      myRepresentation->Clear();
    }

  mySons.clear();
}


/**
*  Returns the UNRN
*/
DGtalNode  * DGtalNode::getUpperNonRootNode()
{
  std::cout << "On va recupere la racine" << std::endl;
  DGtalNode * UNRN = this;

  while ( !UNRN->getFather()->isRoot() )
    {
      std::cout << "On monte" << std::endl;
      UNRN = UNRN->getFather();
    }

  return UNRN;
}

/**
*  Returns the DGtalObject type
*/
std::string   DGtalNode::getType()
{
  return myType;
}

