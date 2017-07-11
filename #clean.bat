@echo off
for /r %%s in (*.exe,*.out,*.o,*.in) do (
	erase %%s
)