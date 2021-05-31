/// @file matleap.cpp
/// @brief leap motion controller interface
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-09-12

#include "matleap.h"
#include <array>

// Under Windows, a Leap::Controller must be allocated after the MEX
// startup code has completed.  Also, a Leap::Controller must be
// deleted in the function specified by mexAtExit after all global
// destructors are called.  If the Leap::Controller is not allocated
// and freed in this way, the MEX function will crash and cause MATLAB
// to hang or close abruptly.  Linux and OS/X don't have these
// constraints, and you can just create a global Leap::Controller
// instance.

// Global instance pointer
matleap::frame_grabber* fg = 0;
int version = 4; // 1: orig, 2: with arm info, 3: with more hand info

// Exit function
void matleap_exit()
{
	fg->close_connection();
	delete fg;
	fg = 0;
}

/// @brief process interface arguments
///
/// @param nlhs matlab mex output interface
/// @param plhs[] matlab mex output interface
/// @param nrhs matlab mex input interface
/// @param prhs[] matlab mex input interface
///
/// @return command number
int get_command(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
	int command;
	// check inputs
	switch (nrhs)
	{
	case 1:
		command = *mxGetPr(prhs[0]);
		break;
	case 0:
		mexErrMsgTxt("Not enough input arguments");
	default:
		mexErrMsgTxt("Too many input arguments");
	}
	// check that inputs agree with command
	switch (command)
	{
	case -1:
	{
		// set debug command requires 0 outputs
		if (nlhs != 0)
			mexErrMsgTxt("Wrong number of outputs specified");
	}
	break;
	case 0:
	{
		// get version command requires 1 outputs
		if (nlhs != 0 && nlhs != 1)
			mexErrMsgTxt("Wrong number of outputs specified");
	}
	break;
	case 1:
	{
		// frame grab command only requires one input
		if (nrhs > 1)
			mexErrMsgTxt("Too many inputs specified");
		// frame grab command requires exactly one output
		if (nlhs != 0 && nlhs != 1)
			mexErrMsgTxt("Wrong number of outputs specified");
	}
	break;
	default:
		mexErrMsgTxt("An unknown command was specified");
	}
	return command;
}

/// @brief helper function
///
/// @param v values to fill array with
///
/// @return created and filled array
mxArray* create_and_fill(const LEAP_VECTOR& v)
{
	mxArray* p = mxCreateNumericMatrix(1, 3, mxDOUBLE_CLASS, mxREAL);
	*(mxGetPr(p) + 0) = v.x;
	*(mxGetPr(p) + 1) = v.y;
	*(mxGetPr(p) + 2) = v.z;
	return p;
}
/// @brief helper function
///
/// @param v values to fill array with
///
/// @return created and filled array
mxArray* create_and_fill(const LEAP_QUATERNION& v)
{
	mxArray* p = mxCreateNumericMatrix(1, 4, mxDOUBLE_CLASS, mxREAL);
	*(mxGetPr(p) + 0) = v.x;
	*(mxGetPr(p) + 1) = v.y;
	*(mxGetPr(p) + 2) = v.z;
	*(mxGetPr(p) + 3) = v.w;
	return p;
}

/// @brief helper function
///
/// @param m Leap Matrix object to fill array with
///
/// @return created and filled 3x3 array of real doubles
//mxArray *create_and_fill (const LEAP_VECTOR &m)
//{
//    mxArray *p = mxCreateNumericMatrix (3, 3, mxDOUBLE_CLASS, mxREAL);
//
//    const Leap::Vector& x = m.xBasis;
//    const Leap::Vector& y = m.yBasis;
//    const Leap::Vector& z = m.zBasis;
//
//    *(mxGetPr (p) + 0) = x.x;
//    *(mxGetPr (p) + 1) = x.y;
//    *(mxGetPr (p) + 2) = x.z;
//
//    *(mxGetPr (p) + 3) = y.x;
//    *(mxGetPr (p) + 4) = y.y;
//    *(mxGetPr (p) + 5) = y.z;
//
//    *(mxGetPr (p) + 6) = z.x;
//    *(mxGetPr (p) + 7) = z.y;
//    *(mxGetPr (p) + 8) = z.z;
//    return p;
//}
/// @brief get a frame from the leap controller
///
/// @param nlhs matlab mex output interface
/// @param plhs[] matlab mex output interface
void get_frame(int nlhs, mxArray* plhs[])
{
	// get the frame
	const matleap::frame& f = fg->get_frame();
	// create matlab frame struct
	const char* frame_field_names[] =
	{
		"id",
		"timestamp",
		"hands",
		"version"
	};
	int frame_fields = sizeof(frame_field_names) / sizeof(*frame_field_names);
	plhs[0] = mxCreateStructMatrix(1, 1, frame_fields, frame_field_names);
	// fill the frame struct
	mxSetFieldByNumber(plhs[0], 0, 0, mxCreateDoubleScalar(f.id));
	mxSetFieldByNumber(plhs[0], 0, 1, mxCreateDoubleScalar(f.timestamp));

	if (f.detectedHands > 0)
	{
		const char* hand_field_names[] =
		{
			"id", // 0
			"type", // 1
			"confidence", // 2
			"visible_time",
			"pinch_distance",
			"grab_angle",
			"pinch_strength",
			"grab_strength",
			"palm",
			"digits",
			"arm"
		};

		int hand_fields = sizeof(hand_field_names) / sizeof(*hand_field_names);
		mxArray* p = mxCreateStructMatrix(1, f.detectedHands, hand_fields, hand_field_names);
		mxSetFieldByNumber(plhs[0], 0, 2, p);
		// 3 because hands is the third (fourth) field name in
		// the overall struct we are creating.

		for (int i = 0; i < f.detectedHands; ++i)
		{
			// one by one, get the fields for the hand
			mxSetFieldByNumber(p, i, 0, mxCreateDoubleScalar(f.hands[i].id));
			mxSetFieldByNumber(p, i, 1, mxCreateDoubleScalar(f.hands[i].type));
			mxSetFieldByNumber(p, i, 2, mxCreateDoubleScalar(f.hands[i].confidence));
			mxSetFieldByNumber(p, i, 3, mxCreateDoubleScalar(f.hands[i].visible_time));
			mxSetFieldByNumber(p, i, 4, mxCreateDoubleScalar(f.hands[i].pinch_distance));
			mxSetFieldByNumber(p, i, 5, mxCreateDoubleScalar(f.hands[i].grab_angle));
			mxSetFieldByNumber(p, i, 6, mxCreateDoubleScalar(f.hands[i].pinch_strength));
			mxSetFieldByNumber(p, i, 7, mxCreateDoubleScalar(f.hands[i].grab_strength));

			// palm
			const char* palm_field_names[] =
			{
				"position",
				"stabilized_position",
				"velocity",
				"normal",
				"width",
				"direction",
				"oritentation"
			};
			int palm_fields = sizeof(palm_field_names) / sizeof(*palm_field_names);
			mxArray* palm = mxCreateStructMatrix(1, 1, palm_fields, palm_field_names);
			mxSetFieldByNumber(p, i, 8, palm);
			mxSetFieldByNumber(palm, 0, 0, create_and_fill(f.hands[i].palm.position));
			mxSetFieldByNumber(palm, 0, 1, create_and_fill(f.hands[i].palm.stabilized_position));
			mxSetFieldByNumber(palm, 0, 2, create_and_fill(f.hands[i].palm.velocity));
			mxSetFieldByNumber(palm, 0, 3, create_and_fill(f.hands[i].palm.normal));
			mxSetFieldByNumber(palm, 0, 4, mxCreateDoubleScalar(f.hands[i].palm.width));
			mxSetFieldByNumber(palm, 0, 5, create_and_fill(f.hands[i].palm.direction));
			mxSetFieldByNumber(palm, 0, 6, create_and_fill(f.hands[i].palm.orientation));
			// get bones for all fingers
			const char* digit_field_names[] =
			{
				"finger_id", // 0
				"is_extended",
				"bones",
			};
			int digit_fields = sizeof(digit_field_names) / sizeof(*digit_field_names);
			LEAP_DIGIT digits[5];
			std::copy(std::begin(f.hands[i].digits), std::end(f.hands[i].digits), std::begin(digits));
			mxArray* d = mxCreateStructMatrix(1, 5, digit_fields, digit_field_names);
			mxSetFieldByNumber(p, i, 9, d);

			for (int d_it = 0; d_it < 5; d_it++)
			{
				mxSetFieldByNumber(d, d_it, 0, mxCreateDoubleScalar(digits[d_it].finger_id));
				mxSetFieldByNumber(d, d_it, 1, mxCreateDoubleScalar(digits[d_it].is_extended));
				const char* bone_field_names[] =
				{
					"prev_joint",    // 0
					"next_joint",   // 1
					"width",// 2
					"rotation"
				};
				int bone_fields = sizeof(bone_field_names) / sizeof(*bone_field_names);
				mxArray* bones = mxCreateStructMatrix(1, 4, bone_fields, bone_field_names);
				mxSetFieldByNumber(d, d_it, 2, bones);

				LEAP_BONE bone;
				for (int bi = 0; bi < 4; bi++)
				{
					bone = digits[d_it].bones[bi];

					mxSetFieldByNumber(bones, bi, 0, create_and_fill(bone.prev_joint)); // 0
					mxSetFieldByNumber(bones, bi, 1, create_and_fill(bone.next_joint)); // 1
					mxSetFieldByNumber(bones, bi, 2, mxCreateDoubleScalar(bone.width)); // 2
					mxSetFieldByNumber(bones, bi, 3, create_and_fill(bone.rotation));

				}
			}
			// arm
			const char* arm_field_names[] =
			{
					"prev_joint",    // 0
					"next_joint",   // 1
					"width",// 2
					"rotation"
			};
			int arm_fields = sizeof(arm_field_names) / sizeof(*arm_field_names);
			mxArray* arm = mxCreateStructMatrix(1, 1, arm_fields, arm_field_names);
			mxSetFieldByNumber(p, i, 10, arm);
			mxSetFieldByNumber(arm, 0, 0, create_and_fill(f.hands[i].arm.prev_joint));
			mxSetFieldByNumber(arm, 0, 1, create_and_fill(f.hands[i].arm.next_joint));
			mxSetFieldByNumber(arm, 0, 2, mxCreateDoubleScalar(f.hands[i].arm.width));
			mxSetFieldByNumber(arm, 0, 3, create_and_fill(f.hands[i].arm.rotation));
		} // re: for f.hands.count()
	} // re: if f.hands.count() > 0

	mxSetFieldByNumber(plhs[0], 0, 4, mxCreateDoubleScalar(version));
}

void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
	if (!fg)
	{
		fg = new matleap::frame_grabber;
		if (fg == 0)
			mexErrMsgTxt("Cannot allocate a frame grabber");
		fg->open_connection();
		mexAtExit(matleap_exit);
	}
	switch (get_command(nlhs, plhs, nrhs, prhs))
	{
		// turn on debug
	case -1:
		fg->set_debug(true);
		return;
		// get version
	case 0:
		plhs[0] = mxCreateNumericMatrix(1, 2, mxDOUBLE_CLASS, mxREAL);
		*(mxGetPr(plhs[0]) + 0) = MAJOR_REVISION;
		*(mxGetPr(plhs[0]) + 1) = MINOR_REVISION;
		return;
		// get frame
	case 1:
		get_frame(nlhs, plhs);
		return;
	default:
		// this is a logic error
		mexErrMsgTxt("unknown error: please contact developer");
	}
}
