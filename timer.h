//
// Timer: Initialize, update
//
// Author:	Kim Einar Larsen
// Email:	kim.developer@gmail.com
// Github:	https://github.com/kimlar
// Copyright (c) 2024 Kim Einar Larsen. All rights reserved.
//
// 
// NOTE: timer_update() returns delta time in seconds.
//
// TODO: Make this also to work with C++.
// 
// Example of using timer.h
//
//		#include "timer.h"
//		...
//		// Initialize the timer
//		timer_init();
//		
//		// Update the timer. Gets the delta time in seconds.
//		float dt = timer_update();
//		
//		// Show delta time
//		printf("dt: %f seconds\n", dt); // OUTPUT: dt: 0.000001 seconds
//
//

#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>

//
// Data types
//
typedef long long			i64;
typedef float				f32;
typedef double				f64;

//
// Prototypes: Timer
//
void timer_init();
f32 timer_update();

//
// Variables
//
i64 startPerfCount;
i64 perfCounterFrequency;
f64 currentTimeInSeconds;

//
// Implementations: Timer
//

// Initialize the timer
void timer_init()
{
	startPerfCount = 0;
	perfCounterFrequency = 0;
	{
		LARGE_INTEGER perfCount;
		QueryPerformanceCounter(&perfCount);
		startPerfCount = perfCount.QuadPart;
		LARGE_INTEGER perfFreq;
		QueryPerformanceFrequency(&perfFreq);
		perfCounterFrequency = perfFreq.QuadPart;
	}
	currentTimeInSeconds = 0.0;
}

// Update the timer. Returns delta time in seconds.
f32 timer_update()
{
	f64 previousTimeInSeconds = currentTimeInSeconds;
	LARGE_INTEGER perfCount;
	QueryPerformanceCounter(&perfCount);

	currentTimeInSeconds = (f64)(perfCount.QuadPart - startPerfCount) / (f64)perfCounterFrequency;

	f32 timer_dt = (f32)(currentTimeInSeconds - previousTimeInSeconds);
	if (timer_dt > (1.f / 60.f))
		timer_dt = (1.f / 60.f);

	return timer_dt;
}