@echo off
for /r %%s in (*.exe,*.out,*.o,*.in,*.class) do (
	erase "%%s"
	echo Deleted %%s.
)
pause