/// @file matleap.h
/// @brief leap motion controller interface
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-09-12

#ifndef MATLEAP_H
#define MATLEAP_H

#define MAJOR_REVISION 4
#define MINOR_REVISION 0

#include "LeapC.h"
#include "mex.h"
#include "LeapConnection.h"

namespace matleap
{

/// @brief a leap frame
struct frame
{
    int64_t id;
    int64_t timestamp;
	uint32_t detectedHands;
    LEAP_HAND* hands;
};

/// @brief leap frame grabber interface
class frame_grabber
{
    private:
    bool debug;
	LEAP_CONNECTION* controllerConnection;
    frame current_frame;
    public:
    /// @brief constructor
    frame_grabber ()
        : debug (false)
    {
    }
	void open_connection()
	{
		controllerConnection = OpenConnection();
		while (!IsConnected)
			millisleep(100); //wait a bit to let the connection complete
		LeapSetPolicyFlags(*controllerConnection, eLeapPolicyFlag_BackgroundFrames, 0);
	}
	void close_connection()
	{
		CloseConnectionHandle(controllerConnection);
		while (IsConnected)
			millisleep(100); //wait a bit to let the connection complete
	}
    /// @brief destructor
    ~frame_grabber ()
    {
        if (debug)
            mexPrintf ("Closing matleap frame grabber\n");
    }
    /// @brief debug member access
    ///
    /// @param flag turn it on/off
    void set_debug (bool flag)
    {
        if (flag == debug)
            return;
        if (flag)
            mexPrintf ("Setting debug on\n");
        debug = flag;
    }
    /// @brief get a frame from the controller
    ///
    /// @return the frame
    const frame &get_frame ()
    {
		LEAP_TRACKING_EVENT* frame = GetFrame();
		current_frame.id = frame->tracking_frame_id;
        if (debug)
            mexPrintf ("Got frame with id %d\n", current_frame.id);
		current_frame.timestamp = frame->info.timestamp;
		current_frame.detectedHands = frame->nHands;
		current_frame.hands = frame->pHands;
        return current_frame;
    }
};

} // namespace matleap

#endif
