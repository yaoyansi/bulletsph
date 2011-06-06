#ifndef _PREREQUEST_LOCAL_H_
#define _PREREQUEST_LOCAL_H_

#include "common/typedefine.h"
#include "common/log.h"
#include "common/util.h"
#include "common/PluginManager.h"



#define SAFE_DELETE(p)	\
{					\
	if(p!=NULL){	\
	delete p;	\
	p = NULL;	\
	}				\
}

#endif//_PREREQUEST_LOCAL_H_
