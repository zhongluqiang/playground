#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/PatternLayout.hh>

// 日志器

// 获取root日志器，root日志器名称默认为空
log4cpp::Category &root_logger = log4cpp::Category::getRoot(); 
// 获取指定名称的日志器
log4cpp::Category &file_logger = log4cpp::Category::getInstance("file_logger");

int main() {
    // 日志输出地
    log4cpp::Appender *coutAppender = new log4cpp::OstreamAppender("cout", &std::cout);
    log4cpp::FileAppender *fileAppender = new log4cpp::FileAppender("file", "./log.txt");

    // 日志格式器
    log4cpp::PatternLayout *coutPattern = new log4cpp::PatternLayout();
    // 格式：[年:月:日 时:分:秒:毫秒] 日志级别 日志内容 换行符
    coutPattern->setConversionPattern("[%d{%Y-%m-%d %H:%M:%S:%l}] %p %m%n");

    log4cpp::PatternLayout *filePattern = new log4cpp::PatternLayout();
    // 格式：[年:月:日 时:分:秒:毫秒] UTC秒数 日志器名称 日志级别 日志内容 换行符
    filePattern->setConversionPattern("[%d{%Y-%m-%d %H:%M:%S:%l}] %R %c %p %m%n");

    // 绑定日志器和appender，设置日志器的输出级别
    coutAppender->setLayout(coutPattern);
    root_logger.setAppender(coutAppender);
    root_logger.setPriority(log4cpp::Priority::INFO);

    fileAppender->setLayout(filePattern);
    file_logger.setAppender(fileAppender);
    file_logger.setPriority(log4cpp::Priority::ERROR);

    // 支持c风格的日志打印和流式的日志打印
    root_logger.debug("debug msg");
    root_logger.debugStream() << "debug msg by stream";
    root_logger.info("info msg");
    root_logger.infoStream() << "info msg by stream";
    root_logger.error("error msg");
    root_logger.errorStream() << "err msg by stream";

    file_logger.debug("file debug msg");
    file_logger.debugStream() << "file debug msg by stream";
    file_logger.info("file info msg");
    file_logger.infoStream() << "file info msg by stream";
    file_logger.error("file error msg");
    file_logger.errorStream() << "file err msg by stream";

    return 0;
}