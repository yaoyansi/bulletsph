#ifndef _BT_SPH_CMD_
#define _BT_SPH_CMD_


#include "prerequest.h"

class btSPHCmd : public MPxCommand
{
	typedef MPxCommand super;
public:
	btSPHCmd();
	virtual ~btSPHCmd();

	virtual bool isUndoable() const { return false; }

	virtual MStatus	doIt ( const MArgList& );
	static void *creator() { return new btSPHCmd; }

	static MSyntax newSyntax();

	static  const MTypeId     typeId;
	static  const MString     typeName;

	MStatus onInit(const size_t particlecount);
	MStatus onUninit();
	MStatus onFrameRange(size_t minFrame, size_t maxFrame);

protected:
	MStatus parseSyntax (MArgDatabase &argData);
	void printArgs();
	void getAABB(const MString &name, MPoint& min, MPoint &max);


	DECLARE_PARAM2(FRAME_RANGE, size_t, size_t)	//frame range min max
	DECLARE_PARAM1(PARTICLE_COUNT, size_t)	//how many particles
// 	DECLARE_PARAM0(INITILIZE)	//initilize
// 	DECLARE_PARAM0(UNINITILIZE)	//uninitilize
 	DECLARE_PARAM0(CACHE)	//cache
 	DECLARE_PARAM1(PARTICLE_NAME, MString)	//cache

	void _updateOneFrame(int frame);


	MDGModifier dgMod;

};

#endif//#ifndef _BT_SPH_CMD_