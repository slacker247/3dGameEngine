#include "Thread.h"

namespace helpers
{
	Thread::Thread(void( __cdecl *func )( void ))
	{
		m_ExeFunc = func;
		m_MutexHandle = NULL;
		m_ThreadHandle = (void*)_beginthread(&(Thread::run), 0, this);
		this->m_ThreadID = GetThreadId(this->m_ThreadHandle);
	}
	
	Thread::Thread(void( __cdecl *func )( void * ), void* classPtr)
	{
		m_ExeFunc = func;
		m_MutexHandle = NULL;
		m_ThreadHandle = (void*)_beginthread(func, 0, classPtr);
		this->m_ThreadID = GetThreadId(this->m_ThreadHandle);
	}

	Thread::~Thread(void)
	{
		int status = -1;
		TerminateThread(this->m_ThreadHandle, status);
	}

	int Thread::setName(String* name)
	{
		int status = -1;
		// http://stackoverflow.com/questions/16486937/name-a-thread-created-by-beginthread-in-c
		return status;
	}

	void __cdecl Thread::run(void * param)
	{
		//*(((Thread)param).m_ExeFunc)();
	}

	/////////////////////////////////////////////////////////
	/// Function: lock
	///
	/// <summary>Locks a resource for this thread to use.</summary>
	///
	/// <returns>returns: 0 for a success. Otherwise the
	/// value will be in the lookup table: <see></see> </returns>
	/////////////////////////////////////////////////////////
	int Thread::lock()
	{
		int status = -1;
		m_MutexHandle = CreateMutex(NULL, false, NULL);
		return status;
	}

	/////////////////////////////////////////////////////////
	/// Function: unlock
	///
	/// <summary>Unlocks a resource that this thread has locked.
	/// </summary>
	///
	/// <returns>returns: 0 for a success. Otherwise the
	/// value will be in the lookup table: <see></see> </returns>
	/////////////////////////////////////////////////////////
	int Thread::unlock()
	{
		int status = -1;
		if(m_MutexHandle != NULL)
			if(ReleaseMutex(m_MutexHandle))
			{
				m_MutexHandle = NULL;
				status = 0;
			}
		return status;
	}
	
	/////////////////////////////////////////////////////////
	/// Function: isAlive
	///
	/// <summary>Tells the caller if the thread is still active
	/// or not.</summary>
	///
	/// <returns>returns: true if the thread is still active
	/// and false if the thread is not active.</returns>
	/////////////////////////////////////////////////////////
	bool Thread::isAlive()
	{
		bool status = true;
		DWORD result = WaitForSingleObject(this->m_ThreadHandle, 10);
		switch(result)
		{
		case WAIT_ABANDONED:
			status = false;
			break;
		case WAIT_OBJECT_0:
			status = false;
			break;
		case WAIT_TIMEOUT:
			break;
		case WAIT_FAILED:
			DWORD err = GetLastError();
			break;
		}
		return status;
	}

	/////////////////////////////////////////////////////////
	/// Function: stop
	///
	/// <summary>Stops the execution of the thread.  This fundtion
	/// will not return until the thread has stopped.</summary>
	///
	/// <returns>returns: 0 for a success. Otherwise the
	/// value will be in the lookup table: <see></see> </returns>
	/////////////////////////////////////////////////////////
	int Thread::stop()
	{
		int status = -1;
		_endthreadex(status);
		return status;
	}

	/////////////////////////////////////////////////////////
	/// Function: suspend
	///
	/// <summary>This will suspend the thread if it is not
	/// suspended.</summary>
	///
	/// <returns>returns: 0 for a success. Otherwise the
	/// value will be in the lookup table: <see></see> </returns>
	/////////////////////////////////////////////////////////
	int Thread::suspend()
	{
		int status = -1;
		SuspendThread(this->m_ThreadHandle);
		return status;
	}

	/////////////////////////////////////////////////////////
	/// Function: resume
	///
	/// <summary>If the thread is suspended, this function will
	/// resume the thread.</summary>
	///
	/// <returns>returns: 0 for a success. Otherwise the
	/// value will be in the lookup table: <see></see> </returns>
	/////////////////////////////////////////////////////////
	int Thread::resume()
	{
		int status = -1;
		while(ResumeThread(this->m_ThreadHandle));
		return status;
	}

	void Thread::sleep(long ms)
	{
		Sleep(ms);
	}
}