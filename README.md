unix\_signals\_handeling_example
==============================

Unix signals handeling example as part of system programming classes

###What does it do?
Ignores SIGQUIT and launch a function when SIGTERM is received. When processing SIGTERM, SIGUSR1 is blocked.


###How to compile?
go to the folder and run "make"

### How to test?
launch "unix\_signals\_handeling_example.run"

send SIGTERM with:

killall -TERM unix\_signals\_handeling_example.run

I let you guess how to send SIGQUIT or SIGUSR1 ;-)
