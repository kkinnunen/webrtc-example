# webrtc-example

An example of what would be nice WebRTC integration with gn.
For Windows only, just for demonstration purposes.

```
git clone https://github.com/kkinnunen/webrtc-example.git
cd webrtc-example
python tools_webrtc_example\bootstrap.py
gclient sync

# patch //third_party/webrtc with url below

gn gen out\debug
ninja -C out\debug 

# In one terminal:
out\debug\video_server --run=server

# In other terminal:
out\debug\video_server --run=client

```

//third_party/webrtc needs https://webrtc-review.googlesource.com/c/src/+/123197 for the above to compile.
