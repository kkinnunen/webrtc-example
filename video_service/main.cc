// Copyright (c) 2019 NVIDIA Corporation.  All rights reserved.

#include "video_service/flag_defs.h"
#include "video_service/client/main_client.h"
#include "video_service/server/main_server.h"

int main(int argc, char* argv[]) {
  int rv = rtc::FlagList::SetFlagsFromCommandLine(&argc, argv, true);
  if (FLAG_help) {
    rtc::FlagList::Print(NULL, false);
    return rv == 0 ? 0 : -1;
  }

  // Abort if the user specifies a port that is outside the allowed
  // range [1, 65535].
  if ((FLAG_port < 1) || (FLAG_port > 65535)) {
    printf("Error: %i is not a valid port.\n", FLAG_port);
    return -1;
  }
  if (FLAG_run == std::string("client")) {
    return MainClient();
  } else if (FLAG_run == std::string("server")) {
    return MainServer();
  }
  printf("Error: invalid --run argument '%s'. Should be client or server.", FLAG_run);
  return -1;
}
