@echo off

set EXCUTABLE=%0%
echo [Rte] Getting path for code generation...
set RTE_EXECUTABLE=%EXCUTABLE:Rte.bat=Rte.exe%
set INDENT_EXECUTABLE=%EXCUTABLE:Rte.bat=gc.exe%

echo [Rte] RTE_EXECUTABLE = %RTE_EXECUTABLE%
if not exist %RTE_EXECUTABLE% (
	echo [Rte] Cannot find Rte_Executable... Finish
	goto finish
)

echo.
echo [Rte] Execute Code-Generation...
%RTE_EXECUTABLE% %*

echo.
echo [Rte] Getting path for auto indentation...

:find_output_directory

if "%0"=="" (
	set OUTPUT_DIR=%EXCUTABLE:Rte.bat=Rte_Output%
	goto indent_output_directory
)
if "%0"=="-o" (
	set OUTPUT_DIR=%1%
	goto indent_output_directory
)
if "%0"=="-O" (
	set OUTPUT_DIR=%1%
	goto indent_output_directory
)
shift
goto find_output_directory

:indent_output_directory

echo [Rte] INDENT_EXECUTABLE = %INDENT_EXECUTABLE%
if not exist %INDENT_EXECUTABLE% (
	echo [Rte] Cannot find Indent_Executable... Skip
	goto finish
)

echo [Rte] OUTPUT_DIR = %OUTPUT_DIR%
if not exist %OUTPUT_DIR% (
	echo [Rte] Cannot find Output_Directory... Skip
	goto finish
)

echo.
echo [Rte] Execute Auto-Indentation...

for /f %%f in ('dir /b /s %OUTPUT_DIR%\rte*.c %OUTPUT_DIR%\schm*.c 2^> nul') do (
	echo %%f
	%INDENT_EXECUTABLE% -no-cmt_doxygen- -no-cmt_add_file- -no-cmt_add_gc_tag- -no-cmt_add_fct_def- -no-cmt_add_fct_def_class- -no-cmt_add_class_access- -file-%%f > nul
)

:finish