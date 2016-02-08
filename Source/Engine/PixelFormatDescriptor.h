	///* pixel types */
	//#define PFD_TYPE_RGBA        0
	//#define PFD_TYPE_COLORINDEX  1

	///* layer types */
	//#define PFD_MAIN_PLANE       0
	//#define PFD_OVERLAY_PLANE    1
	//#define PFD_UNDERLAY_PLANE   (-1)

	///* PIXELFORMATDESCRIPTOR flags */
	//#define PFD_DOUBLEBUFFER            0x00000001
	//#define PFD_STEREO                  0x00000002
	//#define PFD_DRAW_TO_WINDOW          0x00000004
	//#define PFD_DRAW_TO_BITMAP          0x00000008
	//#define PFD_SUPPORT_GDI             0x00000010
	//#define PFD_SUPPORT_OPENGL          0x00000020
	//#define PFD_GENERIC_FORMAT          0x00000040
	//#define PFD_NEED_PALETTE            0x00000080
	//#define PFD_NEED_SYSTEM_PALETTE     0x00000100
	//#define PFD_SWAP_EXCHANGE           0x00000200
	//#define PFD_SWAP_COPY               0x00000400
	//#define PFD_SWAP_LAYER_BUFFERS      0x00000800
	//#define PFD_GENERIC_ACCELERATED     0x00001000
	//#define PFD_SUPPORT_DIRECTDRAW      0x00002000
	//#define PFD_DIRECT3D_ACCELERATED    0x00004000
	//#define PFD_SUPPORT_COMPOSITION     0x00008000

	///* PIXELFORMATDESCRIPTOR flags for use in ChoosePixelFormat only */
	//#define PFD_DEPTH_DONTCARE          0x20000000
	//#define PFD_DOUBLEBUFFER_DONTCARE   0x40000000
	//#define PFD_STEREO_DONTCARE         0x80000000

	///* Pixel format descriptor */
	//typedef struct tagPIXELFORMATDESCRIPTOR
	//{
	//	unsigned short nSize;				// size of this pfd
	//	unsigned short nVersion;			// version number
	//	unsigned long dwFlags;				/*	  Default values:
	//										 *	  PFD_DRAW_TO_WINDOW |          // support window
	//										 *	  PFD_SUPPORT_OPENGL |          // support OpenGL
	//										 *	  PFD_DOUBLEBUFFER,             // double buffered
	//										 */
	//	unsigned char iPixelType;			// RGBA type
	//	unsigned char cColorBits;			// 24-bit color depth
	//	unsigned char cRedBits;				// color bits ignored
	//	unsigned char cRedShift;			// color bits ignored
	//	unsigned char cGreenBits;			// color bits ignored
	//	unsigned char cGreenShift;			// color bits ignored
	//	unsigned char cBlueBits;			// color bits ignored
	//	unsigned char cBlueShift;			// color bits ignored
	//	unsigned char cAlphaBits;			// color bits ignored
	//	unsigned char cAlphaShift;			// color bits ignored
	//	unsigned char cAccumBits;			// no accumulation buffer
	//	unsigned char cAccumRedBits;		// accum bits ignored
	//	unsigned char cAccumGreenBits;		// accum bits ignored
	//	unsigned char cAccumBlueBits;		// accum bits ignored
	//	unsigned char cAccumAlphaBits;		// accum bits ignored
	//	unsigned char cDepthBits;			// NOTE: better performance with 16-bit z-buffer
	//	unsigned char cStencilBits;			// no stencil buffer
	//	unsigned char cAuxBuffers;			// no auxiliary buffer
	//	unsigned char iLayerType;			// main layer
	//	unsigned char bReserved;			// reserved
	//	unsigned long dwLayerMask;			// layer masks ignored
	//	unsigned long dwVisibleMask;		// layer masks ignored
	//	unsigned long dwDamageMask;			// layer masks ignored
	//} PIXELFORMATDESCRIPTOR, *PPIXELFORMATDESCRIPTOR, FAR *LPPIXELFORMATDESCRIPTOR;
