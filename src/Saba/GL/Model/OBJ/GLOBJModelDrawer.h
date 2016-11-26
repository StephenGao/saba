#ifndef SABA_GL_MODEL_OBJ_GLOBJMODELDRAWER_H_
#define SABA_GL_MODEL_OBJ_GLOBJMODELDRAWER_H_

#include "../../../Viewer/ModelDrawer.h"

#include <vector>
#include <memory>

#include <glm/mat4x4.hpp>

namespace saba
{
	class GLOBJModel;
	class GLOBJModelDrawContext;

	class GLOBJModelDrawer : public ModelDrawer
	{
	public:
		GLOBJModelDrawer(GLOBJModelDrawContext* ctxt, std::shared_ptr<GLOBJModel> model);
		~GLOBJModelDrawer() override;

		GLOBJModelDrawer(const GLOBJModelDrawer&) = delete;
		GLOBJModelDrawer& operator =(const GLOBJModelDrawer&) = delete;

		bool Create();
		void Destroy();

		virtual void Draw(ViewerContext* ctxt) override;

	private:
		struct MaterialShader
		{
			int					m_objMaterialIndex;
			int					m_objShaderIndex;
			GLVertexArrayObject	m_vao;
		};
	private:
		GLOBJModelDrawContext*		m_drawContext;
		std::shared_ptr<GLOBJModel>	m_objModel;

		std::vector<MaterialShader>	m_materialShaders;

		glm::mat4	m_world;
	};
}

#endif // !SABA_GL_MODEL_OBJ_GLOBJMODELDRAWER_H_

