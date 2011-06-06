#include "btSPHCmd.h"
#include <common/prerequest_std.h>
#include <common/prerequest_local.h>
#include <common/mayacheck.h>

#include "sph/bulletsph/bulletSPH.h"

using namespace std;

//#define _USE_ARG_
IMPLEMENT_PARAM(FRAME_RANGE, fr, framerange )
IMPLEMENT_PARAM(PARTICLE_COUNT, pc, particlecount )
// IMPLEMENT_PARAM(INITILIZE, init, initilize )
// IMPLEMENT_PARAM(UNINITILIZE, uninit, uninitilize )
IMPLEMENT_PARAM(CACHE, c, cache)
IMPLEMENT_PARAM(PARTICLE_NAME, pn, particleName)
// const char * kPARTICLE_NAME_S="-pn";
// const char * kPARTICLE_NAME_L="-particleName";

#ifdef _USE_ARG_
	#define kSPHInitFlag		"-myinit"
	#define kSPHInitFlagLong	"-myinitialize"
	#define kSPHUninitFlag		"-myuninit"
	#define kSPHUninitFlagLong	"-myuninitialize"
#endif


const MTypeId btSPHCmd::typeId(TI_BULLET_SPH_CMD);
const MString btSPHCmd::typeName(TN_BULLET_SPH_CMD);

#define getPlugValue_asDistance(target, fn, plugName) \
	{\
		plug = fn.findPlug(plugName, &status);\
		IfMErrorWarn(status);\
		MDistance v = plug.asMDistance(MDGContext::fsNormal, &status);\
		IfMErrorWarn(status);\
		target = v.value();\
	}

btSPHCmd::btSPHCmd()
{
	_LogFunctionCall("btSPHCmd::btSPHCmd()") ;

}
//
btSPHCmd::~btSPHCmd()
{
	_LogFunctionCall("btSPHCmd::~btSPHCmd()") ;
}
//
MSyntax btSPHCmd::newSyntax()
{	
	_LogFunctionCall("btSPHCmd::newSyntax()");

	MSyntax syntax;

	ADD_ARG2( FRAME_RANGE, MSyntax::kUnsigned, MSyntax::kUnsigned );
	ADD_ARG1( PARTICLE_COUNT, MSyntax::kUnsigned );
// 	ADD_ARG0( INITILIZE );
// 	ADD_ARG0( UNINITILIZE );
 	ADD_ARG0( CACHE );
	ADD_ARG1( PARTICLE_NAME, MSyntax::kString );
	//IfMErrorWarn(syntax.addFlag( "-pname", "-particleName", MSyntax::kString));
#ifdef _USE_ARG_
	IfMErrorWarn(syn.addFlag(kSPHInitFlag,  kSPHInitFlagLong, MSyntax::kLong));
	IfMErrorWarn(syn.addFlag(kSPHUninitFlag, kSPHUninitFlagLong));
#endif


	return syntax;
}
//
MStatus btSPHCmd::parseSyntax(MArgDatabase &argData)
{
	_LogFunctionCall("btSPHCmd::parseArgs()");

	MStatus status;

	GET_ARG2( FRAME_RANGE );
	GET_ARG1( PARTICLE_COUNT );
// 	GET_ARG0( INITILIZE );
// 	GET_ARG0( UNINITILIZE );
 	GET_ARG0( CACHE );
	GET_ARG1( PARTICLE_NAME );
#ifdef _USE_ARG_
	fInit  = argData.isFlagSet(kSPHInitFlagLong, &status);
	IfMErrorWarn(status);
	if (fInit){
		argData.getFlagArgument(kSPHInitFlagLong, 0, mParticleNum);
	}
#else
// 	fInit = true;
// 	mParticleNum = 100;
#endif


#ifdef _USE_ARG_
// 	fUninit = argData.isFlagSet(kSPHUninitFlagLong, &status);
// 	IfMErrorWarn(status);
#else
/*	fUninit = false;*/
#endif

	printArgs();

	return MStatus::kSuccess;
}
//

MStatus btSPHCmd::doIt ( const MArgList &args )
{ 
	_LogFunctionCall("btSPHCmd::doIt ()");

	MArgDatabase	argData( newSyntax(), args );
	parseSyntax( argData );

	if( FLAG( FRAME_RANGE ) ){
		size_t start = VARIABLE(FRAME_RANGE, 0);
		size_t end = VARIABLE(FRAME_RANGE, 1);
		onFrameRange( start, end );
	}
	// init
// 	if(FLAG(INITILIZE)){
// 		size_t particlecount = VARIABLE(PARTICLE_COUNT, 0);
// 		onInit(particlecount);
// 	}
	if(FLAG(PARTICLE_COUNT)){
		size_t particlecount = VARIABLE(PARTICLE_COUNT, 0);
		onInit(particlecount);
	}

// 	if(FLAG(UNINITILIZE))
// 	{
// 		onUninit();
// 	}

	return MS::kSuccess;
}
//
void btSPHCmd::printArgs()
{
	_LogFunctionCall("btSPHCmd::printArgs()");
	PRINT_ARG2(FRAME_RANGE);
	PRINT_ARG1(PARTICLE_COUNT);
// 	PRINT_ARG0(INITILIZE);
// 	PRINT_ARG0(UNINITILIZE);
 	PRINT_ARG0(CACHE);
 	PRINT_ARG1(PARTICLE_NAME);
	//_LogDebug("fInit="<<fInit<<", fUninit="<<fUninit);
}
//
MStatus btSPHCmd::onInit(const size_t particlecount)
{	
	_LogFunctionCall("btSPHCmd::onInit()");

	MStatus stat = MS::kSuccess;

	assert(particlecount!=0);

	MString obstaclebox;
	IfMErrorWarn(MGlobal::executeCommand("g_btSPH_getObstacleBoxName()", obstaclebox, true));
	MPoint omin, omax;
	getAABB(obstaclebox, omin, omax);

	MString initbox;
	IfMErrorWarn(MGlobal::executeCommand("g_btSPH_getInitBoxName()", initbox, true));
	MPoint imin, imax;
	getAABB(initbox, imin, imax);

	_LogDebug("<omin,omax>=<"<< omin.x <<","<<omin.y<<","<<omin.z<<"|"<< omax.x <<","<<omax.y<<","<<omax.z<<">");
	_LogDebug("<imin,imax>=<"<< imin.x <<","<<imin.y<<","<<imin.z<<"|"<< imax.x <<","<<imax.y<<","<<imax.z<<">");

	BulletSPH::start(particlecount,
 		omin.x,omin.y,omin.z,  omax.x,omax.y,omax.z,
 		imin.x,imin.y,imin.z,  imax.x,imax.y,imax.z	);

	return  MS::kSuccess;
}
//
MStatus btSPHCmd::onUninit()
{	
	_LogFunctionCall("btSPHCmd::onUninit()");

	MStatus stat = MS::kSuccess;
 
	BulletSPH::end();

	return  MS::kSuccess;
}

MStatus btSPHCmd::onFrameRange(size_t start, size_t end)
{
	_LogFunctionCall("btSPHCmd::onFrameRange("<<start<<","<<end<<")");

	if( FLAG(CACHE) )
	{
		//get cache directory
		MString cacheDir;
		IfMErrorWarn( MGlobal::executeCommand("getAttr dynGlobals1.cacheDirectory", cacheDir, true) );
		if(cacheDir.length()==0)
		{
			assert(cacheDir.length()!=0 &&"cache directory is empty!");
			_LogError("cache directory is empty!");
			return MS::kFailure;
		}

		//get particle name
		std::string pName(VARIABLE(PARTICLE_NAME,0).asChar());//std::string pName("btSPHPartical1");//

		//
		for(int frame = start; frame<=end; ++frame)
		{	
			_updateOneFrame(frame);

			//export particles of current frame 
			std::string tmp(cacheDir.asChar());
			std::stringstream cmd;
			cmd << "dynExport -path \""<< tmp <<"\" -f cache -mnf "<< frame <<" -mxf "<< frame <<" -oup 0 -all 0 " <<pName;
			IfMErrorWarn(MGlobal::executeCommand(cmd.str().c_str(), true));
		}

	}else{// no cache

		for(int frame = start; frame<=end; ++frame)
		{	
			_updateOneFrame(frame);
		}
	}

	return  MS::kSuccess;
}
void btSPHCmd::_updateOneFrame(int frame)
{
	//_LogFunctionCall("btSPHCmd::_updateOneFrame("<<frame<<")");

	//std::string sTime(int2str( frame ));
	// set the current time and update the world.
	std::stringstream cmd;
	cmd << "currentTime -update true " << frame;
	IfMErrorWarn(MGlobal::executeCommand(cmd.str().c_str(), true));

	_Log("frame: "<< frame);
}

void btSPHCmd::getAABB(const MString &name, MPoint& min, MPoint &max)
{
	_LogFunctionCall("btSPHCmd::getAABB("<< name<<")");

	MStatus status = MS::kSuccess;

	MSelectionList sList;
	IfMErrorWarn(MGlobal::getSelectionListByName(name, sList));
	
	assert(sList.length()==1);
	MDagPath dp;
	IfMErrorWarn(sList.getDagPath(0, dp));
	IfMErrorWarn(dp.extendToShape());//particle shape

	MFnMesh meshFn( dp, &status );
	IfMErrorWarn(status);

	MPointArray positions;
	IfMErrorWarn(meshFn.getPoints(positions, MSpace::kWorld));

	const size_t LEN = positions.length();
	for(size_t i=0; i<LEN; ++i)
	{
		const MPoint &p = positions[i];
		if(p.x<min.x) min.x = p.x;
		if(p.y<min.y) min.y = p.y;
		if(p.z<min.z) min.z = p.z;
		
		if(p.x>max.x) max.x = p.x;
		if(p.y>max.y) max.y = p.y;
		if(p.z>max.z) max.z = p.z;
	}

// 	MPlug plug;
// 	getPlugValue_asDistance(min.x, meshFn, "boundingBoxMinX");
//  	getPlugValue_asDistance(min.y, meshFn, "boundingBoxMinY");
//  	getPlugValue_asDistance(min.z, meshFn, "boundingBoxMinZ");
//  	getPlugValue_asDistance(max.x, meshFn, "boundingBoxMaxX");
//  	getPlugValue_asDistance(max.y, meshFn, "boundingBoxMaxY");
//  	getPlugValue_asDistance(max.z, meshFn, "boundingBoxMaxZ");

}