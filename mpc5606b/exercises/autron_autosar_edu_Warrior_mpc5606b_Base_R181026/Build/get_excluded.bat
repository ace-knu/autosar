@echo off
pushd %0\..\..
setlocal
set PYTHON_HOME="D:\ts_mirr\Python\Portable Python 2.7.5.1\App"
set PATH=%PYTHON_HOME%
%PYTHON_HOME%\python .\Build\site_scons\cdt\get_excluded.py Debug 
endlocal
popd
::pause