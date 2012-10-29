#ifndef _C_EVENT_IDENTIFY_MARBLES2
  #define _C_EVENT_IDENTIFY_MARBLES2

  #include <event/IIrrOdeEvent.h>
  #include <IrrOdeNet/WorldObserverMessages.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace ode;

  #define _IRR_ODE_IDENTIFY_STRING "IrrOdeReplayFile"

class CEventIdentify : public IIrrOdeEvent {
  protected:
    c8 m_sIdentify[0xFF],m_sAppName[0xFF];

  public:
    CEventIdentify(const c8 *sAppName);
    CEventIdentify(CSerializer *pData);
    CEventIdentify(irr::ode::IIrrOdeEvent *pEvent);

    const c8 *getIdentify();
    const c8 *getAppName();

    s32 getID() { return 0; }
    virtual u16 getType() { return eMessageIdentify; }
    virtual CSerializer *serialize();

    virtual const c8 *toString();

    virtual IIrrOdeEvent *clone() { return new CEventIdentify(this); }
};

#endif
