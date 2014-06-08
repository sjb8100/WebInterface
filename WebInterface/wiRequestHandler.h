﻿// created by i-saint
// distributed under Creative Commons Attribution (CC BY) license.
// https://github.com/i-saint/WebInterface

#ifndef wiRequestHandler_h
#define wiRequestHandler_h
#include "wiEvent.h"


class wiRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    enum ReturnCode {
        RC_Ok = 0,
        RC_InvalidCommand = -1,
        RC_InvalicParam = -2,
    };
    typedef std::function<void (wiRequestHandler*, HTTPServerRequest&, HTTPServerResponse&)> Handler;
    typedef std::map<std::string, Handler> HandlerTable;
    static HandlerTable&    getHandlerTable();
    static Handler*         findHandler(const std::string &path);

public:
    wiRequestHandler();
    void handleRequest(HTTPServerRequest &request, HTTPServerResponse &response);
    void respondCode(HTTPServerResponse &response, int32 code);

private:
    void handleSelect(HTTPServerRequest &request, HTTPServerResponse &response);
    void handleDisselect(HTTPServerRequest &request, HTTPServerResponse &response);
    void handleAction(HTTPServerRequest &request, HTTPServerResponse &response);

    void handleState(HTTPServerRequest &request, HTTPServerResponse &response);
    void handleConst(HTTPServerRequest &request, HTTPServerResponse &response);
};


#endif // wiRequestHandler_h