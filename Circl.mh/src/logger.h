#pragma once
#include <memory>
#include <spdlog/logger.h>
#include <spdlog/fmt/ostr.h>

namespace mh {

	class logger {
	public:
		logger() = delete;

		static void init();

		inline static std::shared_ptr<spdlog::logger>& get_logger() { return s_logger; }

	private:
		inline static std::shared_ptr<spdlog::logger> s_logger;
	};

} // namespace mh

#ifdef MH_DEBUG

#define MH_TRACE(...)		::mh::logger::get_logger()->trace(__VA_ARGS__)
#define MH_INFO(...)		::mh::logger::get_logger()->info(__VA_ARGS__)
#define MH_DEBUG(...)		::mh::logger::get_logger()->debug(__VA_ARGS__)
#define MH_WARNING(...)		::mh::logger::get_logger()->warn(__VA_ARGS__)
#define MH_ERROR(...)		::mh::logger::get_logger()->error(__VA_ARGS__); __debugbreak()
#define MH_CRITICAL(...)	::mh::logger::get_logger()->critical(__VA_ARGS__); __debugbreak()

#define MH_ASSERT(x, ...) if(!(x)) { MH_ERROR("Assertion failed: {0}", __VA_ARGS__); }

#else

#define 

#endif // MH_DEBUG