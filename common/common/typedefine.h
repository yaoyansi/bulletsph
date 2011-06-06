#ifndef _TYPE_DEFINE_
#define _TYPE_DEFINE_

// For plug-ins that will forever be internal to your site use the constructor 
// that takes a single unsigned int parameter. The numeric range 0 - 0x7ffff (524288 ids)
// has been reserved for such plug-ins.
// 
// The example plug-ins provided with Maya in the plug-in development kit will use ids
// in the range 0x80000 - 0xfffff (524288 ids). If you customize one of these example 
// plug-ins, you should change the id to avoid future conflicts.
// 
// Plug-ins that are intended to be shared between sites will need to have a globally 
// unique id. The Autodesk Developer Network (ADN) will provide such id's in blocks of 
// 256. You will be assigned one or more 24-bit prefixes. Once this has been obtained, 
// used the MTypeId constructor that takes 2 unsigned int parameters. The prefix goes in
// the first parameter, and you are responsible for managing the allocation of the 256 ids 
// that go into the second parameter. 

enum TypeID
{
	TI_NULL = 0x00000000,

	TI_BULLET_SPH_NODE			= 0xFFFFF350,
	TI_BULLET_SPH_CONSTEXT		= 0xFFFFF351,
	TI_BULLET_SPH_EMITTER_NODE	= 0xFFFFF352,
	TI_BULLET_SPH_FIELD_NODE	= 0xFFFFF353,
	TI_BULLET_SPH_PARTICLE_ATTR_NODE	= 0xFFFFF354,
	TI_BULLET_SPH_CMD			= 0xFFFFF355,
	TI_BULLET_SPH_MGR_NODE		= 0xFFFFF356,

	TI_NUM,
};
//

extern const char *TN_BULLET_SPH_NODE;
extern const char *TN_BULLET_SPH_CONSTEXT;
extern const char *TN_BULLET_SPH_EMITTER_NODE;
extern const char *TN_BULLET_SPH_FIELD_NODE;
extern const char *TN_BULLET_SPH_PARTICLE_ATTR_NODE;
extern const char *TN_BULLET_SPH_CMD;
extern const char *TN_BULLET_SPH_MGR_NODE;

//
#endif