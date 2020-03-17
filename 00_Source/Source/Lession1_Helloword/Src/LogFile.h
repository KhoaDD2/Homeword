#ifndef SECURE_WRAPPER_LOGFILE_H
#define SECURE_WRAPPER_LOGFILE_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "UserConfig.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LOGD(xx_fmt,...) if(DEBUG) printf("[D]" xx_fmt,##__VA_ARGS__)
#define LOGI(xx_fmt,...) printf("[I]" xx_fmt "\r\n",##__VA_ARGS__)
#define LOGW(xx_fmt,...) printf("[W]" xx_fmt "\r\n",##__VA_ARGS__)
#define LOGE(xx_fmt,...) printf("[E]" xx_fmt "\r\n",##__VA_ARGS__)
#define LOGF(xx_fmt,...) printf("[F]" xx_fmt "\r\n",##__VA_ARGS__)

#define ENABLE_LOG_MSG_LOW               1
#define ENABLE_LOG_MSG_MED               1
#define ENABLE_LOG_MSG_HIGH              1
#define ENABLE_LOG_MSG_ERROR             1
#define ENABLE_LOG_MSG_FATAL             1
#define ENABLE_LOG_MSG_DEBUG             1 

#define LOG_MSG_LOW                      (0)
#define LOG_MSG_MED                      (1)
#define LOG_MSG_HIGH                     (2)
#define LOG_MSG_ERROR                    (3)
#define LOG_MSG_FATAL                    (4)
#define LOG_MSG_DEBUG                    (5)

#define LOG_INFO  LOG_LOW

#define LOG_DEBUG(xx_fmt, ...) \
  APPS_LOG(LOG_MSG_DEBUG, xx_fmt, ##__VA_ARGS__)

#define LOG_LOW(xx_fmt, ...) \
  APPS_LOG(LOG_MSG_LOW, xx_fmt, ##__VA_ARGS__)

#define LOG_MED(xx_fmt, ...) \
  APPS_LOG(LOG_MSG_MED, xx_fmt, ##__VA_ARGS__)

#define LOG_HIGH(xx_fmt, ...) \
  APPS_LOG(LOG_MSG_HIGH, xx_fmt, ##__VA_ARGS__)

#define LOG_ERROR(xx_fmt, ...) \
  APPS_LOG(LOG_MSG_ERROR, xx_fmt, ##__VA_ARGS__)

#define LOG_FATAL(xx_fmt, ...) \
  APPS_LOG(LOG_MSG_FATAL, xx_fmt, ##__VA_ARGS__)

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#undef APPS_LOG
#define APPS_LOG(xx_prio, xx_fmt, ...) \
  APPS_RAW(xx_prio, xx_fmt , ##__VA_ARGS__)

#ifdef LOG_ON
    #ifdef APPS_RAW
    #undef APPS_RAW
    #endif
    #define APPS_RAW(xx_prio, xx_fmt, ...) \
    do { \
        if((xx_prio == LOG_MSG_LOW) && (ENABLE_LOG_MSG_LOW)) { \
                LOGI(xx_fmt , ##__VA_ARGS__);} \
            else if((xx_prio == LOG_MSG_MED) && (ENABLE_LOG_MSG_MED)){ \
                LOGW(xx_fmt , ##__VA_ARGS__);} \
            else if((xx_prio == LOG_MSG_HIGH) && (ENABLE_LOG_MSG_HIGH)){ \
                LOGW(xx_fmt , ##__VA_ARGS__);} \
            else if((xx_prio == LOG_MSG_ERROR) && (ENABLE_LOG_MSG_ERROR)){ \
                LOGE(xx_fmt , ##__VA_ARGS__);} \
            else if((xx_prio == LOG_MSG_FATAL) && (ENABLE_LOG_MSG_FATAL)){ \
                LOGF(xx_fmt , ##__VA_ARGS__);} \
            else if((xx_prio == LOG_MSG_DEBUG) && (ENABLE_LOG_MSG_DEBUG)){ \
                LOGD(xx_fmt , ##__VA_ARGS__);} \
        } while (0)
#else
    #define APPS_RAW(xx_prio, xx_fmt, ...)
#endif // LOG_ON

#ifdef __cplusplus
}
#endif

#endif
