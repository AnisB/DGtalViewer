/*
 * InputListener.h
 *
 *  Created on: 26 janv. 2012
 *      Author: dev
 */

/*
#if defined(InputListener_RECURSES)
 #error Recursive header files inclusion detected in InputListener.h
 #else // defined(InputListener_RECURSES)
 /** Prevents recursive inclusion of headers.
 #define InputListener_RECURSES
*/


#if !defined (InputListener_h)
#define InputListener_h

//----------------------------------------------------Includes OIS
#include <OIS/OIS.h>
#include <map>
//----------------------------------------------------Includes personnels

#include "OGRE/Ogre.h"


#include "CameraMan.h"
#include "mousecursor.h"

namespace DGtal {
class ViewerOgre3D;

class InputListener :public Ogre::FrameListener, public OIS::KeyListener, OIS::MouseListener
  {
  public:
    //----------------------------------------------------Constructeur et destructeur
    InputListener ( Ogre::RenderWindow * aWindow,
                    ViewerOgre3D * aViewer,
                    Ogre::Camera * aCamera,
                    Ogre::SceneManager * aSceneManager );
    ~InputListener();

    //----------------------------------------------------Rendu
    virtual bool frameStarted ( const Ogre::FrameEvent & evt );
    virtual bool frameRenderingQueued ( const Ogre::FrameEvent&	);
    //----------------------------------------------------Gestion des entree
    bool keyPressed ( const OIS::KeyEvent &e );
    bool mousePressed ( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    bool mouseReleased ( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    bool keyReleased ( const OIS::KeyEvent &e );
    bool mouseMoved ( const OIS::MouseEvent &e );
    virtual bool frameEnded ( const Ogre::FrameEvent &evt );
    virtual void windowResized ( Ogre::RenderWindow* rw );
    
     void stopRendering ( );
     void startRendering ( );


  private:
    ViewerOgre3D * mViewer;
    Ogre::RenderWindow * mWindow;
    bool mShutdown;
    OIS::Keyboard * mKeyboard;
    OIS::Mouse * mMouse;
    OIS::InputManager * mInputManager;
    Ogre::Camera * mCamera;
    CameraMan * mCameraMan;
    MouseCursor * mMouseCursor;
    bool isInShiftMode;
    Ogre::SceneManager * mSceneMgr;



  };
}
#include "ViewerOgre3D.h"
#include "InputListener.ih"
#endif /* INPUTLISTENER_H_ */
