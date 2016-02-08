#include "Asset.h"

#include "LoadBMP.h"

#pragma once

namespace assets
{
	class Texture : public Asset
	{
	public:
		// Name
		static unsigned int g_Id ;
	protected:
		unsigned int m_Id;
		int m_Width;
		int m_Height;
		unsigned char* m_Data;
		int m_DataSize;
		// FileName
		String m_FileName;
		// StartTime -- start frame of the player ??? how does that equate...
		int m_StartFrame;
		// PlaybackRate
		float m_PlaybackRate;
		/// EndCondition
		///	end condition values:
		///	0-Loop (Causes the animation to loop over and over again.)
		///	1-Ping Pong (Causes the animation to be played backwards, making every animated sequence "loop smoothly")
		///	2-Hold (Causes the last frame of the animation to be frozen on the surface until the end of the scene.)
		int m_EndCondition;
	public:
		// Default Constructor
		Texture();
		// Copy Constructor
		Texture(const Texture &inTexture);
		virtual Texture& operator=( const Texture& rhs );
	    virtual Texture* clone() const;
		virtual void copy(const Texture &inTexture);
		// Destructor
		~Texture();

		unsigned int getId();
		//int setId(unsigned int id);
		int getWidth();
		int getHeight();
		unsigned char* getData();
		int load();
		String* getFileName();
		int setFileName(String& filename);
		int getStartFrame();
		int setStartFrame(int frame);
		float getPlaybackRate();
		int setPlaybackRate(float rate);
		int getEndCondition();
		int setEndCondition(int condition);
	};
}