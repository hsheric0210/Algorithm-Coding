@ECHO OFF
REM Obfuscates the specified file
py.exe cminify.py %~1 >%~1.min_tmp

del %~1 >%~1.min_tmp