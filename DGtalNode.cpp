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

///////////////////////////////////////////////////////////////////////////////
#include "DGtalNode.h"
#include <iostream>
#include "DrawableWithOgreWrapper.h"
#include "DGtal/kernel/PointVector.h"
#include "DGtal/kernel/sets/DigitalSetBySTLSet.h"
///////////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// class DGtalNode
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Standard services - public :

/**
 * Constructor with a predefined name.
 * @param aName the Node's name
 * @param aSceneMgr the ogre scene manager
 */
DGtalNode::DGtalNode ( std::string aName, Ogre::SceneManager * aSceneMgr ) : myName ( aName ), mySceneMgr ( aSceneMgr )
{
  myDGtalObject=NULL;
  myIsRoot = false;
}


/**
 * Constructor without a name
 * @param aSceneMgr the ogre scene manager
 */
DGtalNode::DGtalNode ( Ogre::SceneManager * aSceneMgr ) : mySceneMgr ( aSceneMgr )
{
  myDGtalObject=NULL;
  myIsRoot = false;
}

/**
 * Copy constructor
 */
DGtalNode::DGtalNode ( const DGtalNode& other )
{
  myDGtalObject=NULL;
  myIsRoot = false;
}


/**
 * Destructor
 */
DGtalNode::~DGtalNode()
{ 

  std::map<std::string , DGtalNode * >::iterator it = mySons.begin();

  while ( it != mySons.end() )
    {

      delete (( *it ).second) ;
      it++;
    }

  if(myRepresentation!=NULL)
    {
      delete myRepresentation;
    }
  if(myDGtalObject!=NULL)
    {
      delete myDGtalObject;
    }
}


/**
 * Writes/Displays the object on an output stream.
 * @param out the output stream where the object is written.
 */
void
DGtalNode::selfDisplay ( std::ostream & out ) const
{
  out << "[DGtalNode]";
}


/**
 * Adds a representation to the attributes of this object.
 */
void
DGtalNode::setRepresentation ( Representation * newRepresentation )
{
  myRepresentation = newRepresentation;
}



/**
 * Assignment.
 * @param other the object to copy.
 * @return a reference on 'this'.
 * Forbidden by default.
 */
DGtalNode& DGtalNode::operator= ( const DGtalNode & other )
{
  return *this;
}



/**
 * Assignment.
 * @param other the object to compare.
 * @return a bool wich defines if this two object are the same.
 */
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
 *  Returns back an entity matching with the name
 *  If no entity is matching returns NULL
 *  @param aName the name to test
 *  @return myRepresentation if the name matches
 */
Representation * DGtalNode::ifRepresentation ( std::string aName )
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
 *  @return myRepresentation
 */
Representation * DGtalNode::getRepresentation ( )
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
      myRepresentation->select();
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
      myRepresentation->unselect();
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
      myRepresentation->groupSelect();
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
  if ( !newNode->getRepresentation()->isVirtual() )
    {
      mySons[newNode->getRepresentation()->getEntityName() ] = newNode;
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
      myRepresentation->clear();
    }

  mySons.clear();
}


/**
 *  Returns the UNRN
 */
DGtalNode  * DGtalNode::getUpperNonRootNode()
{
  DGtalNode * UNRN = this;
    
  if(UNRN!=NULL)
    {
      if (UNRN->getFather()!= NULL)
	{
	  while ( ! UNRN->getFather()->isRoot() )
	    {
	      UNRN = UNRN->getFather();
	    }
	}
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

/**
 *  
 */
void DGtalNode::more( )
{
  if ( !myRepresentation->isVirtual() )
    {
      myRepresentation->more();
    }

  std::map<std::string , DGtalNode * >::iterator it = mySons.begin();

  while ( it != mySons.end() )
    {
      ( *it ).second->more();
      it++;
    }
}


/**
 *  
 */
void DGtalNode::less( )
{
  if ( !myRepresentation->isVirtual() )
    {
      myRepresentation->less();
    }

  std::map<std::string , DGtalNode * >::iterator it = mySons.begin();

  while ( it != mySons.end() )
    {
      ( *it ).second->less();
      it++;
    }
}

/**
 *  
 */
void DGtalNode::moreTransparency( )
{
  if ( myRepresentation->isVirtual() )
    {

      IncreaseTransparency(mySons.begin()->second->getRepresentation()->getMaterial());
    }

}

/**
 *  
 */
void DGtalNode::lessTransparency( )
{
  if ( myRepresentation->isVirtual() )
    {
      DecreaseTransparency(mySons.begin()->second->getRepresentation()->getMaterial());

    }

}

/**
 * 
 */
void DGtalNode::IncreaseTransparency(Ogre::MaterialPtr  aMaterial)
{
  
  Ogre::Technique* lFirstTechnique = aMaterial->getTechnique ( 0 );
  Ogre::Pass* lFirstPass = lFirstTechnique->getPass ( 0 );
  
  if((lFirstPass->getSelfIllumination().a*0.5)>0.05)
    {
      Ogre::ColourValue lSelfIllumnationColour ( ( double ) lFirstPass->getSelfIllumination().r,
						 ( double ) lFirstPass->getSelfIllumination().g, 
						 ( double ) lFirstPass->getSelfIllumination().b ,
						 ( double ) lFirstPass->getSelfIllumination().a*0.5);
      lFirstPass->setSelfIllumination ( lSelfIllumnationColour );
    }

  if((lFirstPass->getDiffuse().a*0.5)>0.05)
    {
      Ogre::ColourValue lDiffuseColour ( ( double ) lFirstPass->getDiffuse().r,
					 ( double )  lFirstPass->getDiffuse().g , 
					 ( double )  lFirstPass->getDiffuse().b , 
					 ( double )  lFirstPass->getDiffuse().a*0.5);
      lFirstPass->setDiffuse ( lDiffuseColour );
    }
   
  if((lFirstPass->getAmbient().a*0.5)>0.05)
    {
      Ogre::ColourValue lAmbientColour (( double )  lFirstPass->getAmbient().r, 
					( double ) lFirstPass->getAmbient().g ,
					( double ) lFirstPass->getAmbient().b , 
					( double ) lFirstPass->getAmbient().a*0.5 );
      lFirstPass->setAmbient ( lAmbientColour );
    }
  
  if((lFirstPass->getSpecular().a*0.5)>0.05)
    {
      Ogre::ColourValue lSpecularColour ( ( double ) lFirstPass->getSpecular().r ,
					  ( double ) lFirstPass->getSpecular().g , 
					  ( double ) lFirstPass->getSpecular().b,
					  ( double )lFirstPass->getSpecular().a *0.5);
      lFirstPass->setSpecular ( lSpecularColour );
    }
}
      
      
      
/**
 * 
 */
void DGtalNode::DecreaseTransparency(Ogre::MaterialPtr  aMaterial)
{
  
  Ogre::Technique* lFirstTechnique = aMaterial->getTechnique ( 0 );
  Ogre::Pass* lFirstPass = lFirstTechnique->getPass ( 0 );
    
  if((lFirstPass->getSpecular().a*2.0)<1.1)
    {
      Ogre::ColourValue lSelfIllumnationColour ( ( double ) lFirstPass->getSelfIllumination().r,
						 ( double ) lFirstPass->getSelfIllumination().g, 
						 ( double ) lFirstPass->getSelfIllumination().b ,
						 ( double ) lFirstPass->getSelfIllumination().a*2.0);
      lFirstPass->setSelfIllumination ( lSelfIllumnationColour );
    }

  if((lFirstPass->getDiffuse().a*2.0)<1.1)
    {
      Ogre::ColourValue lDiffuseColour ( ( double ) lFirstPass->getDiffuse().r,
					 ( double )  lFirstPass->getDiffuse().g , 
					 ( double )  lFirstPass->getDiffuse().b , 
					 ( double )  lFirstPass->getDiffuse().a*2.0);
      lFirstPass->setDiffuse ( lDiffuseColour );
    }
 
 
  if((lFirstPass->getAmbient().a*2.0)<1.1)
    {
      Ogre::ColourValue lAmbientColour (( double )  lFirstPass->getAmbient().r, 
					( double ) lFirstPass->getAmbient().g ,
					( double ) lFirstPass->getAmbient().b , 
					( double ) lFirstPass->getAmbient().a*2.0 );
      lFirstPass->setAmbient ( lAmbientColour );
    }

  if((lFirstPass->getSpecular().a*2.0)<1.1)
    {
      Ogre::ColourValue lSpecularColour ( ( double ) lFirstPass->getSpecular().r ,
					  ( double ) lFirstPass->getSpecular().g , 
					  ( double ) lFirstPass->getSpecular().b,
					  ( double )lFirstPass->getSpecular().a *2.7);
      lFirstPass->setSpecular ( lSpecularColour );
    }
}
      
