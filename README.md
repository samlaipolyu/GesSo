## GesSo: A Steerable Soft-Bodied Robot Based on Gesture Control

<hr>

### Preparation

To run the code, ensure that you have:

- A Leap Motion Controller [[Where to buy]](https://www.ultraleap.com/product/leap-motion-controller/)
- [Leap Motion SDK](https://developer.leapmotion.com/sdk-leap-motion-controller/) 
- MATLAB, proabably 2015 or above. I am using the 2020.


### How

Step 1 - Download the all the code in this GesSo repo

Step 2 - Run `main.m`

Step 3 - You will see the panel showing a real-time animation of a soft robot with two segment.

### Customization

- The physical parameters - such as bending stiffness, segment length, etc. - can be cumstomized in the `drawAnimation.m` in the `misc` file. You can make it softer or stiffer, longer or shorter.
- A Matlab interface to show the gesture reading using [matleap](https://github.com/jeffsp/matleap) is written in `drawHandFrame.m` in the misc.


