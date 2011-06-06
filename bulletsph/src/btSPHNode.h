
#ifndef _BULLET_SPH_NODE_
#define _BULLET_SPH_NODE_

#include <common/prerequest_maya.h>

class btSPHNode : public MPxEmitterNode
{
public:
	btSPHNode();
	virtual ~btSPHNode();
	static void addedCallback(MObject& node, void *clientData);
	static void removedCallback(MObject& node, void *clientData);

	static void *creator();
	static MStatus initialize();
	virtual void draw( M3dView&, const MDagPath&, M3dView::DisplayStyle,
						M3dView::DisplayStatus);
	virtual MStatus compute (const MPlug &plug, MDataBlock &dataBlock);

public:
	static const MTypeId typeId;
	static const MString typeName;
	//btSPHNode *m_instance;
    //static  MObject i_time;
    static  MObject o_float;

protected:
	void _destruct();
	void _init_on1stFrame();
	MTime	currentTimeValue( MDataBlock& block );
	MTime	startTimeValue( int plugIndex, MDataBlock& block );
	MTime	deltaTimeValue( int plugIndex, MDataBlock& block );

protected:
	MTime m_prevTime;

};

inline MTime btSPHNode::currentTimeValue( MDataBlock& block )
{
	MStatus status;

	MDataHandle hValue = block.inputValue( mCurrentTime, &status );

	MTime value(0.0);
	if( status == MS::kSuccess )
		value = hValue.asTime();

	return( value );
}

inline MTime btSPHNode::startTimeValue( int plugIndex, MDataBlock& block )
{
	MStatus status;
	MTime value(0.0);

	MArrayDataHandle mhValue = block.inputArrayValue( mStartTime, &status );
	if( status == MS::kSuccess )
	{
		status = mhValue.jumpToElement( plugIndex );
		if( status == MS::kSuccess )
		{
			MDataHandle hValue = mhValue.inputValue( &status );
			if( status == MS::kSuccess )
				value = hValue.asTime();
		}
	}

	return( value );
}

inline MTime btSPHNode::deltaTimeValue( int plugIndex, MDataBlock& block )
{
	MStatus status;
	MTime value(0.0);

	MArrayDataHandle mhValue = block.inputArrayValue( mDeltaTime, &status );
	if( status == MS::kSuccess )
	{
		status = mhValue.jumpToElement( plugIndex );
		if( status == MS::kSuccess )
		{
			MDataHandle hValue = mhValue.inputValue( &status );
			if( status == MS::kSuccess )
				value = hValue.asTime();
		}
	}

	return( value );
}



#endif//_BULLET_SPH_NODE_