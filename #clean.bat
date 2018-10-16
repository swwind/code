@echo off
for /r %%s in (*.exe,*.out,*.o,*.in,*.class,*.log,*.ans) do (
	erase "%%s"
	echo Deleted %%s.
)
pause