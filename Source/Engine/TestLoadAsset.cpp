#include "TestLoadAsset.h"

namespace Testing
{
	namespace Loaders
	{
		TestLoadAsset::TestLoadAsset(void)
		{
		}

		TestLoadAsset::~TestLoadAsset(void)
		{
		}

		void TestLoadAsset::run()
		{
			Asset* asset = loadAsset(newString("D:\\Projects\\Games\\Engine2\\Source\\Data\\NWN\\slaad\\Models\\rfoot_g.xml"));
			if(asset != NULL)
			{
				Asset dref = *asset; // slicing: http://stackoverflow.com/questions/3082291/virtual-function-calling-using-dereference-object
				Asset& ref = *asset;
				Asset* copy = asset->clone();

				wprintf(L"Asset: %s\n", asset->getName());
				wprintf(L"Dref: %s\n", dref.getName());
				wprintf(L"ref: %s\n", ref.getName());
				wprintf(L"Copy: %s\n", copy->getName());
			}
		}

		Asset* TestLoadAsset::loadAsset(String& file)
		{
			// Load model file and print out animation data
			String type = newString("model");
			Asset* asset = new Model();
			FILE* myfile;
			char buf[255];
			buf[0] = '\0';

			loaders::LoadAsset::loadAsset(&file, &type, asset);
			if(asset != NULL)
			{
				myfile = fopen("graph.csv", "w");
				if (myfile != NULL)
				{
					fputs("Frame,P(X),P(Y),P(Z),R(X),R(Y),R(Z)\n", myfile);
					fclose(myfile);
				}
				for(int f = 0; f < asset->getAnimtation()->getEndFrame(); f++)
				{
					Matrix* mat = asset->getMatrix(-1);
					//printf("Matrix:\n");
					//mat->printMatrix();
					//Matrix* rMat;
					//printf("Inverse Matrix:\n");
					//rMat = mat->inverse();
					//rMat->printMatrix();
					//printf("Transpose Matrix:\n");
					//rMat = mat->transpose();
					//rMat->printMatrix();

					mat = asset->getMatrix(f);
					KeyFrame* kf = asset->getAnimtation()->getFrame(f);
					Matrix* animMatrix = NULL;
					if(kf != NULL)
						animMatrix = kf->getMatrix();
					if(mat != NULL)
					{
						//mat->printMatrix();
						//printf("p:%f,%f,%f\n", mat->getPosition()->getX(),
						//		mat->getPosition()->getY(),
						//		mat->getPosition()->getZ());
						//printf("r:%f,%f,%f\n", mat->getRotation()->getX() * mat->getRotationAngle(),
						//		mat->getRotation()->getY() * mat->getRotationAngle(),
						//		mat->getRotation()->getZ() * mat->getRotationAngle());
						myfile = fopen("graph.csv", "a");
						if (myfile != NULL)
						{
							String buffer = newString("M,");

							for(int i = 0; i < 16; i++)
							{
								buffer.append(dblToStr(mat->getMatrix()[i]));
								buffer.append(newString(","));
							}
							buffer.append(newString("\n"));
							fputws(buffer.c_str(), myfile);

							//sprintf(buf, "%d,%f,%f,%f,%f,%f,%f\n", f,
							//	mat->getPosition()->getX(),
							//	mat->getPosition()->getY(),
							//	mat->getPosition()->getZ(),
							//	mat->getRotation()->getX() * mat->getRotationAngle(),
							//	mat->getRotation()->getY() * mat->getRotationAngle(),
							//	mat->getRotation()->getZ() * mat->getRotationAngle());
							//fputs(buf, myfile);

							mat = animMatrix;
							if(mat != NULL)
							{
								buffer = newString("A,");
								for(int i = 0; i < 16; i++)
								{
									buffer.append(dblToStr(mat->getMatrix()[i]));
									buffer.append(newString(","));
								}
								buffer.append(newString("\n"));
								fputws(buffer.c_str(), myfile);

								//sprintf(buf, "%d,%f,%f,%f,%f,%f,%f\n", f,
								//	mat->getPosition()->getX(),
								//	mat->getPosition()->getY(),
								//	mat->getPosition()->getZ(),
								//	mat->getRotation()->getX() * mat->getRotationAngle(),
								//	mat->getRotation()->getY() * mat->getRotationAngle(),
								//	mat->getRotation()->getZ() * mat->getRotationAngle());
								//fputs(buf, myfile);
							}
							fclose(myfile);
						}
					}
				}
			}
			return asset;
		}
	}
}