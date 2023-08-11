#pragma once

#ifdef REALENGINE_PLATFORM_WINDOWS

extern realengine::Application* realengine::CreateApplication();

int main(int argc, char** argv) {
	realengine::Log::Init();
	REALENGINE_CORE_WARN("Initialized Logger!");
	REALENGINE_INFO("Hello World!");
	auto app = realengine::CreateApplication();
	app->Run();
	delete app;
}

#endif
