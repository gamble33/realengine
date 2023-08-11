#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace realengine {
	class REALENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define REALENGINE_CORE_TRACE(...) ::realengine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define REALENGINE_CORE_INFO(...) ::realengine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define REALENGINE_CORE_WARN(...) ::realengine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define REALENGINE_CORE_ERROR(...) ::realengine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define REALENGINE_CORE_FATAL(...) ::realengine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define REALENGINE_TRACE(...) ::realengine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define REALENGINE_INFO(...) ::realengine::Log::GetClientLogger()->info(__VA_ARGS__)
#define REALENGINE_WARN(...) ::realengine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define REALENGINE_ERROR(...) ::realengine::Log::GetClientLogger()->error(__VA_ARGS__)
#define REALENGINE_FATAL(...) ::realengine::Log::GetClientLogger()->fatal(__VA_ARGS__)

