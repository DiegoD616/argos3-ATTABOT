#include "real_attabot_device.h"

/****************************************/
/****************************************/

char CRealAttabotDevice::m_pchBuffer[100];

/****************************************/
/****************************************/

CRealAttabotDevice::CRealAttabotDevice(knet_dev_t* pt_dspic) :
   m_ptDSPic(pt_dspic) {
}

/****************************************/
/****************************************/
