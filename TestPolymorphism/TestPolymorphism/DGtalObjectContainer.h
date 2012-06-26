	
#include <string.h>
#include <iostream>
using namespace std;	
	
	

	class DrawableWithOgre
	{
	  public:
	    DrawableWithOgre( ) { }
	    ~DrawableWithOgre() { }
	    virtual const char * className() const { return "a";}
	protected:
	  int typeClass;
	};





	template <class T> 
	class TDrawable : public TDrawableWithOgre
	{
	  public:
	    TDrawable()  { }
	    ~TDrawable()  { }
	 
	    virtual const char * className() const
	    {
	        return  (static_cast <T*>(myObject)->className()).c_str(); 
	    }
	protected :
	  T * myObject;

	};
