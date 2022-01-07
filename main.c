#include "ab_logger.h"

int main(int argc, char *argv[]) {
    ab_logger_init(AB_LOGGER_OUTPUT_TO_STDOUT, ".", "log", 100, 100 * 1024);
    AB_LOGGER_INFO("Startup.\n");
    AB_LOGGER_FATAL("fatal.\n");
    AB_LOGGER_ALERT("alert.\n");
    AB_LOGGER_CRIT("crit.\n");
    AB_LOGGER_ERROR("error.\n");
    AB_LOGGER_WARN("warn.\n");
    AB_LOGGER_NOTICE("notice.\n");
    AB_LOGGER_INFO("info.\n");
    AB_LOGGER_DEBUG("debug.\n");
    AB_LOGGER_TRACE("trace.\n");
    AB_LOGGER_NOTSET("notest.\n");
    AB_LOGGER_UNKNOWN("unknow.\n");
    AB_LOGGER_INFO("Shutdown.\n");
    ab_logger_deinit();
    return 0;
}
