/*
 *  Copyright 2012 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef VIDEO_SERVICE_FLAG_DEFS_H_
#define VIDEO_SERVICE_FLAG_DEFS_H_

#include "third_party/webrtc/rtc_base/flags.h"

extern const uint16_t kDefaultServerPort;  // From defaults.[h|cc]

// Define flags for the peerconnect_client testing tool, in a separate
// header file so that they can be shared across the different main.cc's
// for each platform.

WEBRTC_DEFINE_bool(help, false, "Prints this message");

WEBRTC_DEFINE_string(
    run,
    "",
    "Run either client or server");

WEBRTC_DEFINE_string(
    force_fieldtrials,
    "",
    "Field trials control experimental features. This flag specifies the field "
    "trials in effect. E.g. running with "
    "--force_fieldtrials=WebRTC-FooFeature/Enabled/ "
    "will assign the group Enabled to field trial WebRTC-FooFeature. Multiple "
    "trials are separated by \"/\"");

WEBRTC_DEFINE_bool(autoconnect,
                   false,
                   "Client: Connect to the server without user "
                   "intervention.");
WEBRTC_DEFINE_string(server, "localhost", "The server to connect to.");
WEBRTC_DEFINE_int(port,
                  kDefaultServerPort,
                  "Client: The port on which the server is listening.");
WEBRTC_DEFINE_bool(
    autocall,
    false,
    "Client: Call the first available other client on "
    "the server without user intervention.  Note: this flag should only be set "
    "to true on one of the two clients.");


#endif  // VIDEO_SERVICE_CLIENT_FLAG_DEFS_H_
