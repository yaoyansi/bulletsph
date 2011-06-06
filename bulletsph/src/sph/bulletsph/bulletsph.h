
#ifndef _BULLET_SPH_
#define _BULLET_SPH_

#include "fluids/fluid.h"

namespace BulletSPH
{
	void start(const size_t particleCount,
		const double ominx, const double ominy, const double ominz,
		const double omaxx, const double omaxy, const double omaxz,
		const double iminx, const double iminy, const double iminz,
		const double imaxx, const double imaxy, const double imaxz);
	void simulate(float duration);
	void idle();
	void reshape(int w, int h);
	void display(const double *modelview_);
	void end();
	FluidParticle* getPrticle(const size_t index);
	size_t getPrticleCount();
	void updateObstacleBox(	
		const double minx, const double miny, const double minz,
		const double maxx, const double maxy, const double maxz);

	extern const double ObstacleBox[][6];
	extern const double InitVolumeBox[][6];
	extern int		psys_demo;
}//namespace _BULLET_SPH_


#endif