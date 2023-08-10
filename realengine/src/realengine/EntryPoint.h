#pragma once

#ifdef REALENGINE_PLATFORM_WINDOWS

extern realengine::Application* realengine::CreateApplication();

int main(int argc, char** argv) {
	printf("realengine started!");
	auto app = realengine::CreateApplication();
	app->Run();
	delete app;
}

#endif
