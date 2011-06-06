//-
// ==========================================================================
// Copyright 1995,2006,2008 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk
// license agreement provided at the time of installation or download,
// or which otherwise accompanies this software in either electronic
// or hard copy form.
// ==========================================================================
//+

#include "prerequest.h"


class simpleFluidEmitter: public MPxFluidEmitterNode
{
public:
	simpleFluidEmitter();
	virtual ~simpleFluidEmitter();

	static void		*creator();
	static MStatus	initialize();
	virtual MStatus	compute( const MPlug& plug, MDataBlock& block );
	static const MTypeId typeId;
	static const MString typeName;

	virtual MStatus fluidEmitter( const MObject& fluid, const MMatrix& worldMatrix, int plugIndex );
	void  omniFluidEmitter(  MFnFluid&, const MMatrix&, int, MDataBlock&, double, double, double );
	void volumeFluidEmitter(  MFnFluid&, const MMatrix&, int, MDataBlock&, double, double, double );
	void surfaceFluidEmitter( MFnFluid&, const MMatrix&, int, MDataBlock&, double, double, double );
	void ownerFluidEmitter( MFnFluid&, const MMatrix&, int, MDataBlock&, double, double, double );

private:

};



