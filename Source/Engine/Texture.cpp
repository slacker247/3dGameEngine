#include "Texture.h"

namespace assets
{
	unsigned int Texture::g_Id = 0;

	Texture::Texture()
	{
		Texture::g_Id++;
		this->m_Id = Texture::g_Id;
		this->m_Width = 0;
		this->m_Height = 0;
		this->m_Data = NULL;
		this->m_DataSize = 0;
		this->m_FileName = newString("");
		this->m_StartFrame = 0;
		this->m_PlaybackRate = 1;
		this->m_EndCondition = 0;

		this->m_Type = Asset::TEXTURE;
	}

	// Copy Constructor
	Texture::Texture(const Texture &inTexture)
		: Asset(inTexture)
	{
		copy(inTexture);
	}

	Texture& Texture::operator=( const Texture& rhs )
	{
		Asset::operator=(rhs);
		copy(rhs);
		return *this;
	}

	Texture* Texture::clone() const
	{
		return new Texture(*this);
	}

	void Texture::copy(const Texture &inTexture)
	{
		this->m_Id = inTexture.m_Id;
		this->m_Width = inTexture.m_Width;
		this->m_Height = inTexture.m_Height;
		this->m_DataSize = inTexture.m_DataSize;
		
		if(this->m_Data != NULL && this->m_DataSize > 0)
			delete m_Data;
		this->m_Data = new unsigned char[this->m_DataSize];
		for(int i = 0; i < this->m_DataSize; i++)
			this->m_Data[i] = inTexture.m_Data[i];

		this->m_FileName = inTexture.m_FileName;
		this->m_StartFrame = inTexture.m_StartFrame;
		this->m_PlaybackRate = inTexture.m_PlaybackRate;
		this->m_EndCondition = inTexture.m_EndCondition;
	}

	// Destructor
	Texture::~Texture()
	{
		if(this->m_Data != NULL)
			delete this->m_Data;
	}
	
	unsigned int Texture::getId()
	{
		return this->m_Id;
	}

	int Texture::getWidth()
	{
		return this->m_Width;
	}

	int Texture::getHeight()
	{
		return this->m_Height;
	}

	unsigned char* Texture::getData()
	{
		return this->m_Data;
	}

	int Texture::load()
	{
		int status = -1;
		this->m_Data = loaders::LoadBMP::loadBMP(this->m_FileName);
		if(this->m_Data != NULL)
		{
			this->m_Width = loaders::LoadBMP::width;
			this->m_Height = loaders::LoadBMP::height;
			status = 0;
		}
		return status;
	}

	//int Texture::setId(unsigned int id)
	//{
	//	int status = -1;
	//	this->m_Id = id;
	//	return status;
	//}

	String* Texture::getFileName()
	{
		return &(this->m_FileName);
	}

	int Texture::setFileName(String& filename)
	{
		int status = -1;
		this->m_FileName = filename;
		return status;
	}

	int Texture::getStartFrame()
	{
		return this->m_StartFrame;
	}

	int Texture::setStartFrame(int frame)
	{
		int status = -1;
		this->m_StartFrame = frame;
		return status;
	}

	float Texture::getPlaybackRate()
	{
		return this->m_PlaybackRate;
	}

	int Texture::setPlaybackRate(float rate)
	{
		int status = -1;
		this->m_PlaybackRate = rate;
		return status;
	}

	int Texture::getEndCondition()
	{
		return this->m_EndCondition;
	}

	int Texture::setEndCondition(int condition)
	{
		int status = -1;
		this->m_EndCondition = condition;
		return status;
	}
}