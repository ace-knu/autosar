@echo off
pushd %0\..\..
setlocal
set PYTHON_HOME=D:\ts_mirr\python\Portable_Python_2.7.6.1\App
set SCONS_HOME=D:\ts_mirr\scons\scons-local-2.3.4
set PATH=%PATH%;%PYTHON_HOME%;%SCONS_HOME%
%PYTHON_HOME%\python Build\site_scons\Build.py %*
endlocal
popd
exit /B %ERRORLEVEL%
::pause