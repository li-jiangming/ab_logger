#ifndef AB_LOGGER_H_
#define AB_LOGGER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    AB_LOGGER_PRIORITY_FATAL           = 0,
    AB_LOGGER_PRIORITY_ALERT           = 1,
    AB_LOGGER_PRIORITY_CRIT            = 2,
    AB_LOGGER_PRIORITY_ERROR           = 3,
    AB_LOGGER_PRIORITY_WARN            = 4,
    AB_LOGGER_PRIORITY_NOTICE          = 5,
    AB_LOGGER_PRIORITY_INFO            = 6,
    AB_LOGGER_PRIORITY_DEBUG           = 7,
    AB_LOGGER_PRIORITY_TRACE           = 8,
    AB_LOGGER_PRIORITY_NOTSET          = 9,
    AB_LOGGER_PRIORITY_UNKNOWN         = 10
} ab_logger_priority_e;

typedef enum {
    AB_LOGGER_OUTPUT_TO_STDOUT      = 0,
    AB_LOGGER_OUTPUT_TO_FILE
} ab_logger_output_e;

extern int ab_logger_init(ab_logger_output_e to,
    const char *path, const char *log_prefix,
    unsigned int log_max_nums, unsigned int log_max_size);
extern void ab_logger_message(int priority,
    const char *file, int line, const char *fun,
    const char *fmt, ...);
extern int ab_logger_deinit();

#define AB_LOGGER_FATAL(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_FATAL, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)
#define AB_LOGGER_ALERT(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_ALERT, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)
#define AB_LOGGER_CRIT(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_CRIT, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)
#define AB_LOGGER_ERROR(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_ERROR, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)
#define AB_LOGGER_WARN(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_WARN, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)
#define AB_LOGGER_NOTICE(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_NOTICE, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)
#define AB_LOGGER_INFO(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_INFO, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)
#define AB_LOGGER_DEBUG(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_DEBUG, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)
#define AB_LOGGER_TRACE(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_TRACE, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)
#define AB_LOGGER_NOTSET(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_NOTSET, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)
#define AB_LOGGER_UNKNOWN(fmt, args...) \
    ab_logger_message(AB_LOGGER_PRIORITY_UNKNOWN, __FILE__, __LINE__, __FUNCTION__, fmt, ##args)

#ifdef __cplusplus
}
#endif

#endif // AB_LOGGER_H_
