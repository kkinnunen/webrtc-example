# webrtc-example

An example of what would be nice WebRTC integration with gn.
For Windows only, just for demonstration purposes.

git clone https://github.com/kkinnunen/webrtc-example.git
cd webrtc-example
python tools_webrtc_example\bootstrap.py
gclient sync
gn gen out\debug
ninja -C out\debug 

out\debug\video_server --run=server

out\debug\video_server --run=client

