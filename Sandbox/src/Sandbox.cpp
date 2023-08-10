#include <realengine.h>

class Sandbox : public realengine::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

realengine::Application* realengine::CreateApplication() {
	return new Sandbox();
}