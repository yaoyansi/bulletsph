#include "particleAttrNode.h"
#include "sph/bulletsph/bulletsph.h"

const MTypeId particleAttrNode::typeId(TI_BULLET_SPH_PARTICLE_ATTR_NODE);
const MString particleAttrNode::typeName(TN_BULLET_SPH_PARTICLE_ATTR_NODE);
MObject particleAttrNode::outPositionPP;
MObject particleAttrNode::i_particleCount;
MObject particleAttrNode::o_dummy;
PLUGNAME_IMPLEMENT(particleAttrNode, dummy,				d)
PLUGNAME_IMPLEMENT(particleAttrNode, particleCount,		pc)

#ifdef _USE_TIME_PLUG_
MObject particleAttrNode::o_Time;
#endif

// particleAttrNode* particleAttrNode::getNodePtr()
// {
// 	_LogFunctionCall("particleAttrNode::getNodePtr()");
// 
// 	MItDependencyNodes depIt(MFn::kPluginDependNode);
// 	for (; !depIt.isDone(); depIt.next()) 
// 	{
// 		MObject obj = depIt.thisNode();
// 		if (MFnDependencyNode(obj).typeId() == particleAttrNode::typeId) 
// 		{
// 			MFnDependencyNode fnNode(obj);
// 			particleAttrNode *context = dynamic_cast<particleAttrNode*>(fnNode.userNode());
// 			assert(context!=NULL);
// 			return context;
// 		}
// 	}
// 	assert(0&&"particleAttrNode not exist.");
// 	return NULL;
// }
particleAttrNode::particleAttrNode()
{
	_LogFunctionCall("particleAttrNode::particleAttrNode()");
}

particleAttrNode::~particleAttrNode()
{
	_LogFunctionCall("particleAttrNode::~particleAttrNode()");
}

void* particleAttrNode::creator()
{
	_LogFunctionCall("particleAttrNode::creator()");
	return new particleAttrNode();
}

MStatus particleAttrNode::initialize()
{
	_LogFunctionCall("particleAttrNode::initialize()");
	MStatus status = MS::kSuccess;
	
	MFnUnitAttribute uAttr;
	MFnNumericAttribute nAttr;

	// In addition to the standard arrayMapper attributes,
	// create an additional vector attribute.
	//
	MFnTypedAttribute tAttr;
	MVectorArray defaultVectArray;
	MFnVectorArrayData vectArrayDataFn;
	vectArrayDataFn.create( defaultVectArray );
	outPositionPP = tAttr.create( "outPosition", "opos", MFnData::kVectorArray, vectArrayDataFn.object(), &status );
	IfMErrorWarn(tAttr.setWritable(false));
	IfMErrorWarn(tAttr.setStorable(false));
	IfMErrorWarn(addAttribute( outPositionPP ));

	i_particleCount = nAttr.create( particleCount, pc, MFnNumericData::kInt, 0, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(addAttribute( i_particleCount ));


#ifdef _USE_TIME_PLUG_
	o_Time = uAttr.create( "oTime", "ot", MFnUnitAttribute::kTime, 1.0, &status );
	IfMErrorWarn(status);
	uAttr.setStorable(false);
	IfMErrorWarn(addAttribute(o_Time));

	IfMErrorWarn(attributeAffects(time , outPositionPP ));
	IfMErrorWarn(attributeAffects(time , o_Time ));
#endif

	o_dummy = nAttr.create(dummy, d, MFnNumericData::kInt, 0, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(addAttribute(o_dummy));
	
	//input/output
	IfMErrorWarn(attributeAffects( computeNode, outPositionPP ));
	IfMErrorWarn(attributeAffects( i_particleCount, outPositionPP ));
	return status;
}

MStatus particleAttrNode::compute( const MPlug& plug, MDataBlock& block )
{
	_LogFunctionCall("particleAttrNode::compute("<<plug.name() <<")");
	MStatus status = MS::kUnknownParameter;
	
	if( plug == outPositionPP )
	{
		status = computeMesh( plug, block );
		return status;
	}
#ifdef _USE_TIME_PLUG_
	else if(plug == o_Time){
		MTime itime = block.inputValue( time ).asTime();
		block.outputValue( o_Time ).set(itime);
		block.outputValue( o_Time ).setClean();

		return MS::kSuccess;
	}
#endif
	return status;
}

MStatus particleAttrNode::computeMesh( const MPlug& plug, MDataBlock& block )
{
	_LogFunctionCall("particleAttrNode::computeMesh()");
	MStatus status = MS::kSuccess;

	//simulate
	BulletSPH::simulate(0.0);

	//get particle number

	int n = block.inputValue( i_particleCount ).asInt();
	unsigned int nParticles = (n>0)? n:0;


	// Get pointer to destination attribute: outPositionPP
	MDataHandle dh = block.outputValue( outPositionPP, &status );
 	IfMErrorWarn(status);

	MObject posD = dh.data();

	MFnVectorArrayData dataVectorArrayFn;
	status = dataVectorArrayFn.setObject( posD );

	MVectorArray outPosArray;	
	if( status == MS::kSuccess )
	{
		outPosArray = dataVectorArrayFn.array();
	}

	outPosArray.setLength( nParticles );
	//set new positions
	fetchParticleData( outPosArray );

	dataVectorArrayFn.set( outPosArray );
	dh.setClean();//!
	return MS::kSuccess;
}

void particleAttrNode::fetchParticleData(MVectorArray &o_position )
{
	_LogFunctionCall("particleAttrNode::fetchParticleData()");

	MStatus status;

	size_t btParticleCount = BulletSPH::getPrticleCount();

	//assert((particleCount+1)==positions.length()); why?
	if( (btParticleCount+1) != o_position.length() )
	{
		_LogDebug("btParticleCount="<<btParticleCount);
		_LogDebug("particleAttrNode::o_position.length()="<<o_position.length());
	}
	
	size_t END = btParticleCount;//o_position.length();
	for(size_t i=0; i<END; ++i)
	{
		FluidParticle* pParticle = BulletSPH::getPrticle(i);
		assert(pParticle!=NULL);

		//position
// 		o_position[i].x =  pParticle->pos.x;
// 		o_position[i].y = -pParticle->pos.z;
// 		o_position[i].z =  pParticle->pos.y;
 		o_position[i].x =  pParticle->pos.x;
 		o_position[i].y =  pParticle->pos.y;
 		o_position[i].z =  pParticle->pos.z;

	}


}
