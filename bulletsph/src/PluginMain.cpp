//#include "prerequest.h"
#include <common/prerequest_ogl.h>
#include <common/prerequest_local.h>
#include <common/mayacheck.h>
#include <maya/MFnPlugin.h>

// #include "BasicHwShader.h"
// #include "BasicHwShaderBehavior.h"
// #include "ownerEmitter.h"
//#include "btSPHContext.h"
#include "btSPHNode.h"
#include "simpleFluidEmitter.h"
//#include "torusField.h"
#include "btSPHCmd.h"
#include "particleAttrNode.h"
#include "btSPHMgrNode.h"

// required to link the libraries under VisualC++/Win32
#ifdef WIN32
// 	#pragma comment(lib,"Foundation.lib")
// 	#pragma comment(lib,"OpenMaya.lib")
// 	#pragma comment(lib,"OpenMayaFx.lib")
// 	#pragma comment(lib,"OpenMayaUi.lib")
// 	#pragma comment(lib,"Image.lib")
// 	#pragma comment(lib,"OpenMayaAnim.lib")
// 	#pragma comment(lib,"OpenGl32.lib")
// 	#pragma comment(lib,"glu32.lib")
// 	#pragma comment(lib,"glut32.lib")
#endif

// under WIN32 we have to 'export' these functions so that they are visible
// inside the dll. If maya can't see the functions, it can't load the plugin!
#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else 
	#define EXPORT
#endif


/// \brief	This function is called once when our plugin is loaded. We can use
///			it to register any custom nodes, mel functions etc.
/// \param	obj	-	a handle to the loaded plugin
/// \return	an MStatus error code
///
EXPORT MStatus initializePlugin( MObject obj )
{
	_LogFunctionCall("initializePlugin()");
	
	init_logs("c:/bulletSPH.log");
	MStatus   status;

	// a classification for where the node will appear on the create menus
	// of the multilister and hypershade.
	const MString UserClassify( "shader/surface" );

	MFnPlugin plugin( obj, "Rob Bateman", "1.0", "Any");

	//
	//status = plugin.registerNode( btSPHContext::typeName, 
	//								btSPHContext::typeId,
	//								btSPHContext::creator,
	//								btSPHContext::initialize,
	//								MPxNode::kLocatorNode );
	//IfMErrorMsgReturn(status, "regist btSPHContext error.", status);
	//MCallbackId CallbackID_AddSPHContext = 
	//	MDGMessage::addNodeAddedCallback(
	//	btSPHContext::addedCallback, 
	//	btSPHContext::typeName, &status
	//	);
	//IfMErrorWarn(status);
	//MCallbackId CallbackID_RemoveSPHContext = 
	//	MDGMessage::addNodeRemovedCallback(
	//	btSPHContext::removedCallback, 
	//	btSPHContext::typeName, &status
	//	);
	//IfMErrorWarn(status);

	////
	status = plugin.registerNode( btSPHNode::typeName, 
									btSPHNode::typeId,
									btSPHNode::creator,
									btSPHNode::initialize,
									MPxNode::kEmitterNode );
	IfMErrorMsgReturn(status, "regist btSPHNode error.", status);
	MCallbackId CallbackID_AddSPHNode = 
		MDGMessage::addNodeAddedCallback(
		btSPHNode::addedCallback, 
		btSPHNode::typeName, &status
		);
	IfMErrorWarn(status);
	MCallbackId CallbackID_RemoveSPHNode = 
		MDGMessage::addNodeRemovedCallback(
		btSPHNode::removedCallback,
		btSPHNode::typeName, &status
		);
	IfMErrorWarn(status);

	////
	//status = plugin.registerNode( simpleFluidEmitter::typeName,
	//	simpleFluidEmitter::typeId,
	//	simpleFluidEmitter::creator,
	//	simpleFluidEmitter::initialize,
	//	MPxNode::kFluidEmitterNode );
	//IfMErrorWarn(status);
	//
	////
	//status = plugin.registerNode( torusField::typeName,
	//	torusField::typeId,
	//	torusField::creator,
	//	torusField::initialize,
	//	MPxNode::kFieldNode );
	//IfMErrorWarn(status);

	//
	status = plugin.registerNode(
		particleAttrNode::typeName,
		particleAttrNode::typeId,
		particleAttrNode::creator,
		particleAttrNode::initialize,
		MPxNode::kParticleAttributeMapperNode );
	IfMErrorWarn(status);

	//
	status = plugin.registerCommand( 
		btSPHCmd::typeName, 
		btSPHCmd::creator, 
		btSPHCmd::newSyntax);
	IfMErrorMsgReturn(status, "regist btSPHCmd error.", status);

	//
	status = plugin.registerNode(
		btSPHMgrNode::typeName,
		btSPHMgrNode::typeId,
		btSPHMgrNode::creator,
		btSPHMgrNode::initialize,
		MPxNode::kDependNode );
	IfMErrorWarn(status);
	//
	MGlobal::executeCommand("source \"SPHMain.mel\"; g_btSPH_Start();");

	return status;
}

/// \brief	This function is called once when our plugin is unloaded. We need
/// 		to tell maya which mel funcs, nodes etc we are removing.
/// \param	obj	-	a handle to the loaded plugin
/// \return	an MStatus error code
///
EXPORT MStatus uninitializePlugin( MObject obj)
{
	_LogFunctionCall("uninitializePlugin()");

	MStatus   status;
	MFnPlugin plugin( obj );

	//
	//status = plugin.deregisterNode( btSPHContext::typeId );
	//IfMErrorMsgReturn(status, "deregist btSPHContext error.", status);
	//
	////
	status = plugin.deregisterNode( btSPHNode::typeId );
	IfMErrorMsgReturn(status, "deregist btSPHNode error.", status);

	////
	//status = plugin.deregisterNode( simpleFluidEmitter::typeId );
	//IfMErrorMsgReturn(status, "deregist simpleFluidEmitter error.", status);

	////
	//status = plugin.deregisterNode( torusField::typeId );
	//IfMErrorMsgReturn(status, "deregist torusField error.", status);
	//
	//
	status = plugin.deregisterNode( particleAttrNode::typeId );
	IfMErrorMsgReturn(status, "deregist particleAttrNode error.", status);
	
	//
	status = plugin.deregisterCommand( btSPHCmd::typeName );				
	IfMErrorMsgReturn(status, "deregist btSPHCmd error.", status);
	//
	status = plugin.deregisterNode( btSPHMgrNode::typeId );
	IfMErrorMsgReturn(status, "deregist btSPHMgrNode error.", status);

	//
	MGlobal::executeCommand("source \"SPHMain.mel\"; g_btSPH_End();");

	close_logs();
	return status;
}
