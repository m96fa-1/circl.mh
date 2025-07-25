#include "logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace mh {

	void logger::init() {
		auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		sink->set_level(spdlog::level::trace);
		sink->set_pattern("%^[%T] %n: %v%$");

		s_logger = std::make_shared<spdlog::logger>("circl.mh", sink);
	}

} // namespace mh