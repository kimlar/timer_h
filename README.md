# timer_h
![alt text](https://github.com/kimlar/timer_h/blob/main/timer-code-example.png "Showing the code")

<br>

![alt text](https://github.com/kimlar/timer_h/blob/main/timer-running.png "Showing the code in action")

## Examples of using timer.h

### How to use the timer:
```c
#include "timer.h"
...
// Initialize the timer
timer_init();

// Update the timer. Gets the delta time in seconds.
float dt = timer_update();

// Show delta time
printf("dt: %f seconds\n", dt); // OUTPUT: dt: 0.000001 seconds
```

This is a drop-in file for any Windows C projects in order to get delta time in seconds
