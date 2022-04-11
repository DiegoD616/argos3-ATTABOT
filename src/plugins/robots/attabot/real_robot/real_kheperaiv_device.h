#ifndef REAL_ATTABOT_DEVICE_H
#define REAL_ATTABOT_DEVICE_H

#include <argos3/core/utility/datatypes/datatypes.h>
#include <attabot/attabot.h>

using namespace argos;

class CRealAttabotDevice {

public:

   CRealAttabotDevice(knet_dev_t* pt_dspic);
   virtual ~CRealAttabotDevice() {}

   virtual void Do(Real f_elapsed_time) = 0;

   inline knet_dev_t* GetDSPic() const {
      return m_ptDSPic;
   }

   inline char* GetBuffer() {
      return m_pchBuffer;
   }

private:

   knet_dev_t* m_ptDSPic;
   static char m_pchBuffer[100];
   
};

#endif // REAL_ATTABOT_DEVICE_H
