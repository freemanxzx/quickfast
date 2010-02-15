// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
//

#include <Examples/ExamplesPch.h>
#include <InterpretApplication/InterpretApplication.h>

#if 10
#include <Communication/TCPReceiver.h>
#include <Codecs/BlockedStreamQueueService.h>
#include <Messages/SingleValueBuilder.h>
#endif

using namespace QuickFAST;
using namespace Examples;

int main(int argc, char* argv[])
{
  int result = -1;
#if 10
  if(argc <= 1)
  {
    // this is here to test TCPReceiver
    // it doeesn't belong here.  I just needed a place to put it temporarily.
    Communication::TCPReceiver receiver("localhost", "1000");
    Codecs::TemplateRegistryPtr templateRegistry;
    Messages::SingleValueBuilder<int> builder;
    Codecs::BlockedStreamQueueService queueService(templateRegistry, builder);
    receiver.start(queueService);

    return 0;
  }
#endif
  InterpretApplication application;
  if(application.init(argc, argv))
  {
    result = application.run();
    application.fini();
  }
  return result;
}