#!/bin/bash
set -eu -o pipefail

sudo -n true

if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

echo "Start installing dependencies"

bin_dir="bin/"

[ ! -d "$bin_dir" ] && mkdir -p "$bin_dir"

apt update
apt upgrade

while read -r p ; do sudo apt-get install -y $p ; done < <(cat << "EOF"
    qt5-default 
    qtcreator 
    qttools5-dev
    libqt5webkit5-dev 
    libqt5webenginewidgets5
    qtbase5-examples 
    qtbase5-doc-html 
    qtquickcontrols2-5-examples 
    qt5-doc 
    qt5-doc-html 
    qml-module-qtquick-controls2
    qt5serialport-examples 
    qtserialport5-doc-html
    qtbase5-examples 
    qtdeclarative5-examples
    bison build-essential 
    gperf 
    flex 
    python2 
    libasound2-dev  
    libdrm-dev 
    libegl1-mesa-dev 
    libnss3-dev 
    libpci-dev 
    libpulse-dev 
    libudev-dev 
    nodejs 
    gyp 
    ninja-build
    libssl-dev 
    libxcursor-dev 
    libxcomposite-dev
    libxdamage-dev 
    libxrandr-dev 
    libfontconfig1-dev 
    libxss-dev 
    libwebp-dev 
    libjsoncpp-dev 
    libopus-dev 
    libminizip-dev 
    libavutil-dev 
    libavformat-dev 
    libavcodec-dev 
    libevent-dev 
    libvpx-dev 
    libsnappy-dev 
    libre2-dev 
    libprotobuf-dev 
    protobuf-compiler
    qtwebengine5-dev
    qml-module-qtwebengine 
    libqt5webengine5 
    libqt5webenginecore5 
    libqt5webengine-data  
    libqt5webenginewidgets5 
    qml-module-qtwebengine 
    qtwebengine5-dev 
    qtwebengine5-dev-tools 
    qtwebengine5-doc 
    qtwebengine5-doc-html 
    qtwebengine5-examples  
    qtwebengine5-private-dev
    qtmultimedia5-dev 
    libqt5multimediawidgets5 
    libqt5multimedia5-plugins 
    libqt5multimedia5
    libqt5charts5-dev
    qtdeclarative5-dev
    qtbase5-examples 
    qtbase5-doc-html
    qtquickcontrols2-5-examples
    qt5-doc 
    qt5-doc-html
    cmake-qt-gui 
    qt5-default 
    qt5-doc 
    qt5-doc-html 
    qtbase5-dev 
    qtbase5-doc-html 
    qtbase5-examples 
    qtcreator 
    qtquickcontrols2-5-examples
    qml-module-qtquick-controls2
    libqt5multimedia5-plugins 
    qml-module-qtmultimedia
    qt5-image-formats-plugins
EOF
)

sudo snap install webengine513
