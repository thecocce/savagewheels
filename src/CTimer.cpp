// CTimer.cpp -


#include "main.h"


// define time-counter
#define TICKS SDL_GetTicks()


/////////////////////////////////////////////////////////////////////////////////////////////
//// Name: Start()
//// Desc: inicializira timer
/////////////////////////////////////////////////////////////////////////////////////////////
void CTimer::Start()
{
	m_paused = false;
	m_starttime = TICKS;
}


/////////////////////////////////////////////////////////////////////////////////////////////
//// Name: Pause()
//// Desc: 
/////////////////////////////////////////////////////////////////////////////////////////////
void CTimer::Pause()
{
	m_paused = true;
	m_pausestart = TICKS;
}


/////////////////////////////////////////////////////////////////////////////////////////////
//// Name: Unpause()
//// Desc: 
/////////////////////////////////////////////////////////////////////////////////////////////
void CTimer::Unpause()
{
	m_paused = false;
	m_pausetime += TICKS - m_pausestart;
}


/////////////////////////////////////////////////////////////////////////////////////////////
//// Name: Time()
//// Desc: get current ticks
/////////////////////////////////////////////////////////////////////////////////////////////
int CTimer::Time()
{
	int cur_time = TICKS;
	int result = cur_time - m_pausetime;

	if ( m_paused )
		result -= cur_time - m_pausestart;

	return result - m_starttime;
}


/////////////////////////////////////////////////////////////////////////////////////////////
//// Name: Elapsed()
//// Desc: check if time has elapsed
/////////////////////////////////////////////////////////////////////////////////////////////
bool CTimer::Elapsed( int &time_start, int interval )
{
	int cur_time = Time();

	if ( cur_time > time_start + interval )
	{
		time_start = cur_time;
		return true;
	}
	
	return false;
}
