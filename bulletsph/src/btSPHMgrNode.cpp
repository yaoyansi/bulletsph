#include "btSPHMgrNode.h"
#include <common/prerequest_local.h>
#include <common/prerequest_std.h>
#include <common/mayacheck.h>

const MTypeId btSPHMgrNode::typeId( TI_BULLET_SPH_MGR_NODE );
const MString btSPHMgrNode::typeName(TN_BULLET_SPH_MGR_NODE);
MObject btSPHMgrNode::i_particleShape;
MObject btSPHMgrNode::i_particlePPAttr;
MObject btSPHMgrNode::i_particleCount;
MObject btSPHMgrNode::i_obstacleAABB;
MObject btSPHMgrNode::i_initAABB;
PLUGNAME_IMPLEMENT(btSPHMgrNode, particleShape,	ps)
PLUGNAME_IMPLEMENT(btSPHMgrNode, particlePPAttr,pppa)
PLUGNAME_IMPLEMENT(btSPHMgrNode, particleCount,	pc)
PLUGNAME_IMPLEMENT(btSPHMgrNode, obstacleBox,	obox)
PLUGNAME_IMPLEMENT(btSPHMgrNode, initBox,		ibox)

btSPHMgrNode::btSPHMgrNode()
{
	_LogFunctionCall("btSPHMgrNode::btSPHMgrNode()");
}

btSPHMgrNode::~btSPHMgrNode()
{
	_LogFunctionCall("btSPHMgrNode::~btSPHMgrNode()");
}
//
void btSPHMgrNode::addedCallback(MObject& node, void *clientData)
{
	_LogFunctionCall("btSPHMgrNode::addedCallback()");
}
//
void btSPHMgrNode::removedCallback(MObject& node, void *clientData)
{
	_LogFunctionCall("btSPHMgrNode::removedCallback()");
}
void* btSPHMgrNode::creator()
{
	_LogFunctionCall("btSPHMgrNode::creator()");

	return new btSPHMgrNode();
}

MStatus btSPHMgrNode::initialize()
{
	_LogFunctionCall("btSPHMgrNode::initialize()");

	MStatus status;
	MFnUnitAttribute uAttr;	
	MFnNumericAttribute nAttr;
	MFnTypedAttribute tAttr;

	i_particleShape = nAttr.create(particleShape, ps, MFnNumericData::kInt, 0, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(addAttribute(i_particleShape));

	i_particlePPAttr = nAttr.create(particlePPAttr, pppa, MFnNumericData::kInt, 0, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(addAttribute(i_particlePPAttr));

	i_particleCount = nAttr.create( particleCount, pc, MFnNumericData::kInt, 300,&status);
	IfMErrorWarn(status);
	IfMErrorWarn(addAttribute( i_particleCount ));

	i_obstacleAABB = tAttr.create(obstacleBox, obox, MFnData::kMesh, MObject::kNullObj, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(addAttribute(i_obstacleAABB));

	i_initAABB = tAttr.create(initBox, ibox, MFnData::kMesh, MObject::kNullObj, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(addAttribute(i_initAABB));

	return MS::kSuccess;
}


MStatus btSPHMgrNode::compute(const MPlug &plug, MDataBlock &data)
{
	_LogFunctionCall("btSPHMgrNode::compute("<< plug.name().asChar()<< ")");

	MStatus status;	
	
	return MS::kSuccess;
}