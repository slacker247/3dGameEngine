#include "OpenGLRender.h"

namespace renderers
{
	String OpenGLRender::STR_TARGET = newString(".Target");
	String OpenGLRender::STR_TARGET_DIRECT = newString("#targetDirect");

	// Default Constructor
	OpenGLRender::OpenGLRender()
	{
		m_FOV = 45.0f;
		m_NearClip = 0.0f;
		m_FarClip = 10000.0f;
		m_AspectRatio = 4.0f/3.0f;
	}

	OpenGLRender::OpenGLRender(String& settingsFile)
	{
	}

	// Copy Constructor
	OpenGLRender::OpenGLRender(const OpenGLRender &inRender)
	{
		copy(inRender);
	}

	OpenGLRender& OpenGLRender::operator=( const OpenGLRender& rhs )
	{
		copy(rhs);
		return *this;
	}

	OpenGLRender* OpenGLRender::clone() const
	{
		return new OpenGLRender(*this);
	}

	void OpenGLRender::copy(const OpenGLRender &inOpenGLRender)
	{
	}

	// Destructor
	OpenGLRender::~OpenGLRender()
	{
	}

	int OpenGLRender::init()
	{
		int status = -1;
		// OpenGL Settings
		glShadeModel(GL_SMOOTH);						// Enable Smooth Shading
		glClearColor(0.5f, 0.5f, 0.5f, 0.5f);					// Black Background
		glClearDepth(1.0f);							// Depth Buffer Setup
		glEnable(GL_LIGHTING);
		//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
        glEnable( GL_NORMALIZE );
		glEnable(GL_DEPTH_TEST);						// Enables Depth Testing
		//Disable color materials, so that glMaterial calls work
		glDisable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);						// Enable Texture Mapping ( NEW )
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			// Really Nice Perspective Calculations
		glDepthFunc(GL_LEQUAL);							// The Type Of Depth Testing To Do

		glLoadIdentity();							// Reset The Current Matrix

		return status;
	}

	int OpenGLRender::reSize(double cx, double cy)
	{
		int status = -1;
	
		if ( cx > 0 && cy > 0 )
		{
			setupViewport( cx, cy );

			// compute the aspect ratio
			// this will keep all dimension scales equal
			m_AspectRatio = cx/cy;
			setupViewingFrustum();
		}
		return status;
	}

	int OpenGLRender::applyMatrix(Matrix* matrix)
	{
		int status = -1;
		// NOTE: rotation is Z,Y,X
		glMultMatrixf(matrix->getMatrix());
		//glTranslatef(matrix->getPosition()->getX(),
		//			 matrix->getPosition()->getY(),
		//			 matrix->getPosition()->getZ());
		//glRotatef(matrix->getRotation()->getZ(), 0, 0, 1);
		//glRotatef(matrix->getRotation()->getY(), 0, 1, 0);
		//glRotatef(matrix->getRotation()->getX(), 1, 0, 0);
		//glScalef(matrix->getScale()->getX(),
		//	matrix->getScale()->getY(),
		//	matrix->getScale()->getZ());
		return status;
	}

	int OpenGLRender::setupViewport( int cx, int cy )
	{
		// This also controls the resolution at which we render at
		// select the full client area
		glViewport(0, 0, cx, cy);

		return TRUE;
	}

	int OpenGLRender::setupViewingFrustum()
	{
		int status = -1;
		// select a default viewing volumn
		// select the projection matrix and clear it
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();

		// select the viewing volumn
		gluPerspective( m_FOV, m_AspectRatio, m_NearClip, m_FarClip );

		// switch back to the modelview matrix
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
		return status;
	}

	int OpenGLRender::setupViewingTransform(Camera* camera, Camera* target)
	{
		int status = -1;
		// select a default viewing transformation
		
		/*  Typically in OpenGL, projections are set up in such a way that the camera
		-Z axis is mapped to the front direction in the projection matrix. Therefore,
		pass in the fourth row as (eyeX, eyeY, eyeZ), then 'fourth row - third row'
		as the (centerX, centerY, centerZ), and second row as (upX, upY, upZ). The
		first row is not needed, but assert that the first, second and third row together
		form an orthonormal right-handed basis to catch any handedness flip issues, or
		otherwise bad input.
		*/
		bool test = false;
		if(!test && camera != NULL && target != NULL)
		{
			Matrix* matrix = camera->getMatrix(-1);
			Matrix* TGmatrix = target->getMatrix(-1);
			gluLookAt(matrix->getPosition()->getX(),
					  matrix->getPosition()->getY(),
					  matrix->getPosition()->getZ(), //camera position 
					  TGmatrix->getPosition()->getX(),
					  TGmatrix->getPosition()->getY(),
					  TGmatrix->getPosition()->getZ(), //direction to look (target position)
					  matrix->getPosition()->getX(),
					  matrix->getPosition()->getY(),
					  matrix->getPosition()->getZ() * 10.0f);//camera rotation (up vector?)
		}
		else if(!test && camera != NULL)
		{
			//glMultMatrixf(camera->getMatrix()->getMatrix());
			//glTranslatef(camera->getMatrix()->getPosition()->getX(),
			//			 camera->getMatrix()->getPosition()->getY(),
			//			 camera->getMatrix()->getPosition()->getZ());
			//glRotatef(matrix->getRotation()->getZ(), 0, 0, 1);
			//glRotatef(matrix->getRotation()->getY(), 0, 1, 0);
			//glRotatef(matrix->getRotation()->getX(), 1, 0, 0);
		}
		else
		{
			int distance = -600;
			//static int rotate = 0;
			//rotate++;
			//if (rotate > 360)
			//	rotate = 0;
			//glRotatef(rotate, 0, 0, 1);
			switch(0)
			{
			case 0: // TOP
				glTranslatef(0, 0, distance);
				break;
			case 1: // FRONT
				glTranslatef(0, 0, distance);
				glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
				break;
			case 2: // LEFT
				glTranslatef(0, 0, distance);
				glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
				glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
				break;
			}
		}

		return status;
	}

	int OpenGLRender::draw(BaseState* state)
	{
		static float angle = 0;
		int status = -1;
		bool once = true;
		Camera* cam = NULL;
		Camera* camTarget = NULL;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Clear The Screen And The Depth Buffer
	    glLoadIdentity();                       // Reset The View

		String camera = state->getCamera();

		glPushMatrix();
		for (map<String, Scene>::iterator itScene = state->getScenes()->begin();
			itScene != state->getScenes()->end();
			++itScene)
		{
			Scene* scene = &(itScene->second);

			cam = (Camera*)scene->getAsset(camera);
			if(cam != NULL && once)
			{
				// Should happen during the loading of the xml
				if(cam->getType() == 0)
				{
					String targetCam = camera.append(STR_TARGET);
					camTarget = (Camera*)scene->getAsset(targetCam);
				}
				m_FOV = cam->getFOV();
				m_NearClip = cam->getNearClip();
				m_FarClip = cam->getFarClip();
				once = false;
			}
			setupViewingFrustum();

			setupViewingTransform(cam, camTarget);

			map<String, Asset*>* assets = scene->getAssets();
			for (map<String, Asset*>::iterator itAsset = assets->begin();
				itAsset != assets->end();
				++itAsset)
			{
				glPushMatrix();
				Asset* asset = itAsset->second;

				// TODO : Needs to support nested groups???
				// if belongs to group
				if(asset->getGroupName()->length() > 0)
				{
					String grp = *(asset->getGroupName());
					Asset* group = scene->getAsset(grp);
					if(group != NULL)
					{
						// apply the group matrix
						Matrix* matrix = group->getMatrix(frame);
						//applyMatrix(matrix);
					}
				}

				// Model
				if(asset->getType() == Asset::MODEL)
				{
					bool txtEnabled = false;
					glPushMatrix();
					Model* model = (Model*)asset;
					
					Matrix* matrix = model->getMatrix(frame);
					applyMatrix(matrix);

					String matName = *(model->getMaterialName());
					Material* mat = (Material*)scene->getAsset(matName);
					if(mat != NULL)
					{
						GLenum twoSided = GL_FRONT;
						if(mat->isTwoSided())
							twoSided = GL_FRONT_AND_BACK;

						float color[4];
						
						glMaterialfv(twoSided, GL_AMBIENT, mat->getAmbientColor());
						glMaterialfv(twoSided, GL_DIFFUSE, mat->getDiffuseColor());
						glMaterialf(twoSided, GL_SHININESS, mat->getGlossiness());

						color[0] = mat->getSpecularColor()[0] * mat->getSpecularLevel();
						color[1] = mat->getSpecularColor()[1] * mat->getSpecularLevel();
						color[2] = mat->getSpecularColor()[2] * mat->getSpecularLevel();
						color[3] = mat->getSpecularColor()[3];
						glMaterialfv(twoSided, GL_SPECULAR, color);
						// Emissive = Self Illum
						color[0] = mat->getSelfIllumColor()[0] * mat->getSelfIllumAmount();
						color[1] = mat->getSelfIllumColor()[1] * mat->getSelfIllumAmount();
						color[2] = mat->getSelfIllumColor()[2] * mat->getSelfIllumAmount();
						color[3] = mat->getSelfIllumColor()[3];
						glMaterialfv(twoSided, GL_EMISSION, color);

						String dMap = *(mat->getDiffuseMap());
						Texture* txt = (Texture*)scene->getAsset(dMap);
						if(txt != NULL)
						{
							// TODO : glGenTexture with delete, use on switching states
							glBindTexture(GL_TEXTURE_2D, txt->getId());

							if(txt->getData() == NULL)
							{
								txt->load();
								//glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
								//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
								//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
								glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
								glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
								//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, mat->texture1_map.flags);

								glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
									txt->getWidth(),
									txt->getHeight(),
									0, GL_RGB, GL_UNSIGNED_BYTE,
									txt->getData());
							}
							glEnable(GL_TEXTURE_2D);
							txtEnabled = true;
						}
					}

					list<Mesh>* meshes = model->getMeshes();
					for (list<Mesh>::iterator itMesh = meshes->begin();
						itMesh != meshes->end();
						++itMesh)
					{
						list<assets::Polygon>* polys = itMesh->getPolys();
						for (list<assets::Polygon>::iterator itPoly = polys->begin();
							itPoly != polys->end();
							++itPoly)
						{
							glBegin(GL_TRIANGLES);

							list<assets::Vertex>* verts = itPoly->getVertices();
							int indecies[] = {0,1,2};
							for (int i = 0;
								i < verts->size();
								i++)
							{

								int index = indecies[i];
								list<assets::Vertex>::iterator itVert = verts->begin();
								std::advance(itVert, index);
								glNormal3fv(itVert->getNormal()->getPos());
								Point* ptText = itVert->getTextCoord();
								glTexCoord3fv(ptText->getPos());

								Point* pt = itVert->getPosition();
								glVertex3fv(pt->getPos());
							}
							glEnd();
						}
					}
					if(txtEnabled)
					{
						glDisable(GL_TEXTURE_2D);
					}
					glPopMatrix();
				}
				int find = asset->getName()->find(STR_TARGET);
				// Light
				if(asset->getType() == Asset::LIGHT &&
				   find <= 0)
				{
					glPushMatrix();
					Light* light = (Light*)asset;
					Matrix* matrix = light->getMatrix(frame);
					
					//glMaterialfv(GL_FRONT, GL_SHININESS, &(light->getSoftenDiffuseEdge()));
					
					if(light->isAffectDiffuse())
						glLightfv(light->getId(GL_LIGHT0), GL_DIFFUSE, light->getColor());
					if(light->isAffectSpecular())
						glLightfv(light->getId(GL_LIGHT0), GL_SPECULAR, light->getColor());

					if(light->isAmbientOnly())
						glLightfv(light->getId(GL_LIGHT0), GL_AMBIENT, light->getColor());
					else
					{
						float pos[4];
						pos[0] = matrix->getPosition()->getPos()[0];
						pos[1] = matrix->getPosition()->getPos()[1];
						pos[2] = matrix->getPosition()->getPos()[2];
						pos[3] = 1;

						glLightfv(light->getId(GL_LIGHT0), GL_POSITION, pos);
						
						String targetLight = light->getName()->append(STR_TARGET);
						Light* lightTarget = (Light*)scene->getAsset(targetLight);
						if(cmpStrI(*(light->getLightType()), STR_TARGET_DIRECT) == 0 &&
						   lightTarget != NULL)
						{
							Matrix* TGmatrix = lightTarget->getMatrix(-1);
							// Defining spotlight attributes
							// cutoff is the angle from center to stop from
							glLightf(light->getId(GL_LIGHT0), GL_SPOT_CUTOFF, light->getDecayRadius());
							glLightf(light->getId(GL_LIGHT0), GL_SPOT_EXPONENT, light->getFarAttenEnd());
							glLightfv(light->getId(GL_LIGHT0), GL_SPOT_DIRECTION, TGmatrix->getPosition()->getPos());
						}
						if(light->useFarAtten())
						{
							// http://tomdalling.com/blog/modern-opengl/07-more-lighting-ambient-specular-attenuation-gamma/
							//GL_CONSTANT_ATTENUATION
							//GL_LINEAR_ATTENUATION
							//GL_QUADRATIC_ATTENUATION
							glLightf(light->getId(GL_LIGHT0), GL_LINEAR_ATTENUATION, light->getAttenDecay());
						}
					}

					if(light->isEnabled())
						glEnable(light->getId(GL_LIGHT0));
					else
						glDisable(light->getId(GL_LIGHT0));
					glPopMatrix();
				}
				glPopMatrix();
			}
			// For viewing Transform
			glPopMatrix();
		}

		glPopMatrix();
		
		return status;
	}
}