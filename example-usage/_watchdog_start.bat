@rem this example demonstrates using Watchdog with Pure Data patch

:1

start pd_start.bat

@rem first argument is OSC port, the seconds - time for wait seconds
"../bin/Watchdog.exe" 12370 10

@rem when we are here, it means Watchdog was exited
@rem errorlevel 1 means Watchdog receives /exit, so not need to restart
if %errorlevel% EQU 0 (
	@rem we killing pd and restart again

    echo Restarting...    
    taskkill /im pd.com /f
    taskkill /im pd.exe /f

    timeout 2
    goto 1
)

