#include "btSPHNode.h"
#include <common/prerequest_local.h>
#include <common/prerequest_std.h>
#include <common/mayacheck.h>

#include "sph/bulletsph/bulletSPH.h"


const MTypeId btSPHNode::typeId( TI_BULLET_SPH_NODE );
const MString btSPHNode::typeName(TN_BULLET_SPH_NODE);
//MObject btSPHNode::i_time;
MObject btSPHNode::o_float;


btSPHNode* getSPHNode()
{
	_LogFunctionCall("getSPHNode()");

	MItDependencyNodes depIt(MFn::kPluginDependNode);
	for (; !depIt.isDone(); depIt.next()) 
	{
		MObject obj = depIt.thisNode();
		if (MFnDependencyNode(obj).typeId() == btSPHNode::typeId) 
		{
			MFnDependencyNode fnNode(obj);
			btSPHNode *context = dynamic_cast<btSPHNode*>(fnNode.userNode());
			assert(context!=NULL);
			return context;
		}
	}
	assert(0&&"btSPHNode not exist.");
	return NULL;
}


btSPHNode::btSPHNode()
{
	_LogFunctionCall("btSPHNode::btSPHNode()");


// 	solver = new Solver();
// 	meshutil = new MeshUtil();
// 	softsolver = new SoftSolver();
	//start();
}

btSPHNode::~btSPHNode()
{
	_LogFunctionCall("btSPHNode::~btSPHNode()");

	//end();
// 	SAFE_DELETE(softsolver);
// 	SAFE_DELETE(meshutil);
// 	SAFE_DELETE(solver);//this->_destruct();
}
//
void btSPHNode::addedCallback(MObject& node, void *clientData)
{
	_LogFunctionCall("btSPHNode::addedCallback()");
	


	//BulletSPH::start(100);

}
//
void btSPHNode::removedCallback(MObject& node, void *clientData)
{
	_LogFunctionCall("btSPHNode::removedCallback()");

	//BulletSPH::end();

}
void* btSPHNode::creator()
{
	_LogFunctionCall("btSPHNode::creator()");

	return new btSPHNode();
}

MStatus btSPHNode::initialize()
{
	_LogFunctionCall("btSPHNode::initialize()");
	
	MStatus status;
	MFnUnitAttribute uAttr;	
	MFnNumericAttribute nAttr;

// 	i_time = uAttr.create( "inTime", "it", MFnUnitAttribute::kTime, 1.0, &status );
// 	IfMErrorWarn(status);
// 	IfMErrorWarn(addAttribute(i_time));

	o_float = nAttr.create("oFloat", "of", MFnNumericData::kFloat,0.0, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(addAttribute(o_float));

	//attributeAffects(i_time , o_float );


	return MS::kSuccess;
}
void btSPHNode::_init_on1stFrame()
{
	_LogFunctionCall("btSPHNode::_init_on1stFrame()");
	m_prevTime = 0.0;
}
void btSPHNode::_destruct()
{
	_LogFunctionCall("btSPHNode::_destruct()");
}

void btSPHNode::draw( M3dView& view,
					  const MDagPath& DGpath,
					  M3dView::DisplayStyle dstyle,
					  M3dView::DisplayStatus dstatus )
{
	//_LogFunctionCall("btSPHNode::draw()");
	MStatus status;

	view.beginGL();
		glPushAttrib( GL_CURRENT_BIT );

			MMatrix modelview;
			IfMErrorWarn( view.modelViewMatrix(modelview) );
			MTransformationMatrix transform(modelview);

			MVector trans(transform.getTranslation(MSpace::kWorld, &status));
			IfMErrorWarn(status);
		//	_LogDebug("transform:"<< trans.x <<", "<< trans.y <<", "<< trans.z );
			double rot[3];MTransformationMatrix::RotationOrder ord;
			IfMErrorWarn(transform.getRotation(rot, ord));
		//	_LogDebug("rotate:"<< rot[0] <<", "<< rot[1] <<", "<< rot[2] );

			int width  = view.portWidth(&status);
			IfMErrorWarn(status);
			int height = view.portHeight(&status);
			IfMErrorWarn(status);


			//BulletSPH::simulate(0.0);
			BulletSPH::reshape(width, height);
			BulletSPH::display( &(modelview.matrix[0][0]) );

		glPopAttrib();
	view.endGL();
}

MStatus btSPHNode::compute(const MPlug &plug, MDataBlock &data)
{
	_LogFunctionCall("btSPHNode::compute("<< plug.name().asChar()<< ")");
	
	MStatus status;

	if( !(plug == mOutput) )
		return( MS::kUnknownParameter );

	int multiIndex = plug.logicalIndex( &status );
	IfMErrorWarn(status);
// 	MTime time = data.inputValue(i_time, &status).asTime();
// 	IfMErrorWarn(status)
	MTime cT = currentTimeValue( data );
	MTime sT = startTimeValue( multiIndex, data );
	MTime dT = deltaTimeValue( multiIndex, data );
	if( dT <= 0.0 )
	{
		_LogDebug("NOTE::: dT <= 0.0 ");
		// We do not emit particles before the start time, 
		// and do not emit particles when moving backwards in time.
		// 

		// This code is necessary primarily the first time to 
		// establish the new data arrays allocated, and since we have 
		// already set the data array to length zero it does 
		// not generate any new particles.
		// 
		//hOut.set( dOutput );
		data.setClean( plug );

		return( MS::kSuccess );
	}

	if( cT <= sT )
	{
		_LogDebug("NOTE:::cT <= sT ");
		_init_on1stFrame();
	}else{
		if( cT > m_prevTime )
		{
		_LogDebug("NOTE:::cT <= sT simulate");

			double duration = dT.value();
// 			BulletSPH::simulate(duration);
// 			BulletSPH::idle();


		}else if(cT == m_prevTime ){
			_LogDebug("time == m_prevTime\n");
		}else {
			_LogDebug("time < m_prevTime\n");
		}
	}

	m_prevTime = cT;


	return MS::kSuccess;
}