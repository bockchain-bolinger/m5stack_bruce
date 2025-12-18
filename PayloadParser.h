#ifndef PAYLOAD_PARSER_H
#define PAYLOAD_PARSER_H

#include <Arduino.h>

class PayloadParser {
public:
    PayloadParser();
    String parseLine(String payload);
    bool hasMoreCommands(String payload);
    void reset();
    String extractDelay(String command);
    String extractString(String command);
    
private:
    int _currentIndex;
};

#endif
