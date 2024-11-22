# create temp with zip extension (or Expand will complain)
$tmp = New-TemporaryFile | Rename-Item -NewName { $_ -replace 'tmp$', 'zip' } –PassThru
# download
Invoke-WebRequest -OutFile $tmp https://github.com/podofo/podofo/archive/refs/tags/0.10.4.zip
# extract to same folder
$tmp | Expand-Archive -DestinationPath podofo -Force
# remove temporary file
$tmp | Remove-Item
cd podofo/podofo*
vcpkg install pkgconf fontconfig freetype libxml2 openssl libjpeg-turbo libpng tiff zlib
mkdir build
cd build
# cmake -DCMAKE_TOOLCHAIN_FILE=C:\vcpkg\scripts\buildsystems\vcpkg.cmake -DPODOFO_BUILD_STATIC=TRUE ..
cmake -DCMAKE_TOOLCHAIN_FILE=C:\vcpkg\scripts\buildsystems\vcpkg.cmake ..
cmake --build . --config Release
cmake --install .
