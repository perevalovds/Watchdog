@rem this example demonstrates watch-dogging pd patch

:1

start pd_start.bat

cd .. 
@rem first argument is OSC port, the seconds - time for wait seconds
Watchdog.exe 13470 10
cd pd-example

@rem when we are here, it means Watchdog was exited
@rem errorlevel 1 means Watchdog receives /exit, so not need to restart
if errorlevel 0 (
    echo Restarting...
    @rem we killing pd and restart again
    taskkill /im pd.com /f
    taskkill /im pd.exe /f

    timeout 2

    goto 1
)

