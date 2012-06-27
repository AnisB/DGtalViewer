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
* @file DGtalNode.h
* @author Anis Benyoub (\c anis.benyoub@insa-lyon.fr )
* INSTITUTION
*
* @date 2012/06/14
*
* Header file for module DGtalNode.cpp
*
* This file is part of the DGtal library.
*/

#if defined(DGtalNode_RECURSES)
#error Recursive header files inclusion detected in DGtalNode.h
#else // defined(DGtalNode_RECURSES)
/** Prevents recursive inclusion of headers. */
#define DGtalNode_RECURSES

#if !defined DGtalNode_h
/** Prevents repeated inclusion of headers. */
#define DGtalNode_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "OGRE/Ogre.h"
#include "DrawableWithOgre.h"

//////////////////////////////////////////////////////////////////////////////

namespace DGtal
  {

/////////////////////////////////////////////////////////////////////////////
// class DGtalNode
  /**
  * Description of class 'DGtalNode' <p>
  * \brief Aim: Creates the link between a DGtal object and a Ogre3D Object
  */
  
  class Representation;
  
 
  class DGtalNode
    {
      // ----------------------- Standard services ------------------------------
    public:
      /**
      * Constructor with a predefined name.
      */
      DGtalNode( std::string aName, Ogre::SceneManager * aSceneMgr);

      
       /**
      * Constructor without a name
      */
      DGtalNode(Ogre::SceneManager * aSceneMgr);


      /**
      * Destructor.
      */
      ~DGtalNode();


      /**
      * Getter to the name of the object
      */
      std::string getName()
      {
        return myName;
      }

      // ----------------------- Interface --------------------------------------
    public:

      /**
      * Writes/Displays the object on an output stream.
      * @param out the output stream where the object is written.
      */
      void selfDisplay ( std::ostream & out ) const;

      /**
      * Checks the validity/consistency of the object.
      * @return 'true' if the object is valid, 'false' otherwise.
      */
      bool isValid() const;

      /**
      * Assignment.
      * @param other the object to compare.
      * @return a bool wich defines if this two object are the same.
      */
      virtual bool operator== ( const DGtalNode& other ) const;
      
      
      /**
      * Adds an entity to the list of attributes of this object.
      */

      bool setRepresentation (Representation * newRepresentation);
      
      
      
      
      /**
       *  Returns back an entity matching with the name
       *  If no entity is matching returns NULL
       */
       Representation * getRepresentation(std::string aName);
       
       
       
       /**
       *  Sets this node as the root one
       */
       void setRoot();
       
       /**
      *  Says if this node is the root node of the DGtal tree or not.
      */
      bool  isRoot( );
       
       
       /**
       *  Sets the name of the Object
       */
       void setName(std::string aName);
       
       
       /**
       *  Sets the DGtal associated object
       */
       void setDGtalObject(DGtal::DrawableWithOgre  * obj);
       
       
       
       /**
       *  Returns back the DGtal associated object
       */
       DGtal::DrawableWithOgre * getDGtalObject( );
       
       
       
     
       /**
       *  Returns back the scene node matching this object
       */
       Ogre::SceneNode * getNode();
      

      /**
      * Set this object as a selected one
      *
      */
      void Select();
      
      
      /**
      * Set this virtual object as a selected one
      *
      */
      void GroupSelect();


      /**
      * Set this object as a unselected
      *
      */
      void Unselect();
      
      
      
      /**
      *  Returns back the representation 
      */
      Representation * returnRepresentation();
      
      
      
      /**
      *  Adds a son the the sons list
      */
      void addSon(DGtal::DGtalNode  * newNode);

      
      
      /**
      *  Sets the father's Node
      */
      void setFather(DGtal::DGtalNode  * newNode);
      
      
      /**
      *  Returns the father's Node
      */
      DGtal::DGtalNode  * getFather( );

      /**
      *  Returns the UNRN
      */
      DGtalNode  * getUpperNonRootNode();
      
      
      /**
       * Delete the Node's sons and it's self
       * 
       */
        void Clear();

	/**
	*  Returns the DGtalObject type
	*/
	std::string  getType();


      // ------------------------- Protected Datas ------------------------------
    protected:
      // ------------------------- Private Datas --------------------------------
    private:

      // ------------------------- Hidden services ------------------------------
    protected:

      


    private:

      /**
      * Copy constructor.
      * @param other the object to clone.
      * Forbidden by default.
      */
      DGtalNode ( const DGtalNode & other );

      /**
      * Assignment.
      * @param other the object to copy.
      * @return a reference on 'this'.
      * Forbidden by default.
      */
      DGtalNode & operator= ( const DGtalNode & other );








      // ------------------------- Internals ------------------------------------
    private:

      //--------------------------- Protected attributes---------------------------
    protected:
      std::string myName;
      Representation * myRepresentation;
      DGtalNode * myFather;
      std::map<string, DGtalNode* > mySons; 
      bool mIsRoot;
      DrawableWithOgre * myDGtalObject;
      Ogre::SceneManager * mySceneMgr;
      std::string mType;

    }; // end of class DGtalNode


  /**
  * Overloads 'operator<<' for displaying objects of class 'DGtalNode'.
  * @param out the output stream where the object is written.
  * @param object the object of class 'DGtalNode' to write.
  * @return the output stream after the writing.
  */
  std::ostream&
  operator<< ( std::ostream & out, const DGtalNode & object );


} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////

#include "Representation.h"
// Includes inline functions.
#if !defined(BUILD_INLINE)
#include "DGtalNode.ih"
#endif


// //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined DGtalNode_h
#undef DGtalNode_RECURSES
#endif // else defined(DGtalNode_RECURSES)




