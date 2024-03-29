#ifndef __LAB_WORK_4_HPP__
#define __LAB_WORK_4_HPP__

#include "GL/gl3w.h"
#include "common/base_lab_work.hpp"
#include "common/camera.hpp"
#include "common/models/triangle_mesh_model.hpp"
#include "define.hpp"
#include <map>
#include <vector>

namespace M3D_ISICG
{
	class LabWork4 : public BaseLabWork
	{
	  public:
		LabWork4() : BaseLabWork() {}
		~LabWork4();

		bool init() override;
		void animate( const float p_deltaTime ) override;
		void render() override;

		void handleEvents( const SDL_Event & p_event ) override;
		void displayUI() override;

		void resize( const int p_width, const int p_height ) override;
		int	 _valueDisplay = 0;
	  private:
		bool _initProgram();
		void _initCamera();

	  private:
		// ================ Scene data.
		TriangleMeshModel _bunny;
		Camera			  _camera;
		// ================

		// ================ GL data.
		GLuint _program			 = GL_INVALID_INDEX;
		GLint  _uMVPMatrixLoc	 = GL_INVALID_INDEX;
		GLint  _uMVMatrixLoc	 = GL_INVALID_INDEX;
		GLint  _uNormalMatrixLoc = GL_INVALID_INDEX;
		GLint  _uPosCameraLoc	 = GL_INVALID_INDEX;
		// ================

		// ================ Settings.
		Vec4f _bgColor = Vec4f( 0.8f, 0.8f, 0.8f, 1.f ); // Background color
		// Camera
		float _cameraSpeed		 = 0.1f;
		float _cameraSensitivity = 0.1f;
		float _fovy				 = 60.f;
		// ================ MVPmatrix

		Mat4f MVPMatrix;
		Mat4f MVMatrix;
		Mat4f NormalMatrix;

		static const std::string _shaderFolder;
	};
} // namespace M3D_ISICG

#endif // __LAB_WORK_4_HPP__
