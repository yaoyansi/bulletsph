#ifndef _PREREQUEST_MAYA_H_
#define _PREREQUEST_MAYA_H_

#ifdef _USE_OPENGL_
#include "prerequest_ogl.h"
#endif

#include <maya/M3dView.h>                                           
#include <maya/MAngle.h>                                            
#include <maya/MAnimControl.h>                                      
#include <maya/MAnimCurveChange.h>                                  
#include <maya/MAnimCurveClipboard.h>                               
#include <maya/MAnimCurveClipboardItem.h>                           
#include <maya/MAnimCurveClipboardItemArray.h>                      
#include <maya/MAnimMessage.h>                                      
#include <maya/MAnimUtil.h>                                         
//#include <maya/MApiVersion.h>                                       
#include <maya/MArgDatabase.h>                                      
#include <maya/MArgList.h>                                          
#include <maya/MArgParser.h>                                        
#include <maya/MArrayDataBuilder.h>                                 
#include <maya/MArrayDataHandle.h>                                  
//#include <maya/MAtomic.h>//maya2009 only                                           
#include <maya/MAttributeIndex.h>                                   
#include <maya/MAttributeSpec.h>                                    
#include <maya/MAttributeSpecArray.h>                               
#include <maya/MBoundingBox.h>                                      
#include <maya/MCallbackIdArray.h>                                  
#include <maya/MClothConstraint.h>                                  
#include <maya/MClothConstraintBridge.h>                            
#include <maya/MClothConstraintCmd.h>                               
#include <maya/MClothControl.h>                                     
#include <maya/MClothEdge.h>                                        
#include <maya/MClothForce.h>                                       
#include <maya/MClothMaterial.h>                                    
#include <maya/MClothParticle.h>                                    
#include <maya/MClothPolyhedron.h>                                  
#include <maya/MClothSolverRegister.h>                              
#include <maya/MClothSystem.h>                                      
#include <maya/MClothTriangle.h>                                    
#include <maya/MClothTypes.h>                                       
#include <maya/MColor.h>                                            
#include <maya/MColorArray.h>                                       
#include <maya/MCommandMessage.h>                                   
#include <maya/MCommandResult.h>                                    
#include <maya/MCommonRenderSettingsData.h>                         
#include <maya/MCommonSystemUtils.h>                                
#include <maya/MComputation.h>                                      
#include <maya/MConditionMessage.h>                                 
//#include <maya/MContainerMessage.h>//maya2009 only                                 
#include <maya/MCursor.h>                                           
#include <maya/MD3D9Renderer.h>                                     
#include <maya/MDagMessage.h>                                       
#include <maya/MDagModifier.h>                                      
#include <maya/MDagPath.h>                                          
#include <maya/MDagPathArray.h>                                     
#include <maya/MDataBlock.h>                                        
#include <maya/MDataHandle.h>                                       
#include <maya/MDeviceChannel.h>                                    
#include <maya/MDeviceState.h>                                      
#include <maya/MDGContext.h>                                        
#include <maya/MDGMessage.h>                                        
#include <maya/MDGModifier.h>                                       
#include <maya/MDistance.h>                                         
#include <maya/MDoubleArray.h>                                      
#include <maya/MDrawData.h>                                         
#include <maya/MDrawInfo.h>                                         
#include <maya/MDrawProcedureBase.h>                                
#include <maya/MDrawRequest.h>                                      
#include <maya/MDrawRequestQueue.h>                                 
#include <maya/MDrawTraversal.h>                                    
#include <maya/MDynamicsUtil.h>                                     
#include <maya/MDynSweptLine.h>                                     
#include <maya/MDynSweptTriangle.h>                                 
#include <maya/MEulerRotation.h>                                    
#include <maya/MEvent.h>                                            
#include <maya/MEventMessage.h>                                     
#include <maya/MFeedbackLine.h>                                     
#include <maya/MFileIO.h>                                           
#include <maya/MFileObject.h>                                       
#include <maya/MFloatArray.h>                                       
#include <maya/MFloatMatrix.h>                                      
#include <maya/MFloatPoint.h>                                       
#include <maya/MFloatPointArray.h>                                  
#include <maya/MFloatVector.h>                                      
#include <maya/MFloatVectorArray.h>                                 
#include <maya/MFn.h>                                               
#include <maya/MFnAirField.h>                                       
#include <maya/MFnAmbientLight.h>                                   
#include <maya/MFnAnimCurve.h>                                      
#include <maya/MFnAnisotropyShader.h>                               
#include <maya/MFnAreaLight.h>                                      
#include <maya/MFnArrayAttrsData.h>                                 
#include <maya/MFnAttribute.h>                                      
#include <maya/MFnBase.h>                                           
#include <maya/MFnBlendShapeDeformer.h>                             
#include <maya/MFnBlinnShader.h>                                    
#include <maya/MFnCamera.h>                                         
#include <maya/MFnCharacter.h>                                      
#include <maya/MFnCircleSweepManip.h>                               
#include <maya/MFnClip.h>                                           
#include <maya/MFnComponent.h>                                      
#include <maya/MFnComponentListData.h>                              
#include <maya/MFnCompoundAttribute.h>                              
//#include <maya/MFnContainerNode.h>//maya2009 only                                  
#include <maya/MFnCurveSegmentManip.h>                              
#include <maya/MFnDagNode.h>                                        
#include <maya/MFnData.h>                                           
#include <maya/MFnDependencyNode.h>                                 
#include <maya/MFnDirectionalLight.h>                               
#include <maya/MFnDirectionManip.h>                                 
#include <maya/MFnDiscManip.h>                                      
#include <maya/MFnDistanceManip.h>                                  
#include <maya/MFnDoubleArrayData.h>                                
#include <maya/MFnDoubleIndexedComponent.h>                         
#include <maya/MFnDragField.h>                                      
#include <maya/MFnDynSweptGeometryData.h>                           
#include <maya/MFnEnumAttribute.h>                                  
#include <maya/MFnExpression.h>                                     
#include <maya/MFnField.h>                                          
#include <maya/MFnFluid.h>                                          
#include <maya/MFnFreePointTriadManip.h>                            
#include <maya/MFnGenericAttribute.h>                               
#include <maya/MFnGeometryData.h>                                   
#include <maya/MFnGeometryFilter.h>                                 
#include <maya/MFnGravityField.h>                                   
#include <maya/MFnHikEffector.h>                                    
#include <maya/MFnIkEffector.h>                                     
#include <maya/MFnIkHandle.h>                                       
#include <maya/MFnIkJoint.h>                                        
#include <maya/MFnIkSolver.h>                                       
#include <maya/MFnInstancer.h>                                      
#include <maya/MFnIntArrayData.h>                                   
#include <maya/MFnKeyframeDelta.h>                                  
#include <maya/MFnKeyframeDeltaAddRemove.h>                         
#include <maya/MFnKeyframeDeltaBlockAddRemove.h>                    
#include <maya/MFnKeyframeDeltaBreakdown.h>                         
#include <maya/MFnKeyframeDeltaInfType.h>                           
#include <maya/MFnKeyframeDeltaMove.h>                              
#include <maya/MFnKeyframeDeltaScale.h>                             
#include <maya/MFnKeyframeDeltaTangent.h>                           
#include <maya/MFnKeyframeDeltaWeighted.h>                          
#include <maya/MFnLambertShader.h>                                  
#include <maya/MFnLattice.h>                                        
#include <maya/MFnLatticeData.h>                                    
#include <maya/MFnLatticeDeformer.h>                                
#include <maya/MFnLayeredShader.h>                                  
#include <maya/MFnLight.h>                                          
#include <maya/MFnLightDataAttribute.h>                             
#include <maya/MFnManip3D.h>                                        
#include <maya/MFnMatrixAttribute.h>                                
#include <maya/MFnMatrixData.h>                                     
#include <maya/MFnMesh.h>                                           
#include <maya/MFnMeshData.h>                                       
#include <maya/MFnMessageAttribute.h>                               
#include <maya/MFnMotionPath.h>                                     
#include <maya/MFnNewtonField.h>                                    
#include <maya/MFnNObjectData.h>                                    
#include <maya/MFnNonAmbientLight.h>                                
#include <maya/MFnNonExtendedLight.h>                               
#include <maya/MFnNumericAttribute.h>                               
#include <maya/MFnNumericData.h>                                    
#include <maya/MFnNurbsCurve.h>                                     
#include <maya/MFnNurbsCurveData.h>                                 
#include <maya/MFnNurbsSurface.h>                                   
#include <maya/MFnNurbsSurfaceData.h>                               
#include <maya/MFnParticleSystem.h>                                 
#include <maya/MFnPartition.h>                                      
#include <maya/MFnPfxGeometry.h>                                    
#include <maya/MFnPhongEShader.h>                                   
#include <maya/MFnPhongShader.h>                                    
//#include <maya/MFnPlugin.h>                                         
#include <maya/MFnPluginData.h>                                     
#include <maya/MFnPointArrayData.h>                                 
#include <maya/MFnPointLight.h>                                     
#include <maya/MFnPointOnCurveManip.h>                              
#include <maya/MFnPointOnSurfaceManip.h>                            
#include <maya/MFnRadialField.h>                                    
#include <maya/MFnReflectShader.h>                                  
#include <maya/MFnRenderLayer.h>                                    
//#include <maya/MFnRenderPass.h>//maya2009 only                                     
#include <maya/MFnRotateManip.h>                                    
#include <maya/MFnScaleManip.h>                                     
#include <maya/MFnSet.h>                                            
#include <maya/MFnSingleIndexedComponent.h>                         
#include <maya/MFnSkinCluster.h>                                    
#include <maya/MFnSphereData.h>                                     
#include <maya/MFnSpotLight.h>                                      
#include <maya/MFnStateManip.h>                                     
#include <maya/MFnStringArrayData.h>                                
#include <maya/MFnStringData.h>                                     
#include <maya/MFnSubd.h>                                           
#include <maya/MFnSubdData.h>                                       
#include <maya/MFnSubdNames.h>                                      
#include <maya/MFnToggleManip.h>                                    
#include <maya/MFnTransform.h>                                      
#include <maya/MFnTripleIndexedComponent.h>                         
#include <maya/MFnTurbulenceField.h>                                
#include <maya/MFnTypedAttribute.h>                                 
#include <maya/MFnUInt64ArrayData.h>                                
//#include <maya/MFnUint64SingleIndexedComponent.h>                   
#include <maya/MFnUniformField.h>                                   
#include <maya/MFnUnitAttribute.h>                                  
#include <maya/MFnVectorArrayData.h>                                
#include <maya/MFnVolumeAxisField.h>                                
#include <maya/MFnVolumeLight.h>                                    
#include <maya/MFnVortexField.h>                                    
#include <maya/MFnWeightGeometryFilter.h>                           
#include <maya/MFnWireDeformer.h>                                   
#include <maya/MFStream.h>                                          
#include <maya/MGeometry.h>                                         
#include <maya/MGeometryData.h>                                     
#include <maya/MGeometryList.h>                                     
#include <maya/MGeometryManager.h>                                  
#include <maya/MGeometryPrimitive.h>                                
#include <maya/MGeometryRequirements.h>                             
#include <maya/MGLdefinitions.h>                                    
#include <maya/MGLFunctionTable.h>                                  
#include <maya/MGlobal.h>                                           
#include <maya/MHairSystem.h>                                       
#include <maya/MHardwareRenderer.h>                                 
#include <maya/MHwrCallback.h>                                      
#include <maya/MHWShaderSwatchGenerator.h>                          
#include <maya/MHwTextureManager.h>                                 
#include <maya/MIffFile.h>                                          
#include <maya/MIffTag.h>                                           
#include <maya/MIkHandleGroup.h>                                    
#include <maya/MIkSystem.h>                                         
#include <maya/MImage.h>                                            
#include <maya/MImageFileInfo.h>                                    
#include <maya/MIntArray.h>                                         
#include <maya/MIOStream.h>                                         
#include <maya/MIOStreamFwd.h>                                      
#include <maya/MItCurveCV.h>                                        
#include <maya/MItDag.h>                                            
#include <maya/MItDependencyGraph.h>                                
#include <maya/MItDependencyNodes.h>                                
#include <maya/MIteratorType.h>                                     
#include <maya/MItGeometry.h>                                       
#include <maya/MItInstancer.h>                                      
#include <maya/MItKeyframe.h>                                       
#include <maya/MItMeshEdge.h>                                       
#include <maya/MItMeshFaceVertex.h>                                 
#include <maya/MItMeshPolygon.h>                                    
#include <maya/MItMeshVertex.h>                                     
#include <maya/MItSelectionList.h>                                  
#include <maya/MItSubdEdge.h>                                       
#include <maya/MItSubdFace.h>                                       
#include <maya/MItSubdVertex.h>                                     
#include <maya/MItSurfaceCV.h>                                      
#include <maya/MLibrary.h>                                          
#include <maya/MLightLinks.h>                                       
#include <maya/MLockMessage.h>                                      
#include <maya/MManipData.h>                                        
#include <maya/MMaterial.h>                                         
#include <maya/MMatrix.h>                                           
#include <maya/MMatrixArray.h>                                      
#include <maya/MMeshIntersector.h>                                  
//#include <maya/MMeshSmoothOptions.h>                                
#include <maya/MMessage.h>                                          
#include <maya/MModelMessage.h>                                     
#include <maya/MMutexLock.h>                                        
#include <maya/MnCloth.h>                                           
#include <maya/MNodeMessage.h>                                      
//#include <maya/MNurbsIntersector.h>                                 
#include <maya/MObject.h>                                           
#include <maya/MObjectArray.h>                                      
#include <maya/MObjectHandle.h>                                     
#include <maya/MObjectSetMessage.h>                                                                        
//#include <maya/MPlane.h>                                            
#include <maya/MPlug.h>                                             
#include <maya/MPlugArray.h>                                        
#include <maya/MPoint.h>                                            
#include <maya/MPointArray.h>                                       
#include <maya/MPolyMessage.h>                                      
#include <maya/MProgressWindow.h>                                   
#include <maya/MPx3dModelView.h>                                    
#include <maya/MPxBakeEngine.h>                                     
//#include <maya/MPxCacheFormat.h>                                    
#include <maya/MPxCommand.h>                                        
#include <maya/MPxComponentShape.h>                                 
#include <maya/MPxConstraint.h>                                     
#include <maya/MPxConstraintCommand.h>                              
#include <maya/MPxContext.h>                                        
#include <maya/MPxContextCommand.h>                                 
#include <maya/MPxControlCommand.h>                                 
#include <maya/MPxData.h>                                           
#include <maya/MPxDeformerNode.h>                                   
#include <maya/MPxDragAndDropBehavior.h>                            
#include <maya/MPxEmitterNode.h>                                    
#include <maya/MPxFieldNode.h>                                      
#include <maya/MPxFileTranslator.h>                                 
#include <maya/MPxFluidEmitterNode.h>                               
#include <maya/MPxGeometryData.h>                                   
#include <maya/MPxGeometryIterator.h>                               
#include <maya/MPxGlBuffer.h>                                       
#include <maya/MPxHardwareShader.h>                                 
#include <maya/MPxHwShaderNode.h>                                   
#include <maya/MPxIkSolver.h>                                       
#include <maya/MPxIkSolverNode.h>                                   
#include <maya/MPxImageFile.h>                                      
#include <maya/MPxImagePlane.h>                                     
#include <maya/MPxLocatorNode.h>                                    
#include <maya/MPxManipContainer.h>                                 
//#include <maya/MPxManipulatorNode.h>                                
#include <maya/MPxMaterialInformation.h>                            
#include <maya/MPxMayaAsciiFilter.h>                                
#include <maya/MPxMidiInputDevice.h>                                
#include <maya/MPxModelEditorCommand.h>                             
#include <maya/MPxNode.h>                                           
#include <maya/MPxObjectSet.h>                                      
#include <maya/MPxParticleAttributeMapperNode.h>                    
#include <maya/MPxPolyTrg.h>                                        
#include <maya/MPxPolyTweakUVCommand.h>                             
//#include <maya/MPxRenderPassImpl.h>                                 
#include <maya/MPxSelectionContext.h>                               
#include <maya/MPxSpringNode.h>                                     
#include <maya/MPxSurfaceShape.h>                                   
#include <maya/MPxSurfaceShapeUI.h>                                 
#include <maya/MPxToolCommand.h>                                    
#include <maya/MPxTransform.h>                                      
#include <maya/MPxTransformationMatrix.h>                           
#include <maya/MPxUIControl.h>                                      
#include <maya/MPxUITableControl.h>                                 
#include <maya/MQuaternion.h>                                       
#include <maya/MRampAttribute.h>                                    
#include <maya/MRenderCallback.h>                                   
#include <maya/MRenderData.h>                                       
#include <maya/MRenderingInfo.h>                                    
#include <maya/MRenderLine.h>                                       
#include <maya/MRenderLineArray.h>                                  
//#include <maya/MRenderPassDef.h>                                    
//#include <maya/MRenderPassRegistry.h>                               
#include <maya/MRenderProfile.h>                                    
#include <maya/MRenderShadowData.h>                                 
#include <maya/MRenderTarget.h>                                     
#include <maya/MRenderUtil.h>                                       
#include <maya/MRenderView.h>                                       
//#include <maya/MRichSelection.h>                                    
#include <maya/MSceneMessage.h>                                     
#include <maya/MScriptUtil.h>                                       
#include <maya/MSelectInfo.h>                                       
#include <maya/MSelectionList.h>                                    
#include <maya/MSelectionMask.h>                                    
//#include <maya/MSimple.h>                                           
#include <maya/MSpinLock.h>                                         
#include <maya/MStatus.h>                                           
#include <maya/MStreamUtils.h>                                      
#include <maya/MString.h>                                           
#include <maya/MStringArray.h>                                      
#include <maya/MStringResource.h>                                   
#include <maya/MStringResourceId.h>                                 
#include <maya/MSwatchRenderBase.h>                                 
#include <maya/MSwatchRenderRegister.h>                             
#include <maya/MSyntax.h>                                           
//#include <maya/MTemplateCommand.h>                                  
//#include <maya/MTemplateManipulator.h>                              
#include <maya/MTesselationParams.h>                                
#include <maya/MTextureEditorDrawInfo.h>                            
#include <maya/MThreadAsync.h>                                      
#include <maya/MThreadPool.h>                                       
//#include <maya/MThreadUtils.h>                                      
#include <maya/MTime.h>                                             
#include <maya/MTimeArray.h>                                        
#include <maya/MTimer.h>                                            
#include <maya/MTimerMessage.h>                                     
#include <maya/MToolsInfo.h>                                        
#include <maya/MTransformationMatrix.h>                             
#include <maya/MTrimBoundaryArray.h>                                
#include <maya/MTypeId.h>                                           
#include <maya/MTypes.h>                                            
#include <maya/MUiMessage.h>                                        
#include <maya/MUint64Array.h>                                      
#include <maya/MUintArray.h>                                        
#include <maya/MUniformParameter.h>                                 
#include <maya/MUniformParameterList.h>                             
#include <maya/MUserEventMessage.h>                                 
#include <maya/MVaryingParameter.h>                                 
#include <maya/MVaryingParameterList.h>                             
#include <maya/MVector.h>                                           
#include <maya/MVectorArray.h>                                      
#include <maya/MViewportRenderer.h>                                 
//#include <maya/MWeight.h>                                           


#endif//_PREREQUEST_MAYA_H_