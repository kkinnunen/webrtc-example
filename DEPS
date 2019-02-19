# Copyright (c) 2019 NVIDIA Corporation.  All rights reserved.
# Chromium 19ce3be72c503b4360fe7e7f2cc0ec02645c1b2d defines the WebRTC revision
# f13c2cd9ee41f4ca572232a4e397b05449474632. WebRTC revision
# f13c2cd9ee41f4ca572232a4e397b05449474632 defines the revisions in this file.

vars = {
  'boringssl_git': 'https://boringssl.googlesource.com',
  'chromium_git': 'https://chromium.googlesource.com',
  'webrtc_git': 'https://webrtc.googlesource.com',
  'boringssl_revision': '70fe6105565e71e44e0a2a4ee617a26fd8fdcd96',
  "clang_format_revision": "96636aa0e9f047f17447f2d45a094d0b59ed7917",
}

deps = {
  'build':
    Var('chromium_git') + '/chromium/src/build' + '@' + 'c7f76dd3856737d853e3ec5f31619c437207eaee',
  'buildtools':
    Var('chromium_git') + '/chromium/src/buildtools' + '@' + '106e9fce3799633f42b45ca8bbe9e84e1e235603',
  'buildtools/clang_format/script':
    Var('chromium_git') + '/chromium/llvm-project/cfe/tools/clang-format.git@' +
    Var('clang_format_revision'),
  'tools':
    Var('chromium_git') + '/chromium/src/tools' + '@' + 'a21b4c33be351ecd172d361a0d042f2ace3d86f1',
  'testing':
    Var('chromium_git') + '/chromium/src/testing' + '@' + '2c5dd7a4c561600ce73b16668ad58c4f89bf43ed',
  'third_party':
    Var('chromium_git') + '/chromium/src/third_party' + '@' + '03a9db4381782ecfd7b5f74ae95dd0e40edb6d75',
  'base':
    Var('chromium_git') + '/chromium/src/base' + '@' + 'a9b919bb6e89788b1574d7c6e03ff66bb449246b',
  'third_party/boringssl/src':
    Var('boringssl_git') + '/boringssl.git' + '@' +  Var('boringssl_revision'),
  'third_party/googletest/src':
    Var('chromium_git') + '/external/github.com/google/googletest.git' + '@' + '5ec7f0c4a113e2f18ac2c6cc7df51ad6afc24081',
  'third_party/icu': {
    'url': Var('chromium_git') + '/chromium/deps/icu.git' + '@' + '07e7295d964399ee7bee16a3ac7ca5a053b2cf0a',
  },
  'third_party/jsoncpp/source':
    Var('chromium_git') + '/external/github.com/open-source-parsers/jsoncpp.git' + '@' + 'f572e8e42e22cfcf5ab0aea26574f408943edfa4', # from svn 248
  'third_party/libjpeg_turbo':
    Var('chromium_git') + '/chromium/deps/libjpeg_turbo.git' + '@' + '61a2bbaa9aec89cb2c882d87ace6aba9aee49bb9',
  'third_party/libsrtp':
    Var('chromium_git') + '/chromium/deps/libsrtp.git' + '@' + '650611720ecc23e0e6b32b0e3100f8b4df91696c',
  'third_party/libvpx/source/libvpx':
    Var('chromium_git') + '/webm/libvpx.git' + '@' +  'ce4336c2ab60d185b431345987b2188511760e54',
  'third_party/libyuv':
    Var('chromium_git') + '/libyuv/libyuv.git' + '@' + 'b36c86fdfe746d7be904c3a565b047b24d58087e',
  'third_party/nasm': {
      'url': Var('chromium_git') + '/chromium/deps/nasm.git' + '@' +
      '4ee6a69ce33be1e96fd3c44a6e3ae3d8177453da'
  },
  'third_party/openh264/src':
    Var('chromium_git') + '/external/github.com/cisco/openh264' + '@' + '6f26bce0b1c4e8ce0e13332f7c0083788def5fdf',
  'third_party/usrsctp/usrsctplib':
    Var('chromium_git') + '/external/github.com/sctplab/usrsctp' + '@' + '7a8bc9a90ca96634aa56ee712856d97f27d903f8',
  'third_party/winsdk_samples': {
    'url': Var('webrtc_git') + '/deps/third_party/winsdk_samples_v71' + '@' + 'a59391ef795986633735a1695caa97622a9bfd56',
    'condition': 'checkout_win',
  },
  'third_party/yasm/binaries': {
    'url': Var('chromium_git') + '/chromium/deps/yasm/binaries.git' + '@' + '52f9b3f4b0aa06da24ef8b123058bb61ee468881',
    'condition': 'checkout_win',
  },
  'third_party/yasm/source/patched-yasm':
    Var('chromium_git') + '/chromium/deps/yasm/patched-yasm.git' + '@' + '720b70524a4424b15fc57e82263568c8ba0496ad',
  'third_party/webrtc':
    Var('webrtc_git') + '/src.git' + '@' + 'f13c2cd9ee41f4ca572232a4e397b05449474632',
}

hooks = [
  {
    'name': 'win_toolchain',
    'pattern': '.',
    'condition': 'checkout_win',
    'action': ['python', 'build/vs_toolchain.py', 'update', '--force'],
  },
  {
    # Note: On Win, this should run after win_toolchain, as it may use it.
    'name': 'clang',
    'pattern': '.',
    'action': ['python', 'tools/clang/scripts/update.py', '--with-android={checkout_android}'],
  },
  {
    # Update LASTCHANGE.
    'name': 'lastchange',
    'pattern': '.',
    'action': ['python', 'build/util/lastchange.py',
               '-o', 'build/util/LASTCHANGE'],
  },
  {
    'name': 'gn_win',
    'pattern': '.',
    'condition': 'host_os == "win"',
    'action': [ 'download_from_google_storage',
                '--no_resume',
                '--no_auth',
                '--bucket', 'chromium-gn',
                '-s', 'buildtools/win/gn.exe.sha1',
    ],
  },
  {
    'name': 'clang_format_win',
    'pattern': '.',
    'condition': 'host_os == "win"',
    'action': [ 'download_from_google_storage',
                '--no_resume',
                '--no_auth',
                '--bucket', 'chromium-clang-format',
                '-s', 'buildtools/win/clang-format.exe.sha1',
    ],
  },
  {
    'name': 'rc_win',
    'pattern': '.',
    'condition': 'checkout_win and host_os == "win"',
    'action': [ 'download_from_google_storage',
                '--no_resume',
                '--no_auth',
                '--bucket', 'chromium-browser-clang/rc',
                '-s', 'build/toolchain/win/rc/win/rc.exe.sha1',
    ],
  },
]

