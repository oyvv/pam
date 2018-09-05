#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "05";
	static const char MONTH[] = "09";
	static const char YEAR[] = "2018";
	static const char UBUNTU_VERSION_STYLE[] =  "18.09";
	
	//Software Status
	static const char STATUS[] =  "Release";
	static const char STATUS_SHORT[] =  "r";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 596;
	static const long REVISION  = 3406;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 1648;
	#define RC_FILEVERSION 1,0,596,3406
	#define RC_FILEVERSION_STRING "1, 0, 596, 3406\0"
	static const char FULLVERSION_STRING [] = "1.0.596.3406";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 0;
	

}
#endif //VERSION_H
