#include <windows.h>
#include <process.h>

#include "String.h"

// http://www.codeproject.com/Articles/16134/Calling-a-non-static-member-function-as-a-thread-f
#pragma once
namespace helpers
{
	class Thread
	{
	public:
		Thread(void( __cdecl *func )( void ));
		Thread(void( __cdecl *func )( void * ), void* classPtr);
		~Thread(void);
		
		static void sleep(long ms);
		int setName(String* name);
		int lock();
		int unlock();
		int stop();
		int suspend();
		int resume();
		bool isAlive();
		void* m_ExeFunc;
	protected:
		static void __cdecl run(void * param);

		/////////////////////////////////////////////////////////
		/// Variable: m_ThreadID
		///
		/// <summary>The id to manage this thread.</summary>
		/////////////////////////////////////////////////////////
		int m_ThreadID;
		/////////////////////////////////////////////////////////
		/// Variable: m_ThreadHandle
		///
		/// <summary>The handle to the thread.</summary>
		/////////////////////////////////////////////////////////
		void* m_ThreadHandle;
		void* m_MutexHandle;
	};
}
