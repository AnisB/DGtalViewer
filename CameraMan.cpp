#include "CameraMan.h"


// Constructor
CameraMan::CameraMan ( Ogre::Camera * aCamera, int aSpeed , int aRotationSpeed ) : myCamera ( aCamera )
{

  // Initiate moving flags
  isGoingFoward = false;
  isGoingBackward = false;
  isGoingLeftward = false;
  isGoingRightward = false;

  // initate moving parameters
  mySpeed = aSpeed;
  myRotationSpeed = aRotationSpeed;
  TempMouseMove=Ogre::Vector3::ZERO;
  isOnShiftMode=false;

  // Initial Camera position and orientation
  myCamera->setPosition ( Ogre::Vector3 ( 300,300,300 ) );
  myCamera->lookAt ( Ogre::Vector3 ( 0,0,0 ) );
}

CameraMan::~CameraMan( )
{
  //Nothing to do
}

// OIS methods
bool CameraMan::handleKeyPress ( const OIS::KeyEvent & evt )
{
  switch ( evt.key )
    {
    case OIS::KC_LSHIFT :
      isOnShiftMode=true;
      break;
    case OIS::KC_Z :
      startGoingFoward();
      break;

    case OIS::KC_S :
      startGoingBackward();
      break;

    case OIS::KC_Q :
      startGoingLeftward();
      break;

    case OIS::KC_D :
      startGoingRightward();
      break;

    default :
      break;
    }
  return false;
}
bool CameraMan::handleKeyRelease ( const OIS::KeyEvent & evt )
{
  switch ( evt.key )
    {
    case OIS::KC_LSHIFT :
      isOnShiftMode=false;
      break;
    case OIS::KC_Z :
      stopGoingFoward();
      break;

    case OIS::KC_S :
      stopGoingBackward();
      break;

    case OIS::KC_Q :
      stopGoingLeftward();
      break;

    case OIS::KC_D :
      stopGoingRightward();
      break;

    default :
      break;
    }
  return false;
}
bool CameraMan::handleMouseMove ( const OIS::MouseEvent & evt )
{
  TempMouseMove=Ogre::Vector3 ( -0.05f*evt.state.X.rel,-0.05f*evt.state.Y.rel,-0.05f*evt.state.Z.rel );
  return false;
}
bool CameraMan::handleMouseClick ( const OIS::MouseEvent &e, OIS::MouseButtonID id )
{

  return false;
}
bool CameraMan::handleMouseRelease ( const OIS::MouseEvent &e, OIS::MouseButtonID id )
{

  return false;
}



// General methods
void CameraMan::Render ( const Ogre::FrameEvent & evt )
{
  double step = ( double ) evt.timeSinceLastFrame*mySpeed;
  if ( isOnShiftMode )
    {

      if ( isGoingFoward )
        {
          Ogre::Vector3 NewPosition ( myCamera->getPosition() );
          NewPosition-= ( myCamera->getOrientation().zAxis() *step );
          myCamera->setPosition ( NewPosition );
        }


      if ( isGoingBackward )
        {
          Ogre::Vector3 NewPosition ( myCamera->getPosition() );
          NewPosition+= ( myCamera->getOrientation().zAxis() *step );
          myCamera->setPosition ( NewPosition );
        }

      if ( isGoingLeftward )
        {
          Ogre::Vector3 NewPosition ( myCamera->getPosition() );
          NewPosition-= ( myCamera->getOrientation().xAxis() *step );
          myCamera->setPosition ( NewPosition );
        }

      if ( isGoingRightward )
        {
          Ogre::Vector3 NewPosition ( myCamera->getPosition() );
          NewPosition+=myCamera->getOrientation().xAxis() *step;
          myCamera->setPosition ( NewPosition );
        }

      if ( ( TempMouseMove.x!=0.f ) || ( TempMouseMove.y!=0.f ) || ( TempMouseMove.z!=0.f ) )
        {
          Ogre::Real pitchAngle;

          Ogre::Real pitchAngleSign;

          pitchAngle = ( 2 * Ogre::Degree ( Ogre::Math::ACos (
                                              this->myCamera->getOrientation().w ) ).valueDegrees() );

          pitchAngleSign = this->myCamera->getOrientation().x;

          if ( TempMouseMove.x != 0 )
            {
              myCamera->yaw ( Ogre::Degree ( TempMouseMove.x ) );
            }
          if ( TempMouseMove.y != 0 )
            {
              this->myCamera->pitch ( Ogre::Degree ( TempMouseMove.y ) );
            }
          if ( TempMouseMove.z != 0 )
            {
              this->myCamera->roll ( Ogre::Degree ( TempMouseMove.z ) );
            }
          TempMouseMove = Ogre::Vector3::ZERO;
        }
    }
}

