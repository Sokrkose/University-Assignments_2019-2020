#include <Application.h>
#include <Platform.h>
#include <stdbool.h>

static unsigned char led = false;
static unsigned char blink = true;

static void onPushButtonChangedCbk()
{
  if (Platform_PushButton_getValue() != 0)
  {
    if (blink != 0)
    {
      led = true;
      blink = false;
    }
    else
    {
      if (led != 0)
      {
        led = false;
      }
      else
      {
        blink = true;
      }
    }
    Platform_Led_setValue( led );
  }
}

static void onSystemTick()
{
  static unsigned int i = 0;
  if (blink != 0)
  {
    if (0 == i % 500)
    {
      i = 0;
      led = !led;
      Platform_Led_setValue( led );
    }
    ++i;
  }
  else
  {
    i = 0;
  }
}

void Application_run()
{
  Platform_Led_setValue( led );
  Platform_PushButton_setIsrCallback(onPushButtonChangedCbk);
  Platform_PushButton_enableInterrupt();
  Platform_registerSystickCallback(onSystemTick);
  while( 1 );
}
