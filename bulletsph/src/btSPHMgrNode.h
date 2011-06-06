
#ifndef _BULLET_SPH_MGR_NODE_
#define _BULLET_SPH_MGR_NODE_

#include "prerequest.h"

class btSPHMgrNode : public MPxNode
{
	PLUGNAME_DECLARE(particleShape,	ps)
	PLUGNAME_DECLARE(particlePPAttr,pppa)
	PLUGNAME_DECLARE(particleCount,	pc)
	PLUGNAME_DECLARE(obstacleBox,	obox)
	PLUGNAME_DECLARE(initBox,		ibox)
public:
	btSPHMgrNode();
	virtual ~btSPHMgrNode();
	static void addedCallback(MObject& node, void *clientData);
	static void removedCallback(MObject& node, void *clientData);

	static void *creator();
	static MStatus initialize();
// 	virtual void draw( M3dView&, const MDagPath&, M3dView::DisplayStyle,
// 		M3dView::DisplayStatus);
	virtual MStatus compute (const MPlug &plug, MDataBlock &dataBlock);

public:
	static const MTypeId typeId;
	static const MString typeName;

	static  MObject i_particleShape;//particle.count --> this.i_particleShape
	static	MObject	i_particlePPAttr;
	static	MObject	i_particleCount;
	static	MObject	i_obstacleAABB;
	static	MObject	i_initAABB;


protected:



protected:
	MTime m_prevTime;

};

#endif //_BULLET_SPH_MGR_NODE_