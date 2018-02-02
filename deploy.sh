#!/bin/bash


qt_bin_path="/Users/Shared/Qt5.7.0/5.7/clang_64/bin"
pak_path="./OutDir/Package"
app_path="./OutDir/Package/TestApp.app"
explorer_path="./OutDir/Package/SubApp.app"

is_increase_version=false

if [ -d "${pak_path}" ]; then
    rm -rf ${pak_path}
fi

mkdir ${pak_path}


echo "\r\npack start!\r\n"

cp -XRf ./OutDir/Release/* ${pak_path}

if [ -d "${explorer_path}" ]; then
    cp -XRf ${explorer_path}/Contents/MacOS/SubApp ${app_path}/Contents/MacOS/
fi

install_name_tool -change "libDynLib.1.dylib" $(pwd)/OutDir/Package/"libDynLib.1.dylib" ${app_path}/Contents/MacOS/TestApp

#install_name_tool -change "@rpath/QtAV.framework/Versions/1/QtAV" "@executable_path/../Frameworks/QtAV.framework/Versions/1/QtAV" ${app_path}/Contents/MacOS/TestApp
#install_name_tool -change "@rpath/QtAVWidgets.framework/Versions/1/QtAVWidgets" "@executable_path/../Frameworks/QtAVWidgets.framework/Versions/1/QtAVWidgets" ${app_path}/Contents/MacOS/GoCom
${qt_bin_path}/macdeployqt ${app_path} -executable=${app_path}/Contents/MacOS/SubApp

hdiutil create -srcfolder ${app_path} ./TestApp.dmg

echo "pack completed!"





