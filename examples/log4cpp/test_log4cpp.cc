#include <iostream>
#include <log4cpp/Appender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>

int main() {
    log4cpp::Category &root = log4cpp::Category::getRoot();
    log4cpp::Appender *appender =
        new log4cpp::OstreamAppender("default", &std::cout);
    log4cpp::PatternLayout *layout = new log4cpp::PatternLayout();
    layout->setConversionPattern("[%d{%Y-%m-%d %H:%M:%S:%l} %p %m%n");
    appender->setLayout(layout);
    root.addAppender(appender);
    root.setPriority(log4cpp::Priority::DEBUG);

    std::cout << log4cpp::Priority::getPriorityName(root.getPriority())
              << std::endl;
    root.errorStream() << "" << __func__ << ":" << __LINE__ << "]"
                       << " error";
    root.error("error");
    root.info("info");
    root.notice("notice");
    root.debug("debug");
    return 0;
}