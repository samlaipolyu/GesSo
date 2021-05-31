#ifndef LeapConnection_h
#define LeapConnection_h

#include "LeapC.h"

/* Client functions */
LEAP_CONNECTION* OpenConnection();
void CloseConnection();
void CloseConnectionHandle(LEAP_CONNECTION* connectionHandle);
LEAP_TRACKING_EVENT* GetFrame(); //Used in polling example
LEAP_DEVICE_INFO* GetDeviceProperties(); //Used in polling example
const char* ResultString(eLeapRS r);

/* State */
extern bool IsConnected;

/* Callback function pointers */
typedef void (*connection_callback)     ();
typedef void (*device_callback)         (const LEAP_DEVICE_INFO* device);
typedef void (*device_lost_callback)    ();
typedef void (*device_failure_callback) (const eLeapDeviceStatus failure_code,
	const LEAP_DEVICE failed_device);
typedef void (*policy_callback)         (const uint32_t current_policies);

struct Callbacks {
	connection_callback      on_connection;
	connection_callback      on_connection_lost;
	device_callback          on_device_found;
	device_lost_callback     on_device_lost;
	device_failure_callback  on_device_failure;
	policy_callback          on_policy;
};
extern struct Callbacks ConnectionCallbacks;
extern void millisleep(int milliseconds);
#endif /* ExampleConnection_h */