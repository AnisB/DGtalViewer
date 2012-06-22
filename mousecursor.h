#ifndef __MOUSECURSOR_H__
#define __MOUSECURSOR_H__

//#include <OgrePanelOverlayElement.h>
#include <OgreOverlay.h>
#include <OgreOverlayManager.h>
#include <OgreMaterialManager.h>
#include <OgreTextureManager.h>
#include <OgreOverlayContainer.h>
#include <OgreTechnique.h>


class MouseCursor
  {
  private:
    Ogre::Overlay* mGuiOverlay;
    Ogre::OverlayContainer* mCursorContainer;
    Ogre::TexturePtr mTexture;
    Ogre::MaterialPtr  mMaterial;

    Ogre::Real mWindowWidth;
    Ogre::Real mWindowHeight;

  public:
    MouseCursor() : mGuiOverlay ( 0 ), mCursorContainer ( 0 )
    {
      mMaterial = Ogre::MaterialManager::getSingleton().create ( "MouseCursor/default", "General" );
      mCursorContainer = ( Ogre::OverlayContainer* ) Ogre::OverlayManager::getSingletonPtr()->createOverlayElement ( "Panel", "MouseCursor" );
      mCursorContainer->setMaterialName ( mMaterial->getName() );
      mCursorContainer->setPosition ( 0, 0 );

      mGuiOverlay = Ogre::OverlayManager::getSingletonPtr()->create ( "MouseCursor" );
      mGuiOverlay->setZOrder ( 649 );
      mGuiOverlay->add2D ( mCursorContainer );
      mGuiOverlay->show();
    }

    ~MouseCursor ( void ) {}

    void setImage ( const Ogre::String& filename )
    {
      mTexture = Ogre::TextureManager::getSingleton().load ( filename, "General" );

      Ogre::TextureUnitState *pTexState;
      Ogre::Technique * myTech=mMaterial->getTechnique ( 0 );
      if ( myTech->getPass ( 0 )->getNumTextureUnitStates() )
        {
          pTexState = mMaterial->getTechnique ( 0 )->getPass ( 0 )->getTextureUnitState ( 0 );
        }
      else
        {
          pTexState = mMaterial->getTechnique ( 0 )->getPass ( 0 )->createTextureUnitState ( mTexture->getName() );
        }
      pTexState->setTextureAddressingMode ( Ogre::TextureUnitState::TAM_CLAMP );
      mMaterial->getTechnique ( 0 )->getPass ( 0 )->setSceneBlending ( Ogre::SBT_TRANSPARENT_COLOUR );
    }

    void setWindowDimensions ( unsigned int width, unsigned int height )
    {
      mWindowWidth = ( width > 0 ) ? width : 1;
      mWindowHeight = ( height > 0 ) ? height : 1;


      mCursorContainer->setWidth ( mTexture->getWidth() / mWindowWidth );
      mCursorContainer->setHeight ( mTexture->getHeight() / mWindowHeight );
    }

    void setVisible ( bool visible )
    {
      if ( visible )
        {
          mCursorContainer->show();
        }
      else
        {
          mCursorContainer->hide();
        }
    }

    void updatePosition ( int x, int y )
    {

      Ogre::Real rx = x / mWindowWidth;
      Ogre::Real ry = y / mWindowHeight;
      mCursorContainer->setPosition ( clamp ( rx, 0.0f, 1.0f ), clamp ( ry, 0.0f, 1.0f ) );
    }


    Ogre::Real clamp ( Ogre::Real a, Ogre::Real min, Ogre::Real max )
    {
      if ( a < min )
        {
          return min;
        }
      if ( a > max )
        {
          return max;
        }
      return a;
    }
  };

#endif
